EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L promicro:ProMicro U1
U 1 1 6033E599
P 2500 3500
F 0 "U1" H 2500 4537 60  0000 C CNN
F 1 "ProMicro" H 2500 4431 60  0000 C CNN
F 2 "ProMicro:ProMicro" H 2600 2450 60  0001 C CNN
F 3 "" H 2600 2450 60  0000 C CNN
	1    2500 3500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U2
U 1 1 6033F1E9
P 5200 2600
F 0 "U2" H 5200 3381 50  0000 C CNN
F 1 "74HC595" H 5200 3290 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 5200 2600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5200 2600 50  0001 C CNN
	1    5200 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 3150 1700 3150
Wire Wire Line
	1700 3150 1700 2400
Wire Wire Line
	1700 2400 4500 2400
Wire Wire Line
	1800 3250 1600 3250
Wire Wire Line
	1600 3250 1600 2300
Wire Wire Line
	1600 2300 4700 2300
Wire Wire Line
	4700 2300 4700 2700
Wire Wire Line
	4700 2700 4800 2700
Wire Wire Line
	1800 3350 1500 3350
Wire Wire Line
	1500 3350 1500 2200
Wire Wire Line
	1500 2200 4800 2200
Wire Wire Line
	1800 3450 1400 3450
Wire Wire Line
	1400 3450 1400 2100
Wire Wire Line
	1400 2100 4600 2100
Wire Wire Line
	4600 2100 4600 2800
Wire Wire Line
	4600 2800 4800 2800
Wire Wire Line
	4600 2800 4600 4600
Wire Wire Line
	4600 4600 4800 4600
Connection ~ 4600 2800
Wire Wire Line
	4700 2700 4700 4500
Wire Wire Line
	4700 4500 4800 4500
Connection ~ 4700 2700
Wire Wire Line
	4500 2400 4500 4200
Wire Wire Line
	4500 4200 4800 4200
Connection ~ 4500 2400
Wire Wire Line
	4500 2400 4800 2400
Wire Wire Line
	5600 3100 5750 3100
Wire Wire Line
	5750 3100 5750 3500
Wire Wire Line
	5750 3500 4800 3500
Wire Wire Line
	4800 3500 4800 4000
Wire Wire Line
	5200 3300 4400 3300
Wire Wire Line
	4400 3300 4400 5100
Wire Wire Line
	4400 5100 5200 5100
Wire Wire Line
	4400 3300 4400 2850
Wire Wire Line
	4400 2850 3200 2850
Connection ~ 4400 3300
Wire Wire Line
	3200 2750 4300 2750
Wire Wire Line
	4300 2750 4300 2000
Wire Wire Line
	4300 2000 5200 2000
Wire Wire Line
	4300 2750 4300 3800
Wire Wire Line
	4300 3800 5200 3800
Connection ~ 4300 2750
Wire Wire Line
	4400 5750 4400 5100
Connection ~ 4400 5100
$Comp
L 74xx:74HC595 U3
U 1 1 6033F699
P 5200 4400
F 0 "U3" H 5200 5181 50  0000 C CNN
F 1 "74HC595" H 5200 5090 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 5200 4400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5200 4400 50  0001 C CNN
	1    5200 4400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
