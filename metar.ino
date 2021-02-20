#define OE 5
#define SER 4
#define RCLK 3
#define SRCLK 2

#define WINDOW_LEN 30
#define LED_COUNT 5

unsigned int timer = 0;

class RgbLed {
  unsigned int state_;

  int red_threshold_;
  int green_threshold_;
  int blue_threshold_;

public:
  RgbLed() : state_(0) {}

  void set_color(float red_pct, float green_pct, float blue_pct, float intensity) {
    red_threshold_ = WINDOW_LEN * red_pct * intensity;
    green_threshold_ = WINDOW_LEN * green_pct * intensity;
    blue_threshold_ = WINDOW_LEN * blue_pct * intensity;
  }

  void set_color_off() {
    set_color(0.0, 0.0, 0.0, 0.0);
  }

  void on() {
    state_ = 0b111;
  }

  bool maybe_toggle(unsigned int timer) {
    bool toggled = false;

    if (timer > red_threshold_) {
      state_ &= 0b110;
      toggled = true;
    }

    if (timer > green_threshold_) {
      state_ &= 0b101;
      toggled = true;
    }

    if (timer > blue_threshold_) {
      state_ &= 0b011;
      toggled = true;
    }

    return toggled;
  }

  unsigned int state() {
    return state_;
  }
};

RgbLed leds[LED_COUNT];

void setup() {
  // Set the CTC mode
  TCCR0A = 1 << WGM01;

  /*
  // Value for ORC0A for 100us
  OCR0A = 0x18;
  */
  OCR0A = 0x63;

  // Set the interrupt request
  TIMSK0 |= 1 << OCIE0A;

  // Enable interrupt
  sei();

  /*
  // Set prescale to 1/64 of 16MHz (250kHz)
  TCCR0B |= 1 << CS01;
  TCCR0B |= 1 << CS00;
  */

  // Set prescale to 1/8 of 8MHz (250kHz)
  TCCR0B |= (0 << CS02) | (1 << CS01) | (0 << CS00);

  pinMode(OE, OUTPUT);
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);

  for (auto& led : leds) {
    led.set_color_off();
  }

  Serial.begin(9600);
}

void shift_out_state(int state, int register_count) {
  digitalWrite(OE, HIGH);

  for (int i = register_count * 8 - 1; i >= 0; i--) {
    if ((state >> i) & 1) {
      digitalWrite(SER, HIGH);
    } else {
      digitalWrite(SER, LOW);
    }

    digitalWrite(SRCLK, HIGH);
    digitalWrite(SRCLK, LOW);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
  }

  digitalWrite(OE, LOW);
}

void set_color(RgbLed &led, char color) {
  switch (color) {
    case 'r':
      led.set_color(1.0, 0.0, 0.0, 0.5);
      break;
    case 'g':
      led.set_color(0.0, 1.0, 0.0, 0.5);
      break;
    case 'b':
      led.set_color(0.0, 0.0, 1.0, 0.5);
      break;
    case 'p':
      led.set_color(1.0, 0.0, 1.0, 0.5);
      break;
    case 'o':
      led.set_color(0.0, 0.0, 0.0, 0.0);
      break;
  }
}

char led = 0;

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    if (led == 0) {
      led = input;
    } else {
      char color = input;

      if (led <= '5' && led >= '1') {
        set_color(leds[led - '1'], color);
      }

      led = 0;
    }
  }
}

// Interrupt once every 100us
ISR(TIMER0_COMPA_vect) {
  timer++;

  if (timer > WINDOW_LEN) {
    timer = 0;
  }

  if (timer == 0) {
    for (auto& led : leds) {
      led.on();
    }
  } else {
    bool toggled = false;
    for (auto& led : leds) {
      if (led.maybe_toggle(timer)) {
        toggled = true;
      }
    }

    if (toggled) {
      unsigned int state = 0;
      for (int i = 0; i < LED_COUNT; i++) {
        state |= leds[i].state() << (i * 3);
      }

      shift_out_state(state, 2);

      toggled = false;
    }
  }
}
