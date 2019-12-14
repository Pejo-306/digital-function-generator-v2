EESchema Schematic File Version 4
LIBS:signal-generator-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title "Digital Function Generator v2 - Level Shifter"
Date "2019-12-01"
Rev "1"
Comp "Petar Nikolov"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 9900 2450 2    50   Input ~ 0
SD_SCK
Text HLabel 9900 2650 2    50   Input ~ 0
SD_MISO
Text HLabel 9900 2850 2    50   Input ~ 0
SD_MOSI
$Comp
L ulib_MY_Transistor_FET:AP2310GN Q?
U 1 1 5DE29353
P 9500 1850
F 0 "Q?" V 9750 1850 50  0000 C CNN
F 1 "AP2310GN" V 9841 1850 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 10550 1700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Advanced-Power-Elec-AP2310GN-HF_C46746.pdf" H 11350 1600 50  0001 C CNN
	1    9500 1850
	0    -1   1    0   
$EndComp
Wire Wire Line
	9500 1650 9500 1550
$Comp
L Device:R R?
U 1 1 5DE2935B
P 9900 1750
F 0 "R?" H 9970 1796 50  0000 L CNN
F 1 "910R" H 9970 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9830 1750 50  0001 C CNN
F 3 "~" H 9900 1750 50  0001 C CNN
	1    9900 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 1950 9900 1950
Wire Wire Line
	9900 1950 9900 1900
Wire Wire Line
	9500 1550 9900 1550
Wire Wire Line
	9900 1550 9900 1600
$Comp
L Device:R R?
U 1 1 5DE29366
P 9100 1750
F 0 "R?" H 9170 1796 50  0000 L CNN
F 1 "910R" H 9170 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9030 1750 50  0001 C CNN
F 3 "~" H 9100 1750 50  0001 C CNN
	1    9100 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 1900 9100 1950
Wire Wire Line
	9100 1950 9300 1950
Wire Wire Line
	9100 1600 9100 1450
Wire Wire Line
	9900 1550 9900 1450
Connection ~ 9900 1550
Wire Wire Line
	9900 1950 10100 1950
Connection ~ 9900 1950
Wire Wire Line
	9100 1950 8900 1950
Connection ~ 9100 1950
$Comp
L power:+3.3V #PWR0228
U 1 1 5DE29376
P 9900 1450
F 0 "#PWR0228" H 9900 1300 50  0001 C CNN
F 1 "+3.3V" H 9915 1623 50  0000 C CNN
F 2 "" H 9900 1450 50  0001 C CNN
F 3 "" H 9900 1450 50  0001 C CNN
	1    9900 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0229
U 1 1 5DE2937C
P 9100 1450
F 0 "#PWR0229" H 9100 1300 50  0001 C CNN
F 1 "+5VD" H 9115 1623 50  0000 C CNN
F 2 "" H 9100 1450 50  0001 C CNN
F 3 "" H 9100 1450 50  0001 C CNN
	1    9100 1450
	1    0    0    -1  
$EndComp
Text HLabel 10100 1950 2    50   Input ~ 0
SD_~CS
Text HLabel 8000 1950 2    50   Input ~ 0
T_IRQ
Text HLabel 7800 3250 2    50   Input ~ 0
T_DO
Text HLabel 7800 3450 2    50   Input ~ 0
T_DIN
Text HLabel 8000 2750 2    50   Input ~ 0
T_~CS
Text HLabel 7800 3650 2    50   Input ~ 0
T_CLK
$Comp
L ulib_MY_Transistor_FET:AP2310GN Q?
U 1 1 5DE2D6FB
P 7400 1850
F 0 "Q?" V 7650 1850 50  0000 C CNN
F 1 "AP2310GN" V 7741 1850 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 8450 1700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Advanced-Power-Elec-AP2310GN-HF_C46746.pdf" H 9250 1600 50  0001 C CNN
	1    7400 1850
	0    -1   1    0   
$EndComp
Wire Wire Line
	7400 1650 7400 1550
$Comp
L Device:R R?
U 1 1 5DE2D703
P 7800 1750
F 0 "R?" H 7870 1796 50  0000 L CNN
F 1 "1k6" H 7870 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7730 1750 50  0001 C CNN
F 3 "~" H 7800 1750 50  0001 C CNN
	1    7800 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 1950 7800 1950
Wire Wire Line
	7800 1950 7800 1900
Wire Wire Line
	7400 1550 7800 1550
Wire Wire Line
	7800 1550 7800 1600
$Comp
L Device:R R?
U 1 1 5DE2D70E
P 7000 1750
F 0 "R?" H 7070 1796 50  0000 L CNN
F 1 "1k6" H 7070 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6930 1750 50  0001 C CNN
F 3 "~" H 7000 1750 50  0001 C CNN
	1    7000 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1900 7000 1950
Wire Wire Line
	7000 1950 7200 1950
Wire Wire Line
	7000 1600 7000 1450
Wire Wire Line
	7800 1550 7800 1450
Connection ~ 7800 1550
Wire Wire Line
	7800 1950 8000 1950
Connection ~ 7800 1950
Wire Wire Line
	7000 1950 6800 1950
Connection ~ 7000 1950
$Comp
L power:+3.3V #PWR0230
U 1 1 5DE2D71E
P 7800 1450
F 0 "#PWR0230" H 7800 1300 50  0001 C CNN
F 1 "+3.3V" H 7815 1623 50  0000 C CNN
F 2 "" H 7800 1450 50  0001 C CNN
F 3 "" H 7800 1450 50  0001 C CNN
	1    7800 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0231
U 1 1 5DE2D724
P 7000 1450
F 0 "#PWR0231" H 7000 1300 50  0001 C CNN
F 1 "+5VD" H 7015 1623 50  0000 C CNN
F 2 "" H 7000 1450 50  0001 C CNN
F 3 "" H 7000 1450 50  0001 C CNN
	1    7000 1450
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_Transistor_FET:AP2310GN Q?
U 1 1 5DE2D78B
P 7400 2650
F 0 "Q?" V 7650 2650 50  0000 C CNN
F 1 "AP2310GN" V 7741 2650 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 8450 2500 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Advanced-Power-Elec-AP2310GN-HF_C46746.pdf" H 9250 2400 50  0001 C CNN
	1    7400 2650
	0    -1   1    0   
$EndComp
Wire Wire Line
	7400 2450 7400 2350
$Comp
L Device:R R?
U 1 1 5DE2D793
P 7800 2550
F 0 "R?" H 7870 2596 50  0000 L CNN
F 1 "1k6" H 7870 2505 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7730 2550 50  0001 C CNN
F 3 "~" H 7800 2550 50  0001 C CNN
	1    7800 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 2750 7800 2750
Wire Wire Line
	7800 2750 7800 2700
Wire Wire Line
	7400 2350 7800 2350
Wire Wire Line
	7800 2350 7800 2400
$Comp
L Device:R R?
U 1 1 5DE2D79E
P 7000 2550
F 0 "R?" H 7070 2596 50  0000 L CNN
F 1 "1k6" H 7070 2505 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6930 2550 50  0001 C CNN
F 3 "~" H 7000 2550 50  0001 C CNN
	1    7000 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 2700 7000 2750
Wire Wire Line
	7000 2750 7200 2750
Wire Wire Line
	7000 2400 7000 2250
Wire Wire Line
	7800 2350 7800 2250
Connection ~ 7800 2350
Wire Wire Line
	7800 2750 8000 2750
Connection ~ 7800 2750
Wire Wire Line
	7000 2750 6800 2750
Connection ~ 7000 2750
$Comp
L power:+3.3V #PWR0232
U 1 1 5DE2D7AE
P 7800 2250
F 0 "#PWR0232" H 7800 2100 50  0001 C CNN
F 1 "+3.3V" H 7815 2423 50  0000 C CNN
F 2 "" H 7800 2250 50  0001 C CNN
F 3 "" H 7800 2250 50  0001 C CNN
	1    7800 2250
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0233
U 1 1 5DE2D7B4
P 7000 2250
F 0 "#PWR0233" H 7000 2100 50  0001 C CNN
F 1 "+5VD" H 7015 2423 50  0000 C CNN
F 2 "" H 7000 2250 50  0001 C CNN
F 3 "" H 7000 2250 50  0001 C CNN
	1    7000 2250
	1    0    0    -1  
$EndComp
Text HLabel 5500 4050 2    50   Input ~ 0
LCD_SDO
Text HLabel 5500 4450 2    50   Input ~ 0
LCD_SDI
Text HLabel 5500 4250 2    50   Input ~ 0
LCD_SCK
Text HLabel 5700 1950 2    50   Input ~ 0
LCD_DC\~RS
Text HLabel 5700 2750 2    50   Input ~ 0
LCD_~RESET
$Comp
L ulib_MY_Transistor_FET:AP2310GN Q?
U 1 1 5DDC7774
P 2700 1850
F 0 "Q?" V 2950 1850 50  0000 C CNN
F 1 "AP2310GN" V 3041 1850 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3750 1700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Advanced-Power-Elec-AP2310GN-HF_C46746.pdf" H 4550 1600 50  0001 C CNN
	1    2700 1850
	0    -1   1    0   
$EndComp
Wire Wire Line
	2700 1650 2700 1550
$Comp
L Device:R R?
U 1 1 5DDC777C
P 3100 1750
F 0 "R?" H 3170 1796 50  0000 L CNN
F 1 "560R" H 3170 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3030 1750 50  0001 C CNN
F 3 "~" H 3100 1750 50  0001 C CNN
	1    3100 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 1950 3100 1950
Wire Wire Line
	3100 1950 3100 1900
Wire Wire Line
	2700 1550 3100 1550
Wire Wire Line
	3100 1550 3100 1600
$Comp
L Device:R R?
U 1 1 5DDC7787
P 2300 1750
F 0 "R?" H 2370 1796 50  0000 L CNN
F 1 "560R" H 2370 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2230 1750 50  0001 C CNN
F 3 "~" H 2300 1750 50  0001 C CNN
	1    2300 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1900 2300 1950
Wire Wire Line
	2300 1950 2500 1950
Wire Wire Line
	2300 1600 2300 1450
Wire Wire Line
	3100 1550 3100 1450
Connection ~ 3100 1550
Wire Wire Line
	3100 1950 3300 1950
Connection ~ 3100 1950
Wire Wire Line
	2300 1950 2100 1950
Connection ~ 2300 1950
$Comp
L power:+3.3V #PWR0234
U 1 1 5DDC7797
P 3100 1450
F 0 "#PWR0234" H 3100 1300 50  0001 C CNN
F 1 "+3.3V" H 3115 1623 50  0000 C CNN
F 2 "" H 3100 1450 50  0001 C CNN
F 3 "" H 3100 1450 50  0001 C CNN
	1    3100 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0235
U 1 1 5DDC779D
P 2300 1450
F 0 "#PWR0235" H 2300 1300 50  0001 C CNN
F 1 "+5VD" H 2315 1623 50  0000 C CNN
F 2 "" H 2300 1450 50  0001 C CNN
F 3 "" H 2300 1450 50  0001 C CNN
	1    2300 1450
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_Transistor_FET:AP2310GN Q?
U 1 1 5DDC77A3
P 2700 2650
F 0 "Q?" V 2950 2650 50  0000 C CNN
F 1 "AP2310GN" V 3041 2650 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3750 2500 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Advanced-Power-Elec-AP2310GN-HF_C46746.pdf" H 4550 2400 50  0001 C CNN
	1    2700 2650
	0    -1   1    0   
$EndComp
Wire Wire Line
	2700 2450 2700 2350
$Comp
L Device:R R?
U 1 1 5DDC77AB
P 3100 2550
F 0 "R?" H 3170 2596 50  0000 L CNN
F 1 "560R" H 3170 2505 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3030 2550 50  0001 C CNN
F 3 "~" H 3100 2550 50  0001 C CNN
	1    3100 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2750 3100 2750
Wire Wire Line
	3100 2750 3100 2700
Wire Wire Line
	2700 2350 3100 2350
Wire Wire Line
	3100 2350 3100 2400
$Comp
L Device:R R?
U 1 1 5DDC77B6
P 2300 2550
F 0 "R?" H 2370 2596 50  0000 L CNN
F 1 "560R" H 2370 2505 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2230 2550 50  0001 C CNN
F 3 "~" H 2300 2550 50  0001 C CNN
	1    2300 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 2700 2300 2750
Wire Wire Line
	2300 2750 2500 2750
Wire Wire Line
	2300 2400 2300 2250
Wire Wire Line
	3100 2350 3100 2250
Connection ~ 3100 2350
Wire Wire Line
	3100 2750 3300 2750
Connection ~ 3100 2750
Wire Wire Line
	2300 2750 2100 2750
Connection ~ 2300 2750
$Comp
L power:+3.3V #PWR0236
U 1 1 5DDC77C6
P 3100 2250
F 0 "#PWR0236" H 3100 2100 50  0001 C CNN
F 1 "+3.3V" H 3115 2423 50  0000 C CNN
F 2 "" H 3100 2250 50  0001 C CNN
F 3 "" H 3100 2250 50  0001 C CNN
	1    3100 2250
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0237
U 1 1 5DDC77CC
P 2300 2250
F 0 "#PWR0237" H 2300 2100 50  0001 C CNN
F 1 "+5VD" H 2315 2423 50  0000 C CNN
F 2 "" H 2300 2250 50  0001 C CNN
F 3 "" H 2300 2250 50  0001 C CNN
	1    2300 2250
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_Transistor_FET:AP2310GN Q?
U 1 1 5DDC77D2
P 2700 3450
F 0 "Q?" V 2950 3450 50  0000 C CNN
F 1 "AP2310GN" V 3041 3450 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3750 3300 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Advanced-Power-Elec-AP2310GN-HF_C46746.pdf" H 4550 3200 50  0001 C CNN
	1    2700 3450
	0    -1   1    0   
$EndComp
Wire Wire Line
	2700 3250 2700 3150
$Comp
L Device:R R?
U 1 1 5DDC77DA
P 3100 3350
F 0 "R?" H 3170 3396 50  0000 L CNN
F 1 "560R" H 3170 3305 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3030 3350 50  0001 C CNN
F 3 "~" H 3100 3350 50  0001 C CNN
	1    3100 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3550 3100 3550
Wire Wire Line
	3100 3550 3100 3500
Wire Wire Line
	2700 3150 3100 3150
Wire Wire Line
	3100 3150 3100 3200
$Comp
L Device:R R?
U 1 1 5DDC77E5
P 2300 3350
F 0 "R?" H 2370 3396 50  0000 L CNN
F 1 "560R" H 2370 3305 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2230 3350 50  0001 C CNN
F 3 "~" H 2300 3350 50  0001 C CNN
	1    2300 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3500 2300 3550
Wire Wire Line
	2300 3550 2500 3550
Wire Wire Line
	2300 3200 2300 3050
Wire Wire Line
	3100 3150 3100 3050
Connection ~ 3100 3150
Wire Wire Line
	3100 3550 3300 3550
Connection ~ 3100 3550
Wire Wire Line
	2300 3550 2100 3550
Connection ~ 2300 3550
$Comp
L power:+3.3V #PWR0238
U 1 1 5DDC77F5
P 3100 3050
F 0 "#PWR0238" H 3100 2900 50  0001 C CNN
F 1 "+3.3V" H 3115 3223 50  0000 C CNN
F 2 "" H 3100 3050 50  0001 C CNN
F 3 "" H 3100 3050 50  0001 C CNN
	1    3100 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0239
U 1 1 5DDC77FB
P 2300 3050
F 0 "#PWR0239" H 2300 2900 50  0001 C CNN
F 1 "+5VD" H 2315 3223 50  0000 C CNN
F 2 "" H 2300 3050 50  0001 C CNN
F 3 "" H 2300 3050 50  0001 C CNN
	1    2300 3050
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_Transistor_FET:AP2310GN Q?
U 1 1 5DDC7801
P 5100 1850
F 0 "Q?" V 5350 1850 50  0000 C CNN
F 1 "AP2310GN" V 5441 1850 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 6150 1700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Advanced-Power-Elec-AP2310GN-HF_C46746.pdf" H 6950 1600 50  0001 C CNN
	1    5100 1850
	0    -1   1    0   
$EndComp
Wire Wire Line
	5100 1650 5100 1550
$Comp
L Device:R R?
U 1 1 5DDC7809
P 5500 1750
F 0 "R?" H 5570 1796 50  0000 L CNN
F 1 "560R" H 5570 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5430 1750 50  0001 C CNN
F 3 "~" H 5500 1750 50  0001 C CNN
	1    5500 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 1950 5500 1950
Wire Wire Line
	5500 1950 5500 1900
Wire Wire Line
	5100 1550 5500 1550
Wire Wire Line
	5500 1550 5500 1600
$Comp
L Device:R R?
U 1 1 5DDC7814
P 4700 1750
F 0 "R?" H 4770 1796 50  0000 L CNN
F 1 "560R" H 4770 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4630 1750 50  0001 C CNN
F 3 "~" H 4700 1750 50  0001 C CNN
	1    4700 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 1900 4700 1950
Wire Wire Line
	4700 1950 4900 1950
Wire Wire Line
	4700 1600 4700 1450
Wire Wire Line
	5500 1550 5500 1450
Connection ~ 5500 1550
Wire Wire Line
	5500 1950 5700 1950
Connection ~ 5500 1950
Wire Wire Line
	4700 1950 4500 1950
Connection ~ 4700 1950
$Comp
L power:+3.3V #PWR0240
U 1 1 5DDC7824
P 5500 1450
F 0 "#PWR0240" H 5500 1300 50  0001 C CNN
F 1 "+3.3V" H 5515 1623 50  0000 C CNN
F 2 "" H 5500 1450 50  0001 C CNN
F 3 "" H 5500 1450 50  0001 C CNN
	1    5500 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0241
U 1 1 5DDC782A
P 4700 1450
F 0 "#PWR0241" H 4700 1300 50  0001 C CNN
F 1 "+5VD" H 4715 1623 50  0000 C CNN
F 2 "" H 4700 1450 50  0001 C CNN
F 3 "" H 4700 1450 50  0001 C CNN
	1    4700 1450
	1    0    0    -1  
$EndComp
$Comp
L ulib_MY_Transistor_FET:AP2310GN Q?
U 1 1 5DDC7830
P 5100 2650
F 0 "Q?" V 5350 2650 50  0000 C CNN
F 1 "AP2310GN" V 5441 2650 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 6150 2500 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Advanced-Power-Elec-AP2310GN-HF_C46746.pdf" H 6950 2400 50  0001 C CNN
	1    5100 2650
	0    -1   1    0   
$EndComp
Wire Wire Line
	5100 2450 5100 2350
$Comp
L Device:R R?
U 1 1 5DDC7838
P 5500 2550
F 0 "R?" H 5570 2596 50  0000 L CNN
F 1 "560R" H 5570 2505 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5430 2550 50  0001 C CNN
F 3 "~" H 5500 2550 50  0001 C CNN
	1    5500 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 2750 5500 2750
Wire Wire Line
	5500 2750 5500 2700
Wire Wire Line
	5100 2350 5500 2350
Wire Wire Line
	5500 2350 5500 2400
$Comp
L Device:R R?
U 1 1 5DDC7843
P 4700 2550
F 0 "R?" H 4770 2596 50  0000 L CNN
F 1 "560R" H 4770 2505 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4630 2550 50  0001 C CNN
F 3 "~" H 4700 2550 50  0001 C CNN
	1    4700 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2700 4700 2750
Wire Wire Line
	4700 2750 4900 2750
Wire Wire Line
	4700 2400 4700 2250
Wire Wire Line
	5500 2350 5500 2250
Connection ~ 5500 2350
Wire Wire Line
	5500 2750 5700 2750
Connection ~ 5500 2750
Wire Wire Line
	4700 2750 4500 2750
Connection ~ 4700 2750
$Comp
L power:+3.3V #PWR0242
U 1 1 5DDC7853
P 5500 2250
F 0 "#PWR0242" H 5500 2100 50  0001 C CNN
F 1 "+3.3V" H 5515 2423 50  0000 C CNN
F 2 "" H 5500 2250 50  0001 C CNN
F 3 "" H 5500 2250 50  0001 C CNN
	1    5500 2250
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0243
U 1 1 5DDC7859
P 4700 2250
F 0 "#PWR0243" H 4700 2100 50  0001 C CNN
F 1 "+5VD" H 4715 2423 50  0000 C CNN
F 2 "" H 4700 2250 50  0001 C CNN
F 3 "" H 4700 2250 50  0001 C CNN
	1    4700 2250
	1    0    0    -1  
$EndComp
Text HLabel 2100 2750 0    50   Input ~ 0
SCK
Text HLabel 2100 3550 0    50   Input ~ 0
MOSI
Text HLabel 2100 1950 0    50   Input ~ 0
MISO
Text HLabel 8900 1950 0    50   Input ~ 0
~CS~_SD
Text HLabel 6800 2750 0    50   Input ~ 0
~CS~_T
Text HLabel 5700 3550 2    50   Input ~ 0
LCD_~CS
$Comp
L ulib_MY_Transistor_FET:AP2310GN Q?
U 1 1 5DE5E971
P 5100 3450
F 0 "Q?" V 5350 3450 50  0000 C CNN
F 1 "AP2310GN" V 5441 3450 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 6150 3300 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Advanced-Power-Elec-AP2310GN-HF_C46746.pdf" H 6950 3200 50  0001 C CNN
	1    5100 3450
	0    -1   1    0   
$EndComp
Wire Wire Line
	5100 3250 5100 3150
$Comp
L Device:R R?
U 1 1 5DE5E979
P 5500 3350
F 0 "R?" H 5570 3396 50  0000 L CNN
F 1 "560R" H 5570 3305 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5430 3350 50  0001 C CNN
F 3 "~" H 5500 3350 50  0001 C CNN
	1    5500 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3550 5500 3550
Wire Wire Line
	5500 3550 5500 3500
Wire Wire Line
	5100 3150 5500 3150
Wire Wire Line
	5500 3150 5500 3200
$Comp
L Device:R R?
U 1 1 5DE5E984
P 4700 3350
F 0 "R?" H 4770 3396 50  0000 L CNN
F 1 "560R" H 4770 3305 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4630 3350 50  0001 C CNN
F 3 "~" H 4700 3350 50  0001 C CNN
	1    4700 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3500 4700 3550
Wire Wire Line
	4700 3550 4900 3550
Wire Wire Line
	4700 3200 4700 3050
Wire Wire Line
	5500 3150 5500 3050
Connection ~ 5500 3150
Wire Wire Line
	5500 3550 5700 3550
Connection ~ 5500 3550
Wire Wire Line
	4700 3550 4500 3550
Connection ~ 4700 3550
$Comp
L power:+3.3V #PWR0244
U 1 1 5DE5E994
P 5500 3050
F 0 "#PWR0244" H 5500 2900 50  0001 C CNN
F 1 "+3.3V" H 5515 3223 50  0000 C CNN
F 2 "" H 5500 3050 50  0001 C CNN
F 3 "" H 5500 3050 50  0001 C CNN
	1    5500 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0245
U 1 1 5DE5E99A
P 4700 3050
F 0 "#PWR0245" H 4700 2900 50  0001 C CNN
F 1 "+5VD" H 4715 3223 50  0000 C CNN
F 2 "" H 4700 3050 50  0001 C CNN
F 3 "" H 4700 3050 50  0001 C CNN
	1    4700 3050
	1    0    0    -1  
$EndComp
Text HLabel 4500 3550 0    50   Input ~ 0
~CS~_LCD
Text HLabel 4500 2750 0    50   Input ~ 0
~RESET~_LCD
Text HLabel 4500 1950 0    50   Input ~ 0
DC\~RS~_LCD
Text HLabel 6800 1950 0    50   Input ~ 0
IRQ_T
Wire Notes Line
	10600 1150 8500 1150
Text Notes 8500 1150 0    50   ~ 0
SD CARD LEVEL SHIFTER (4 MHz)
Text Notes 6500 1150 0    50   ~ 0
TOUCH PANEL LEVEL SHIFTER (2 MHz)
Text Notes 3900 1150 0    50   ~ 0
LCD DRIVER LEVEL SHIFTER (4 MHz)
Text Label 3300 1950 0    50   ~ 0
MISO_3.3
Text Label 3300 3550 0    50   ~ 0
MOSI_3.3
Text Label 3300 2750 0    50   ~ 0
SCK_3.3
Text Label 4700 4050 2    50   ~ 0
MISO_3.3
Text Label 4700 4450 2    50   ~ 0
MOSI_3.3
Text Label 4700 4250 2    50   ~ 0
SCK_3.3
Wire Wire Line
	5500 4050 4700 4050
Wire Wire Line
	5500 4450 4700 4450
Wire Wire Line
	4700 4250 5500 4250
Text Label 7000 3250 2    50   ~ 0
MISO_3.3
Text Label 7000 3450 2    50   ~ 0
MOSI_3.3
Text Label 7000 3650 2    50   ~ 0
SCK_3.3
Wire Wire Line
	7000 3250 7800 3250
Wire Wire Line
	7800 3450 7000 3450
Wire Wire Line
	7000 3650 7800 3650
Text Label 9100 2650 2    50   ~ 0
MISO_3.3
Text Label 9100 2850 2    50   ~ 0
MOSI_3.3
Text Label 9100 2450 2    50   ~ 0
SCK_3.3
Wire Wire Line
	9100 2450 9900 2450
Wire Wire Line
	9900 2650 9100 2650
Wire Wire Line
	9100 2850 9900 2850
Wire Notes Line
	8500 1150 8500 3050
Wire Notes Line
	8500 3050 10600 3050
Wire Notes Line
	10600 3050 10600 1150
Wire Notes Line
	6500 1150 6500 3850
Wire Notes Line
	6500 3850 8300 3850
Wire Notes Line
	8300 3850 8300 1150
Wire Notes Line
	8300 1150 6500 1150
Wire Notes Line
	3900 1150 3900 4650
Wire Notes Line
	3900 4650 6300 4650
Wire Notes Line
	6300 4650 6300 1150
Wire Notes Line
	6300 1150 3900 1150
Wire Notes Line
	1800 1150 1800 3950
Wire Notes Line
	1800 3950 3700 3950
Wire Notes Line
	3700 3950 3700 1150
Wire Notes Line
	3700 1150 1800 1150
Text Notes 1800 1150 0    50   ~ 0
COMMON SPI LINES (up to 4 MHz)
$EndSCHEMATC
