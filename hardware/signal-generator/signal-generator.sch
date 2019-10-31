EESchema Schematic File Version 4
LIBS:signal-generator-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "Digital Function Generator v2"
Date "2019-10-31"
Rev "1"
Comp "Petar Nikolov"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 4750 3300 1350 800 
U 5DB72CF6
F0 "DDS System" 50
F1 "DDS-system.sch" 50
$EndSheet
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J?
U 1 1 5DB738D5
P 1250 5750
F 0 "J?" H 1300 6167 50  0000 C CNN
F 1 "Power_Supply_Rails" H 1300 6076 50  0000 C CNN
F 2 "" H 1250 5750 50  0001 C CNN
F 3 "~" H 1250 5750 50  0001 C CNN
	1    1250 5750
	1    0    0    -1  
$EndComp
NoConn ~ 1050 5750
NoConn ~ 1550 5750
Wire Wire Line
	1050 5550 950  5550
Text GLabel 950  5550 0    50   Input ~ 0
+12VA
Wire Wire Line
	1050 5650 950  5650
Wire Wire Line
	950  5850 1050 5850
Wire Wire Line
	950  5950 1050 5950
Wire Wire Line
	1550 5550 1650 5550
Wire Wire Line
	1550 5650 1650 5650
Wire Wire Line
	1550 5850 1650 5850
Wire Wire Line
	1550 5950 1650 5950
Text GLabel 1650 5550 2    50   Input ~ 0
-12VA
Text GLabel 1650 5650 2    50   Input ~ 0
AGND
Text GLabel 950  5650 0    50   Input ~ 0
AGND
Text GLabel 950  5950 0    50   Input ~ 0
+5VD
Text GLabel 950  5850 0    50   Input ~ 0
DGND
Text GLabel 1650 5850 2    50   Input ~ 0
DGND
Text GLabel 1650 5950 2    50   Input ~ 0
DGND
$Comp
L power:+5VD #PWR0101
U 1 1 5DB73A25
P 1700 6500
F 0 "#PWR0101" H 1700 6350 50  0001 C CNN
F 1 "+5VD" H 1715 6673 50  0000 C CNN
F 2 "" H 1700 6500 50  0001 C CNN
F 3 "" H 1700 6500 50  0001 C CNN
	1    1700 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 6500 1700 6600
Connection ~ 1700 6600
Wire Wire Line
	1700 6600 1700 6700
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5DB73278
P 1700 6700
F 0 "#FLG0101" H 1700 6775 50  0001 C CNN
F 1 "PWR_FLAG" H 1700 6873 50  0000 C CNN
F 2 "" H 1700 6700 50  0001 C CNN
F 3 "~" H 1700 6700 50  0001 C CNN
	1    1700 6700
	-1   0    0    1   
$EndComp
Wire Wire Line
	1700 6600 1750 6600
Text GLabel 1750 6600 2    50   Input ~ 0
+5VD
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5DB7342D
P 1700 7150
F 0 "#FLG0102" H 1700 7225 50  0001 C CNN
F 1 "PWR_FLAG" H 1700 7324 50  0000 C CNN
F 2 "" H 1700 7150 50  0001 C CNN
F 3 "~" H 1700 7150 50  0001 C CNN
	1    1700 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 7150 1700 7250
Connection ~ 1700 7250
Wire Wire Line
	1700 7250 1700 7350
$Comp
L power:GNDD #PWR0102
U 1 1 5DB73582
P 1700 7350
F 0 "#PWR0102" H 1700 7100 50  0001 C CNN
F 1 "GNDD" H 1704 7195 50  0000 C CNN
F 2 "" H 1700 7350 50  0001 C CNN
F 3 "" H 1700 7350 50  0001 C CNN
	1    1700 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 7250 1750 7250
Text GLabel 1750 7250 2    50   Input ~ 0
DGND
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5DB736AC
P 1300 7150
F 0 "#FLG0103" H 1300 7225 50  0001 C CNN
F 1 "PWR_FLAG" H 1300 7324 50  0000 C CNN
F 2 "" H 1300 7150 50  0001 C CNN
F 3 "~" H 1300 7150 50  0001 C CNN
	1    1300 7150
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 5DB736BB
P 900 7150
F 0 "#FLG0104" H 900 7225 50  0001 C CNN
F 1 "PWR_FLAG" H 900 7324 50  0000 C CNN
F 2 "" H 900 7150 50  0001 C CNN
F 3 "~" H 900 7150 50  0001 C CNN
	1    900  7150
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0105
U 1 1 5DB736C8
P 900 6700
F 0 "#FLG0105" H 900 6775 50  0001 C CNN
F 1 "PWR_FLAG" H 900 6873 50  0000 C CNN
F 2 "" H 900 6700 50  0001 C CNN
F 3 "~" H 900 6700 50  0001 C CNN
	1    900  6700
	-1   0    0    1   
$EndComp
Wire Wire Line
	900  6700 900  6600
$Comp
L power:+12VA #PWR0103
U 1 1 5DB73845
P 900 6500
F 0 "#PWR0103" H 900 6350 50  0001 C CNN
F 1 "+12VA" H 915 6673 50  0000 C CNN
F 2 "" H 900 6500 50  0001 C CNN
F 3 "" H 900 6500 50  0001 C CNN
	1    900  6500
	1    0    0    -1  
$EndComp
$Comp
L power:-12VA #PWR0104
U 1 1 5DB739CD
P 900 7350
F 0 "#PWR0104" H 900 7200 50  0001 C CNN
F 1 "-12VA" H 915 7523 50  0000 C CNN
F 2 "" H 900 7350 50  0001 C CNN
F 3 "" H 900 7350 50  0001 C CNN
	1    900  7350
	-1   0    0    1   
$EndComp
Text GLabel 950  7250 2    50   Input ~ 0
-12VA
Wire Wire Line
	900  7150 900  7250
Wire Wire Line
	950  7250 900  7250
Connection ~ 900  7250
Wire Wire Line
	900  7250 900  7350
Wire Wire Line
	900  6600 950  6600
Connection ~ 900  6600
Wire Wire Line
	900  6600 900  6500
Text GLabel 950  6600 2    50   Input ~ 0
+12VA
Wire Wire Line
	1300 7150 1300 7250
$Comp
L power:GNDA #PWR0105
U 1 1 5DB743B9
P 1300 7350
F 0 "#PWR0105" H 1300 7100 50  0001 C CNN
F 1 "GNDA" H 1305 7177 50  0000 C CNN
F 2 "" H 1300 7350 50  0001 C CNN
F 3 "" H 1300 7350 50  0001 C CNN
	1    1300 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 7250 1350 7250
Connection ~ 1300 7250
Wire Wire Line
	1300 7250 1300 7350
Text GLabel 1350 7250 2    50   Input ~ 0
AGND
Wire Notes Line
	600  6200 600  7650
Wire Notes Line
	600  7650 2100 7650
Wire Notes Line
	2100 7650 2100 6200
Wire Notes Line
	2100 6200 600  6200
Text Notes 600  6200 0    50   ~ 0
POWER FLAGS
$Comp
L power:+5VD #PWR0106
U 1 1 5DB74C65
P 3350 6400
F 0 "#PWR0106" H 3350 6250 50  0001 C CNN
F 1 "+5VD" H 3365 6573 50  0000 C CNN
F 2 "" H 3350 6400 50  0001 C CNN
F 3 "" H 3350 6400 50  0001 C CNN
	1    3350 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6400 3350 6500
$Comp
L Device:CP C?
U 1 1 5DB74F2C
P 3350 6650
F 0 "C?" H 3468 6696 50  0000 L CNN
F 1 "10uF/16V" H 3468 6605 50  0000 L CNN
F 2 "" H 3388 6500 50  0001 C CNN
F 3 "~" H 3350 6650 50  0001 C CNN
	1    3350 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6800 3350 6900
$Comp
L power:GNDD #PWR0107
U 1 1 5DB7527E
P 3350 6900
F 0 "#PWR0107" H 3350 6650 50  0001 C CNN
F 1 "GNDD" H 3354 6745 50  0000 C CNN
F 2 "" H 3350 6900 50  0001 C CNN
F 3 "" H 3350 6900 50  0001 C CNN
	1    3350 6900
	1    0    0    -1  
$EndComp
$Comp
L power:+12VA #PWR0108
U 1 1 5DB752E5
P 2750 6400
F 0 "#PWR0108" H 2750 6250 50  0001 C CNN
F 1 "+12VA" H 2765 6573 50  0000 C CNN
F 2 "" H 2750 6400 50  0001 C CNN
F 3 "" H 2750 6400 50  0001 C CNN
	1    2750 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 6400 2750 6500
$Comp
L Device:CP C?
U 1 1 5DB75648
P 2750 6650
F 0 "C?" H 2868 6696 50  0000 L CNN
F 1 "10uF/16V" H 2250 6600 50  0000 L CNN
F 2 "" H 2788 6500 50  0001 C CNN
F 3 "~" H 2750 6650 50  0001 C CNN
	1    2750 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 6800 2750 6900
$Comp
L Device:CP C?
U 1 1 5DB75DB4
P 2750 7150
F 0 "C?" H 2500 7200 50  0000 L CNN
F 1 "10uF/16V" H 2250 7100 50  0000 L CNN
F 2 "" H 2788 7000 50  0001 C CNN
F 3 "~" H 2750 7150 50  0001 C CNN
	1    2750 7150
	1    0    0    -1  
$EndComp
Connection ~ 2750 6900
Wire Wire Line
	2750 6900 2750 7000
Wire Wire Line
	2750 7300 2750 7400
$Comp
L power:-12VA #PWR0109
U 1 1 5DB76671
P 2750 7400
F 0 "#PWR0109" H 2750 7250 50  0001 C CNN
F 1 "-12VA" H 2765 7573 50  0000 C CNN
F 2 "" H 2750 7400 50  0001 C CNN
F 3 "" H 2750 7400 50  0001 C CNN
	1    2750 7400
	-1   0    0    1   
$EndComp
$Comp
L power:GNDA #PWR0110
U 1 1 5DB766FB
P 3050 7000
F 0 "#PWR0110" H 3050 6750 50  0001 C CNN
F 1 "GNDA" H 3055 6827 50  0000 C CNN
F 2 "" H 3050 7000 50  0001 C CNN
F 3 "" H 3050 7000 50  0001 C CNN
	1    3050 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 7000 3050 6900
Wire Wire Line
	3050 6900 2750 6900
Wire Notes Line
	2200 7650 2200 6100
Text Notes 2200 6100 0    50   ~ 0
SMOOTHING CAPACITORS
$Comp
L Regulator_Linear:ADP7142AUZJ U?
U 1 1 5DBADB92
P 5250 6400
F 0 "U?" H 5250 6767 50  0000 C CNN
F 1 "ADP7142AUZJ-5.0" H 5250 6676 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-5" H 5250 6000 50  0001 C CIN
F 3 "http://www.analog.com/media/en/technical-documentation/data-sheets/ADP7142.pdf" H 5250 5900 50  0001 C CNN
	1    5250 6400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5DBAE3B6
P 5950 6550
F 0 "C?" H 6065 6596 50  0000 L CNN
F 1 "2.2uF" H 6065 6505 50  0000 L CNN
F 2 "" H 5988 6400 50  0001 C CNN
F 3 "~" H 5950 6550 50  0001 C CNN
	1    5950 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 6400 5950 6300
Wire Wire Line
	5950 6300 5650 6300
Wire Wire Line
	5950 6300 6050 6300
Wire Wire Line
	6050 6300 6050 6200
Connection ~ 5950 6300
$Comp
L power:+5VA #PWR0111
U 1 1 5DBAF012
P 6050 6200
F 0 "#PWR0111" H 6050 6050 50  0001 C CNN
F 1 "+5VA" H 6065 6373 50  0000 C CNN
F 2 "" H 6050 6200 50  0001 C CNN
F 3 "" H 6050 6200 50  0001 C CNN
	1    6050 6200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5DBAF7CE
P 4550 6550
F 0 "C?" H 4300 6600 50  0000 L CNN
F 1 "2.2uF" H 4200 6500 50  0000 L CNN
F 2 "" H 4588 6400 50  0001 C CNN
F 3 "~" H 4550 6550 50  0001 C CNN
	1    4550 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 6400 4550 6300
Wire Wire Line
	4550 6300 4850 6300
Wire Wire Line
	4550 6300 4450 6300
Wire Wire Line
	4450 6300 4450 6200
Connection ~ 4550 6300
$Comp
L power:+12VA #PWR0112
U 1 1 5DBB0862
P 4450 6200
F 0 "#PWR0112" H 4450 6050 50  0001 C CNN
F 1 "+12VA" H 4465 6373 50  0000 C CNN
F 2 "" H 4450 6200 50  0001 C CNN
F 3 "" H 4450 6200 50  0001 C CNN
	1    4450 6200
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:ADP7182AUZJ U?
U 1 1 5DBB56CB
P 5250 7200
F 0 "U?" H 5250 6926 50  0000 C CNN
F 1 "ADP7182AUZJ-5.0" H 5250 6835 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-5" H 5250 6800 50  0001 C CIN
F 3 "http://www.analog.com/media/en/technical-documentation/data-sheets/ADP7182.pdf" H 5250 6700 50  0001 C CNN
	1    5250 7200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5DBB61A3
P 5950 7050
F 0 "C?" H 6065 7096 50  0000 L CNN
F 1 "2.2uF" H 6065 7005 50  0000 L CNN
F 2 "" H 5988 6900 50  0001 C CNN
F 3 "~" H 5950 7050 50  0001 C CNN
	1    5950 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 6700 5950 6800
Wire Wire Line
	5950 7200 5950 7300
Wire Wire Line
	5950 7300 5650 7300
Wire Wire Line
	4550 7300 4450 7300
$Comp
L power:-12VA #PWR0113
U 1 1 5DBBA45E
P 4450 7400
F 0 "#PWR0113" H 4450 7250 50  0001 C CNN
F 1 "-12VA" H 4465 7573 50  0000 C CNN
F 2 "" H 4450 7400 50  0001 C CNN
F 3 "" H 4450 7400 50  0001 C CNN
	1    4450 7400
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5DBBA49D
P 4550 7050
F 0 "C?" H 4300 7100 50  0000 L CNN
F 1 "2.2uF" H 4200 7000 50  0000 L CNN
F 2 "" H 4588 6900 50  0001 C CNN
F 3 "~" H 4550 7050 50  0001 C CNN
	1    4550 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 7300 4550 7200
Wire Wire Line
	4550 6700 4550 6800
Wire Wire Line
	5950 7300 6050 7300
Wire Wire Line
	6050 7300 6050 7400
Connection ~ 5950 7300
$Comp
L power:-5VA #PWR0114
U 1 1 5DBBCDC5
P 6050 7400
F 0 "#PWR0114" H 6050 7500 50  0001 C CNN
F 1 "-5VA" H 6065 7573 50  0000 C CNN
F 2 "" H 6050 7400 50  0001 C CNN
F 3 "" H 6050 7400 50  0001 C CNN
	1    6050 7400
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 6800 4550 6800
Connection ~ 5250 6800
Connection ~ 4550 6800
Wire Wire Line
	4550 6800 4550 6900
Wire Wire Line
	5250 6800 5950 6800
Connection ~ 5950 6800
Wire Wire Line
	5950 6800 5950 6900
Wire Wire Line
	4850 7300 4550 7300
Connection ~ 4550 7300
Wire Wire Line
	4450 7400 4450 7300
Wire Wire Line
	5250 6800 5250 6900
Wire Wire Line
	5250 6700 5250 6800
NoConn ~ 5650 7100
Wire Notes Line
	3950 6100 3950 7650
Wire Notes Line
	2200 6100 3950 6100
Wire Notes Line
	2200 7650 3950 7650
Wire Wire Line
	4550 7300 4750 7100
Wire Wire Line
	4750 7100 4850 7100
Wire Wire Line
	4550 6300 4850 6500
Wire Wire Line
	5650 6500 5950 6300
$Comp
L power:GNDA #PWR0115
U 1 1 5DBE9E60
P 4450 6800
F 0 "#PWR0115" H 4450 6550 50  0001 C CNN
F 1 "GNDA" V 4455 6673 50  0000 R CNN
F 2 "" H 4450 6800 50  0001 C CNN
F 3 "" H 4450 6800 50  0001 C CNN
	1    4450 6800
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 6800 4550 6800
Wire Notes Line
	4050 7650 4050 5900
Wire Notes Line
	4050 5900 6350 5900
Wire Notes Line
	6350 5900 6350 7650
Wire Notes Line
	6350 7650 4050 7650
Text Notes 4050 5900 0    50   ~ 0
+5VA/-5VA RAILS
Wire Notes Line
	6400 7700 550  7700
Wire Notes Line
	550  7700 550  5200
Wire Notes Line
	550  5200 6400 5200
Wire Notes Line
	6400 5200 6400 7700
Text Notes 550  5200 0    50   ~ 0
POWER SUPPLY
$EndSCHEMATC
