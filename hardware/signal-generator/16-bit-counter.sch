EESchema Schematic File Version 4
LIBS:signal-generator-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
Title "Digital Function Generator v2 - DDS 16-bit counter"
Date "2019-11-24"
Rev "1"
Comp "Petar Nikolov"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 5450 5000
NoConn ~ 5450 5200
NoConn ~ 5450 5700
NoConn ~ 5450 5900
NoConn ~ 6050 5800
NoConn ~ 6050 5100
Text HLabel 8850 1550 2    50   Input ~ 0
Q0
Text HLabel 8850 1650 2    50   Input ~ 0
Q1
Text HLabel 8850 1750 2    50   Input ~ 0
Q2
Text HLabel 8850 1850 2    50   Input ~ 0
Q3
Text HLabel 8850 1950 2    50   Input ~ 0
Q4
Text HLabel 8850 2050 2    50   Input ~ 0
Q5
Text HLabel 8850 2150 2    50   Input ~ 0
Q6
Text HLabel 8850 2250 2    50   Input ~ 0
Q7
Text HLabel 8850 2350 2    50   Input ~ 0
Q8
Text HLabel 8850 2450 2    50   Input ~ 0
Q9
Text HLabel 8850 2550 2    50   Input ~ 0
Q10
Text HLabel 8850 2650 2    50   Input ~ 0
Q11
Wire Wire Line
	3650 5300 3850 5300
$Comp
L Device:C C?
U 1 1 5DBB7F3D
P 4000 4600
F 0 "C?" V 3748 4600 50  0000 C CNN
F 1 "100nF" V 3839 4600 50  0000 C CNN
F 2 "" H 4038 4450 50  0001 C CNN
F 3 "~" H 4000 4600 50  0001 C CNN
	1    4000 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 4700 4250 4600
Wire Wire Line
	4150 4600 4250 4600
Wire Wire Line
	3850 4600 3750 4600
Wire Wire Line
	3750 4600 3750 4700
$Comp
L power:GNDD #PWR?
U 1 1 5DBB9690
P 3750 4700
F 0 "#PWR?" H 3750 4450 50  0001 C CNN
F 1 "GNDD" H 3754 4545 50  0000 C CNN
F 2 "" H 3750 4700 50  0001 C CNN
F 3 "" H 3750 4700 50  0001 C CNN
	1    3750 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 4600 4250 4500
Connection ~ 4250 4600
$Comp
L power:+5VD #PWR?
U 1 1 5DBB9DC1
P 4250 4500
F 0 "#PWR?" H 4250 4350 50  0001 C CNN
F 1 "+5VD" H 4265 4673 50  0000 C CNN
F 2 "" H 4250 4500 50  0001 C CNN
F 3 "" H 4250 4500 50  0001 C CNN
	1    4250 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5DBBA88D
P 4000 1250
F 0 "C?" V 3748 1250 50  0000 C CNN
F 1 "100nF" V 3839 1250 50  0000 C CNN
F 2 "" H 4038 1100 50  0001 C CNN
F 3 "~" H 4000 1250 50  0001 C CNN
	1    4000 1250
	0    1    1    0   
$EndComp
Wire Wire Line
	4150 1250 4250 1250
Wire Wire Line
	4250 1250 4250 1350
Wire Wire Line
	3850 1250 3750 1250
Wire Wire Line
	3750 1250 3750 1350
$Comp
L power:GNDD #PWR?
U 1 1 5DBBB94E
P 3750 1350
F 0 "#PWR?" H 3750 1100 50  0001 C CNN
F 1 "GNDD" H 3754 1195 50  0000 C CNN
F 2 "" H 3750 1350 50  0001 C CNN
F 3 "" H 3750 1350 50  0001 C CNN
	1    3750 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 1250 4250 1150
Connection ~ 4250 1250
$Comp
L power:+5VD #PWR?
U 1 1 5DBBC2D6
P 4250 1150
F 0 "#PWR?" H 4250 1000 50  0001 C CNN
F 1 "+5VD" H 4265 1323 50  0000 C CNN
F 2 "" H 4250 1150 50  0001 C CNN
F 3 "" H 4250 1150 50  0001 C CNN
	1    4250 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2850 4250 2950
$Comp
L power:GNDD #PWR?
U 1 1 5DBBD1F3
P 4250 2950
F 0 "#PWR?" H 4250 2700 50  0001 C CNN
F 1 "GNDD" H 4254 2795 50  0000 C CNN
F 2 "" H 4250 2950 50  0001 C CNN
F 3 "" H 4250 2950 50  0001 C CNN
	1    4250 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 6200 4250 6300
$Comp
L power:GNDD #PWR?
U 1 1 5DBBE1A2
P 4250 6300
F 0 "#PWR?" H 4250 6050 50  0001 C CNN
F 1 "GNDD" H 4254 6145 50  0000 C CNN
F 2 "" H 4250 6300 50  0001 C CNN
F 3 "" H 4250 6300 50  0001 C CNN
	1    4250 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3650 5050 3850
Wire Wire Line
	5450 3650 5450 3850
Wire Wire Line
	5850 3850 5850 3650
Wire Wire Line
	6250 3650 6250 3850
Wire Wire Line
	6650 3850 6650 3650
Wire Wire Line
	7050 3850 7050 3650
Entry Wire Line
	7050 3850 7150 3950
Entry Wire Line
	6650 3850 6750 3950
Entry Wire Line
	6250 3850 6350 3950
Entry Wire Line
	5850 3850 5950 3950
Entry Wire Line
	5450 3850 5550 3950
Entry Wire Line
	5050 3850 5150 3950
Wire Wire Line
	3850 2250 3750 2250
Text HLabel 3750 2250 0    50   Input ~ 0
MR1
Entry Wire Line
	3450 3850 3550 3950
Text HLabel 3350 1950 0    50   Input ~ 0
~CP
Wire Wire Line
	3050 4900 2950 4900
Wire Wire Line
	2950 4900 2950 4800
$Comp
L power:+5VD #PWR?
U 1 1 5DBCA96D
P 2950 4800
F 0 "#PWR?" H 2950 4650 50  0001 C CNN
F 1 "+5VD" H 2965 4973 50  0000 C CNN
F 2 "" H 2950 4800 50  0001 C CNN
F 3 "" H 2950 4800 50  0001 C CNN
	1    2950 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 5000 2750 5000
Wire Wire Line
	3050 5100 2750 5100
Wire Wire Line
	3050 5200 2750 5200
Wire Wire Line
	3050 5300 2750 5300
Wire Wire Line
	3050 5400 2750 5400
Wire Wire Line
	3050 5500 2750 5500
Wire Wire Line
	3050 5600 2750 5600
Entry Wire Line
	2650 4900 2750 5000
Entry Wire Line
	2650 5000 2750 5100
Entry Wire Line
	2650 5100 2750 5200
Entry Wire Line
	2650 5200 2750 5300
Entry Wire Line
	2650 5300 2750 5400
Entry Wire Line
	2650 5400 2750 5500
Entry Wire Line
	2650 5500 2750 5600
Text HLabel 8850 2750 2    50   Input ~ 0
Q12
Text HLabel 8850 2850 2    50   Input ~ 0
Q13
Text HLabel 8850 2950 2    50   Input ~ 0
Q14
Text HLabel 8850 3050 2    50   Input ~ 0
Q15
NoConn ~ 4650 5300
NoConn ~ 4650 5400
NoConn ~ 4650 5500
NoConn ~ 4650 5600
NoConn ~ 4650 5700
NoConn ~ 4650 5800
NoConn ~ 4650 5900
NoConn ~ 4650 6000
Wire Wire Line
	3350 1950 3450 1950
Wire Wire Line
	3850 5600 3750 5600
Text HLabel 3750 5600 0    50   Input ~ 0
MR2
Text Label 2750 5600 0    50   ~ 0
CP2I0
Text Label 2750 5500 0    50   ~ 0
CP2I1
Text Label 2750 5400 0    50   ~ 0
CP2I2
Text Label 2750 5300 0    50   ~ 0
CP2I3
Text Label 2750 5200 0    50   ~ 0
CP2I4
Text Label 2750 5100 0    50   ~ 0
CP2I5
Text Label 2750 5000 0    50   ~ 0
CP2I6
Text Label 2650 3950 2    50   ~ 0
CP2I[0..6]
Text Label 7050 3750 0    50   ~ 0
CP2I0
Text Label 6650 3750 0    50   ~ 0
CP2I1
Text Label 6250 3750 0    50   ~ 0
CP2I2
Text Label 5850 3750 0    50   ~ 0
CP2I3
Text Label 5450 3750 0    50   ~ 0
CP2I4
Text Label 5050 3750 0    50   ~ 0
CP2I5
Text Label 3450 3750 0    50   ~ 0
CP2I6
Text Label 7150 3950 0    50   ~ 0
CP2I[0..6]
Wire Wire Line
	4650 1650 4750 1650
Wire Wire Line
	4650 1750 4750 1750
Wire Wire Line
	4650 1850 4750 1850
Wire Wire Line
	4650 1950 4750 1950
Wire Wire Line
	4650 2050 4750 2050
Wire Wire Line
	4650 2150 4750 2150
Wire Wire Line
	4650 2250 4750 2250
Wire Wire Line
	4650 2350 4750 2350
Wire Wire Line
	4650 2450 4750 2450
Wire Wire Line
	4650 2550 4750 2550
Wire Wire Line
	4650 2650 4750 2650
Wire Wire Line
	4650 1550 4750 1550
Entry Wire Line
	4750 1550 4850 1650
Entry Wire Line
	4750 1650 4850 1750
Entry Wire Line
	4750 1750 4850 1850
Entry Wire Line
	4750 1850 4850 1950
Entry Wire Line
	4750 1950 4850 2050
Entry Wire Line
	4750 2050 4850 2150
Entry Wire Line
	4750 2150 4850 2250
Entry Wire Line
	4750 2250 4850 2350
Entry Wire Line
	4750 2350 4850 2450
Entry Wire Line
	4750 2450 4850 2550
Entry Wire Line
	4750 2550 4850 2650
Entry Wire Line
	4750 2650 4850 2750
Entry Wire Line
	4850 2850 4950 2950
Entry Wire Line
	5050 2850 5150 2950
Entry Wire Line
	5250 2850 5350 2950
Entry Wire Line
	5450 2850 5550 2950
Entry Wire Line
	5650 2850 5750 2950
Entry Wire Line
	5850 2850 5950 2950
Entry Wire Line
	6050 2850 6150 2950
Entry Wire Line
	6250 2850 6350 2950
Entry Wire Line
	6450 2850 6550 2950
Entry Wire Line
	6650 2850 6750 2950
Entry Wire Line
	6850 2850 6950 2950
Entry Wire Line
	7050 2850 7150 2950
Wire Wire Line
	7150 2950 7150 3050
Wire Wire Line
	6950 2950 6950 3050
Wire Wire Line
	6750 2950 6750 3050
Wire Wire Line
	6550 2950 6550 3050
Wire Wire Line
	6350 2950 6350 3050
Wire Wire Line
	6150 2950 6150 3050
Wire Wire Line
	5950 2950 5950 3050
Wire Wire Line
	5750 2950 5750 3050
Wire Wire Line
	5550 2950 5550 3050
Wire Wire Line
	5350 2950 5350 3050
Wire Wire Line
	5150 2950 5150 3050
Wire Wire Line
	4950 2950 4950 3050
Text Label 4650 1550 0    50   ~ 0
Q0
Text Label 4650 1650 0    50   ~ 0
Q1
Text Label 4650 1750 0    50   ~ 0
Q2
Text Label 4650 1850 0    50   ~ 0
Q3
Text Label 4650 1950 0    50   ~ 0
Q4
Text Label 4650 2050 0    50   ~ 0
Q5
Text Label 4650 2150 0    50   ~ 0
Q6
Text Label 4650 2250 0    50   ~ 0
Q7
Text Label 4650 2350 0    50   ~ 0
Q8
Text Label 4650 2450 0    50   ~ 0
Q9
Text Label 4650 2550 0    50   ~ 0
Q10
Text Label 4650 2650 0    50   ~ 0
Q11
Text Label 4850 1650 0    50   ~ 0
Q[0..11]
Text Label 4950 3050 2    50   ~ 0
Q0
Text Label 5150 3050 2    50   ~ 0
Q1
Text Label 5350 3050 2    50   ~ 0
Q2
Text Label 5550 3050 2    50   ~ 0
Q3
Text Label 5750 3050 2    50   ~ 0
Q4
Text Label 5950 3050 2    50   ~ 0
Q5
Text Label 6150 3050 2    50   ~ 0
Q6
Text Label 6350 3050 2    50   ~ 0
Q7
Text Label 6550 3050 2    50   ~ 0
Q8
Text Label 6750 3050 2    50   ~ 0
Q9
Text Label 6950 3050 2    50   ~ 0
Q10
Text Label 7150 3050 2    50   ~ 0
Q11
Text Label 4650 4900 0    50   ~ 0
Q12
Text Label 4650 5000 0    50   ~ 0
Q13
Text Label 4650 5100 0    50   ~ 0
Q14
Text Label 4650 5200 0    50   ~ 0
Q15
Wire Wire Line
	8850 1550 8750 1550
Wire Wire Line
	8850 1650 8750 1650
Wire Wire Line
	8850 1750 8750 1750
Wire Wire Line
	8850 1850 8750 1850
Wire Wire Line
	8850 1950 8750 1950
Wire Wire Line
	8850 2050 8750 2050
Wire Wire Line
	8850 2150 8750 2150
Wire Wire Line
	8850 2250 8750 2250
Wire Wire Line
	8850 2350 8750 2350
Wire Wire Line
	8850 2450 8750 2450
Wire Wire Line
	8850 2550 8750 2550
Wire Wire Line
	8850 2650 8750 2650
Wire Wire Line
	8850 2750 8750 2750
Wire Wire Line
	8850 2850 8750 2850
Text Label 8750 1550 2    50   ~ 0
Q0
Text Label 8750 1650 2    50   ~ 0
Q1
Text Label 8750 1750 2    50   ~ 0
Q2
Text Label 8750 1850 2    50   ~ 0
Q3
Text Label 8750 1950 2    50   ~ 0
Q4
Text Label 8750 2050 2    50   ~ 0
Q5
Text Label 8750 2150 2    50   ~ 0
Q6
Text Label 8750 2250 2    50   ~ 0
Q7
Text Label 8750 2350 2    50   ~ 0
Q8
Text Label 8750 2450 2    50   ~ 0
Q9
Text Label 8750 2550 2    50   ~ 0
Q10
Text Label 8750 2650 2    50   ~ 0
Q11
Text Label 8750 2750 2    50   ~ 0
Q12
Text Label 8750 2850 2    50   ~ 0
Q13
Text Label 8750 2950 2    50   ~ 0
Q14
Text Label 8750 3050 2    50   ~ 0
Q15
Wire Wire Line
	8750 3050 8850 3050
Wire Wire Line
	8850 2950 8750 2950
Text Label 7050 2850 0    50   ~ 0
Q[0..11]
Wire Notes Line
	7550 850  7550 4050
Text Notes 3150 850  0    50   ~ 0
12-BIT BINARY COUNTER 1
Wire Notes Line
	2450 4200 2450 6600
Wire Notes Line
	2450 6600 4950 6600
Wire Notes Line
	4950 6600 4950 4200
Wire Notes Line
	4950 4200 2450 4200
Text Notes 3900 4200 0    50   ~ 0
12-BIT BINARY COUNTER 2
$Comp
L 74xx:74HC04 U?
U 1 1 5DBD607E
P 3450 2950
F 0 "U?" V 3404 3130 50  0000 L CNN
F 1 "74HC04" V 3495 3130 50  0000 L CNN
F 2 "" H 3450 2950 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 3450 2950 50  0001 C CNN
	1    3450 2950
	0    1    1    0   
$EndComp
Wire Notes Line
	3150 4050 3150 850 
Wire Notes Line
	3150 850  7550 850 
Wire Notes Line
	3150 4050 7550 4050
Wire Wire Line
	3450 3250 3450 3850
Wire Wire Line
	3450 2650 3450 1950
Connection ~ 3450 1950
Wire Wire Line
	3450 1950 3850 1950
$Comp
L Device:C C?
U 1 1 5DBDEC4E
P 6750 5000
F 0 "C?" V 6498 5000 50  0000 C CNN
F 1 "100nF" V 6589 5000 50  0000 C CNN
F 2 "" H 6788 4850 50  0001 C CNN
F 3 "~" H 6750 5000 50  0001 C CNN
	1    6750 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	6900 5000 7000 5000
Wire Wire Line
	7000 5000 7000 5050
Wire Wire Line
	7000 5000 7000 4950
Connection ~ 7000 5000
$Comp
L power:+5VD #PWR?
U 1 1 5DBE32EE
P 7000 4950
F 0 "#PWR?" H 7000 4800 50  0001 C CNN
F 1 "+5VD" H 7015 5123 50  0000 C CNN
F 2 "" H 7000 4950 50  0001 C CNN
F 3 "" H 7000 4950 50  0001 C CNN
	1    7000 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 5000 6550 5000
Wire Wire Line
	6550 5000 6550 5050
$Comp
L power:GNDD #PWR?
U 1 1 5DBE4BFC
P 6550 5050
F 0 "#PWR?" H 6550 4800 50  0001 C CNN
F 1 "GNDD" H 6554 4895 50  0000 C CNN
F 2 "" H 6550 5050 50  0001 C CNN
F 3 "" H 6550 5050 50  0001 C CNN
	1    6550 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 6050 7000 6100
$Comp
L power:GNDD #PWR?
U 1 1 5DBE65A0
P 7000 6100
F 0 "#PWR?" H 7000 5850 50  0001 C CNN
F 1 "GNDD" H 7004 5945 50  0000 C CNN
F 2 "" H 7000 6100 50  0001 C CNN
F 3 "" H 7000 6100 50  0001 C CNN
	1    7000 6100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5DBE6BCD
P 7700 5000
F 0 "C?" V 7448 5000 50  0000 C CNN
F 1 "100nF" V 7539 5000 50  0000 C CNN
F 2 "" H 7738 4850 50  0001 C CNN
F 3 "~" H 7700 5000 50  0001 C CNN
	1    7700 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	7550 5000 7500 5000
Wire Wire Line
	7500 5000 7500 5050
$Comp
L power:GNDD #PWR?
U 1 1 5DBE8659
P 7500 5050
F 0 "#PWR?" H 7500 4800 50  0001 C CNN
F 1 "GNDD" H 7504 4895 50  0000 C CNN
F 2 "" H 7500 5050 50  0001 C CNN
F 3 "" H 7500 5050 50  0001 C CNN
	1    7500 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 5050 7900 5000
Wire Wire Line
	7900 5000 7850 5000
Wire Wire Line
	7900 5000 7900 4950
Connection ~ 7900 5000
$Comp
L power:+5VD #PWR?
U 1 1 5DBEBCBF
P 7900 4950
F 0 "#PWR?" H 7900 4800 50  0001 C CNN
F 1 "+5VD" H 7915 5123 50  0000 C CNN
F 2 "" H 7900 4950 50  0001 C CNN
F 3 "" H 7900 4950 50  0001 C CNN
	1    7900 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 6050 7900 6100
$Comp
L power:GNDD #PWR?
U 1 1 5DBED8E9
P 7900 6100
F 0 "#PWR?" H 7900 5850 50  0001 C CNN
F 1 "GNDD" H 7904 5945 50  0000 C CNN
F 2 "" H 7900 6100 50  0001 C CNN
F 3 "" H 7900 6100 50  0001 C CNN
	1    7900 6100
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5DC09B9F
P 8800 6100
F 0 "#PWR?" H 8800 5850 50  0001 C CNN
F 1 "GNDD" H 8804 5945 50  0000 C CNN
F 2 "" H 8800 6100 50  0001 C CNN
F 3 "" H 8800 6100 50  0001 C CNN
	1    8800 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 6050 8800 6100
Wire Wire Line
	8800 5050 8800 5000
Wire Wire Line
	8800 5000 8750 5000
$Comp
L Device:C C?
U 1 1 5DC0D472
P 8600 5000
F 0 "C?" V 8348 5000 50  0000 C CNN
F 1 "100nF" V 8439 5000 50  0000 C CNN
F 2 "" H 8638 4850 50  0001 C CNN
F 3 "~" H 8600 5000 50  0001 C CNN
	1    8600 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	8450 5000 8400 5000
Wire Wire Line
	8400 5000 8400 5050
$Comp
L power:GNDD #PWR?
U 1 1 5DC0F329
P 8400 5050
F 0 "#PWR?" H 8400 4800 50  0001 C CNN
F 1 "GNDD" H 8404 4895 50  0000 C CNN
F 2 "" H 8400 5050 50  0001 C CNN
F 3 "" H 8400 5050 50  0001 C CNN
	1    8400 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 5000 8800 4950
Connection ~ 8800 5000
$Comp
L power:+5VD #PWR?
U 1 1 5DC111ED
P 8800 4950
F 0 "#PWR?" H 8800 4800 50  0001 C CNN
F 1 "+5VD" H 8815 5123 50  0000 C CNN
F 2 "" H 8800 4950 50  0001 C CNN
F 3 "" H 8800 4950 50  0001 C CNN
	1    8800 4950
	1    0    0    -1  
$EndComp
Wire Notes Line
	6350 4600 6350 6400
Wire Notes Line
	6350 6400 9400 6400
Wire Notes Line
	9400 6400 9400 4600
Wire Notes Line
	9400 4600 6350 4600
Text Notes 6350 4600 0    50   ~ 0
POWER SUPPLY PINS
Wire Notes Line
	6150 6400 6150 4600
Wire Notes Line
	6150 4600 5350 4600
Wire Notes Line
	5350 4600 5350 6400
Wire Notes Line
	5350 6400 6150 6400
Text Notes 5350 4600 0    50   ~ 0
UNUSED LOGIC GATES
$Comp
L ulib_MY_74xx:74HC4040 U?
U 1 1 5DDE79E4
P 4250 2100
F 0 "U?" H 4000 2800 50  0000 C CNN
F 1 "74HC4040" H 4500 2800 50  0000 C CNN
F 2 "Housings_SOIC:SOIC-16_3.9x9.9mm_Pitch1.27mm" H 4250 2050 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT4040.pdf" H 4250 2150 50  0001 C CNN
	1    4250 2100
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_74xx:74HC4040 U?
U 1 1 5DDE7D79
P 4250 5450
F 0 "U?" H 4000 6150 50  0000 C CNN
F 1 "74HC4040" H 4500 6150 50  0000 C CNN
F 2 "Housings_SOIC:SOIC-16_3.9x9.9mm_Pitch1.27mm" H 4250 5400 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT4040.pdf" H 4250 5500 50  0001 C CNN
	1    4250 5450
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_74xx:74HC30 U?
U 1 1 5DDE81EA
P 3350 5300
F 0 "U?" H 3350 4722 50  0000 C CNN
F 1 "74HC30" H 3350 4813 50  0000 C CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 3350 5250 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT30.pdf" H 3350 5350 50  0001 C CNN
	1    3350 5300
	1    0    0    1   
$EndComp
$Comp
L ulib_MY_74xx:74HC30 U?
U 2 1 5DDE832D
P 8800 5550
F 0 "U?" H 9050 5600 50  0000 L CNN
F 1 "74HC30" H 9050 5500 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 8800 5500 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT30.pdf" H 8800 5600 50  0001 C CNN
	2    8800 5550
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 5 1 5DDE868F
P 7900 5550
F 0 "U?" H 8130 5596 50  0000 L CNN
F 1 "74HC08" H 8130 5505 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 7900 5500 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 7900 5600 50  0001 C CNN
	5    7900 5550
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 5 1 5DDE8710
P 7000 5550
F 0 "U?" H 7230 5596 50  0000 L CNN
F 1 "74HC08" H 7230 5505 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 7000 5500 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 7000 5600 50  0001 C CNN
	5    7000 5550
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 1 1 5DDE88D1
P 5050 3350
F 0 "U?" V 5300 3100 50  0000 L CNN
F 1 "74HC08" H 4850 3150 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 5050 3300 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 5050 3400 50  0001 C CNN
	1    5050 3350
	0    1    1    0   
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 2 1 5DDE89F7
P 5450 3350
F 0 "U?" V 5700 3100 50  0000 L CNN
F 1 "74HC08" H 5250 3150 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 5450 3300 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 5450 3400 50  0001 C CNN
	2    5450 3350
	0    1    1    0   
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 3 1 5DDE8B26
P 5850 3350
F 0 "U?" V 6100 3100 50  0000 L CNN
F 1 "74HC08" H 5650 3150 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 5850 3300 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 5850 3400 50  0001 C CNN
	3    5850 3350
	0    1    1    0   
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 4 1 5DDE8C64
P 6250 3350
F 0 "U?" V 6500 3100 50  0000 L CNN
F 1 "74HC08" H 6050 3150 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 6250 3300 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 6250 3400 50  0001 C CNN
	4    6250 3350
	0    1    1    0   
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 1 1 5DDE8DB3
P 6650 3350
F 0 "U?" V 6900 3100 50  0000 L CNN
F 1 "74HC08" H 6450 3150 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 6650 3300 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 6650 3400 50  0001 C CNN
	1    6650 3350
	0    1    1    0   
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 2 1 5DDE8F14
P 7050 3350
F 0 "U?" V 7300 3100 50  0000 L CNN
F 1 "74HC08" H 6850 3150 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 7050 3300 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 7050 3400 50  0001 C CNN
	2    7050 3350
	0    1    1    0   
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 3 1 5DDE9105
P 5750 5100
F 0 "U?" H 5750 5425 50  0000 C CNN
F 1 "74HC08" H 5750 5334 50  0000 C CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 5750 5050 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 5750 5150 50  0001 C CNN
	3    5750 5100
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_74xx:74HC08 U?
U 4 1 5DDE9185
P 5750 5800
F 0 "U?" H 5750 6125 50  0000 C CNN
F 1 "74HC08" H 5750 6034 50  0000 C CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 5750 5750 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT08.pdf" H 5750 5850 50  0001 C CNN
	4    5750 5800
	1    0    0    -1  
$EndComp
Wire Bus Line
	2650 3950 7150 3950
Wire Bus Line
	2650 3950 2650 5500
Wire Bus Line
	4850 2850 7050 2850
Wire Bus Line
	4850 1650 4850 2850
$EndSCHEMATC
