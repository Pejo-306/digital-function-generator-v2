EESchema Schematic File Version 4
LIBS:signal-generator-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 7
Title "Digital Function Generator v2 - TFT LCD Module Interface Block"
Date "2019-12-01"
Rev "1"
Comp "Petar Nikolov"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3150 3800 1100 2200
U 5DF8DBFF
F0 "sheet5DF8DBE5" 50
F1 "level-shifter.sch" 50
F2 "SD_SCK" I R 4250 3900 50 
F3 "SD_MISO" I R 4250 4000 50 
F4 "SD_MOSI" I R 4250 4100 50 
F5 "T_IRQ" I R 4250 4400 50 
F6 "T_DO" I R 4250 4500 50 
F7 "T_DIN" I R 4250 4600 50 
F8 "T_CLK" I R 4250 4800 50 
F9 "LCD_SCK" I R 4250 5100 50 
F10 "SCK" I L 3150 5700 50 
F11 "MOSI" I L 3150 5800 50 
F12 "MISO" I L 3150 5900 50 
F13 "IRQ_T" I L 3150 4400 50 
F14 "LCD_SDO" I R 4250 5000 50 
F15 "LCD_SDI" I R 4250 5200 50 
F16 "SD_~CS" I R 4250 4200 50 
F17 "T_~CS" I R 4250 4700 50 
F18 "LCD_~RESET" I R 4250 5400 50 
F19 "~CS~_SD" I L 3150 4200 50 
F20 "~CS~_T" I L 3150 4700 50 
F21 "LCD_~CS" I R 4250 5500 50 
F22 "~CS~_LCD" I L 3150 5500 50 
F23 "~RESET~_LCD" I L 3150 5400 50 
F24 "LCD_DC\\~RS" I R 4250 5300 50 
F25 "DC\\~RS~_LCD" I L 3150 5300 50 
$EndSheet
$Comp
L ulib_Displays:MSP3218 #U?
U 1 1 5DF8DC05
P 5050 2350
AR Path="/5DF8DC05" Ref="#U?"  Part="1" 
AR Path="/5DF89F54/5DF8DC05" Ref="#U?"  Part="1" 
F 0 "#U?" H 5050 3450 50  0000 C CNN
F 1 "MSP3218" H 5050 3350 50  0000 C CNN
F 2 "" H 3150 4050 50  0001 C CNN
F 3 "http://www.lcdwiki.com/res/MSP3218/QD-TFT3202%20specification_v1.1.pdf" H 5000 2350 50  0001 C CNN
	1    5050 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 2950 7100 2950
Wire Wire Line
	7050 3050 7100 3050
$Comp
L power:+3.3V #PWR?
U 1 1 5DF8DC0E
P 7100 3050
AR Path="/5DF8DC0E" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DC0E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7100 2900 50  0001 C CNN
F 1 "+3.3V" V 7115 3178 50  0000 L CNN
F 2 "" H 7100 3050 50  0001 C CNN
F 3 "" H 7100 3050 50  0001 C CNN
	1    7100 3050
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5DF8DC14
P 7100 2950
AR Path="/5DF8DC14" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DC14" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7100 2700 50  0001 C CNN
F 1 "GNDD" V 7104 2840 50  0000 R CNN
F 2 "" H 7100 2950 50  0001 C CNN
F 3 "" H 7100 2950 50  0001 C CNN
	1    7100 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7050 2450 7100 2450
Wire Wire Line
	7050 2550 7100 2550
Wire Wire Line
	7050 2650 7100 2650
Wire Wire Line
	7050 2750 7100 2750
Wire Wire Line
	7050 2850 7100 2850
Text Label 7100 1650 0    50   ~ 0
T_IRQ
Text Label 7100 1750 0    50   ~ 0
T_DO
Text Label 7100 1850 0    50   ~ 0
T_DIN
Text Label 7100 1950 0    50   ~ 0
T_~CS
Text Label 7100 2050 0    50   ~ 0
T_CLK
Text Label 7100 2250 0    50   ~ 0
LCD_SDO
Text Label 7100 2450 0    50   ~ 0
LCD_SCK
Text Label 7100 2550 0    50   ~ 0
LCD_SDI
Text Label 7100 2650 0    50   ~ 0
LCD_DC\~RS
Text Label 7100 2750 0    50   ~ 0
LCD_~RESET
Text Label 7100 2850 0    50   ~ 0
LCD_~CS
Text Label 3000 2200 2    50   ~ 0
SD_SCK
Text Label 3000 2300 2    50   ~ 0
SD_MISO
Text Label 3000 2400 2    50   ~ 0
SD_MOSI
Text Label 3000 2500 2    50   ~ 0
SD_~CS
Text Label 4350 3900 0    50   ~ 0
SD_SCK
Text Label 4350 4000 0    50   ~ 0
SD_MISO
Text Label 4350 4100 0    50   ~ 0
SD_MOSI
Wire Wire Line
	4250 3900 4350 3900
Text Label 4350 4200 0    50   ~ 0
SD_~CS
Wire Wire Line
	4250 4400 4350 4400
Wire Wire Line
	4250 4000 4350 4000
Wire Wire Line
	4250 4100 4350 4100
Wire Wire Line
	4250 4200 4350 4200
Wire Wire Line
	4250 4500 4350 4500
Wire Wire Line
	4250 4600 4350 4600
Wire Wire Line
	4250 4700 4350 4700
Wire Wire Line
	4250 4800 4350 4800
Text Label 4350 4400 0    50   ~ 0
T_IRQ
Text Label 4350 4500 0    50   ~ 0
T_DO
Text Label 4350 4600 0    50   ~ 0
T_DIN
Text Label 4350 4700 0    50   ~ 0
T_~CS
Text Label 4350 4800 0    50   ~ 0
T_CLK
Wire Wire Line
	4250 5000 4350 5000
Wire Wire Line
	4250 5100 4350 5100
Wire Wire Line
	4250 5200 4350 5200
Wire Wire Line
	4250 5300 4350 5300
Wire Wire Line
	4250 5400 4350 5400
Wire Wire Line
	4250 5500 4350 5500
Text Label 4350 5000 0    50   ~ 0
LCD_SDO
Text Label 4350 5100 0    50   ~ 0
LCD_SCK
Text Label 4350 5200 0    50   ~ 0
LCD_SDI
Text Label 4350 5300 0    50   ~ 0
LCD_DC\~RS
Text Label 4350 5400 0    50   ~ 0
LCD_~RESET
Text Label 4350 5500 0    50   ~ 0
LCD_~CS
Wire Wire Line
	3150 4200 3050 4200
Wire Wire Line
	3150 4400 3050 4400
Wire Wire Line
	3150 4700 3050 4700
Wire Wire Line
	3150 5300 3050 5300
Wire Wire Line
	3150 5400 3050 5400
Wire Wire Line
	3150 5500 3050 5500
Wire Wire Line
	3150 5700 3050 5700
Wire Wire Line
	3150 5800 3050 5800
Wire Wire Line
	3150 5900 3050 5900
$Comp
L ulib_Digital_Potentiometers:MCP4551-MS U?
U 1 1 5DF8DC69
P 6500 4500
AR Path="/5DF8DC69" Ref="U?"  Part="1" 
AR Path="/5DF89F54/5DF8DC69" Ref="U?"  Part="1" 
F 0 "U?" H 6150 4750 50  0000 C CNN
F 1 "MCP4551-103E/MS" H 6000 4250 50  0000 C CNN
F 2 "Housings_SSOP:MSOP-8_3x3mm_Pitch0.65mm" H 6500 4500 50  0001 C CNN
F 3 "https://ww1.microchip.com/downloads/en/DeviceDoc/22096b.pdf" H 6500 4500 50  0001 C CNN
	1    6500 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 4400 5900 4400
Wire Wire Line
	6000 4500 5900 4500
Wire Wire Line
	6000 4600 5900 4600
$Comp
L power:GNDD #PWR?
U 1 1 5DF8DC75
P 5900 4600
AR Path="/5DF8DC75" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DC75" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5900 4350 50  0001 C CNN
F 1 "GNDD" V 5904 4490 50  0000 R CNN
F 2 "" H 5900 4600 50  0001 C CNN
F 3 "" H 5900 4600 50  0001 C CNN
	1    5900 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	6500 4800 6500 4900
$Comp
L power:GNDD #PWR?
U 1 1 5DF8DC7C
P 6500 4900
AR Path="/5DF8DC7C" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DC7C" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6500 4650 50  0001 C CNN
F 1 "GNDD" H 6504 4745 50  0000 C CNN
F 2 "" H 6500 4900 50  0001 C CNN
F 3 "" H 6500 4900 50  0001 C CNN
	1    6500 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4200 6500 4100
$Comp
L Device:C C?
U 1 1 5DF8DC83
P 6300 4100
AR Path="/5DF8DC83" Ref="C?"  Part="1" 
AR Path="/5DF89F54/5DF8DC83" Ref="C?"  Part="1" 
F 0 "C?" V 6048 4100 50  0000 C CNN
F 1 "100nF" V 6139 4100 50  0000 C CNN
F 2 "" H 6338 3950 50  0001 C CNN
F 3 "~" H 6300 4100 50  0001 C CNN
	1    6300 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	6450 4100 6500 4100
Connection ~ 6500 4100
Wire Wire Line
	6500 4100 6500 4000
Wire Wire Line
	6150 4100 6100 4100
$Comp
L power:GNDD #PWR?
U 1 1 5DF8DC8E
P 6100 4100
AR Path="/5DF8DC8E" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DC8E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6100 3850 50  0001 C CNN
F 1 "GNDD" V 6104 3990 50  0000 R CNN
F 2 "" H 6100 4100 50  0001 C CNN
F 3 "" H 6100 4100 50  0001 C CNN
	1    6100 4100
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5DF8DC94
P 6500 4000
AR Path="/5DF8DC94" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DC94" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6500 3850 50  0001 C CNN
F 1 "+3.3V" H 6515 4173 50  0000 C CNN
F 2 "" H 6500 4000 50  0001 C CNN
F 3 "" H 6500 4000 50  0001 C CNN
	1    6500 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4400 7100 4400
Wire Wire Line
	7100 4400 7100 4300
$Comp
L power:+3.3V #PWR?
U 1 1 5DF8DC9C
P 7100 4300
AR Path="/5DF8DC9C" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DC9C" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7100 4150 50  0001 C CNN
F 1 "+3.3V" H 7115 4473 50  0000 C CNN
F 2 "" H 7100 4300 50  0001 C CNN
F 3 "" H 7100 4300 50  0001 C CNN
	1    7100 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4600 7100 4600
Wire Wire Line
	7100 4600 7100 4700
$Comp
L power:GNDD #PWR?
U 1 1 5DF8DCA4
P 7100 4700
AR Path="/5DF8DCA4" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DCA4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7100 4450 50  0001 C CNN
F 1 "GNDD" H 7104 4545 50  0000 C CNN
F 2 "" H 7100 4700 50  0001 C CNN
F 3 "" H 7100 4700 50  0001 C CNN
	1    7100 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4500 7100 4500
Text Label 7100 4500 0    50   ~ 0
LCD_LED
Text Label 7100 2350 0    50   ~ 0
LCD_LED
$Comp
L power:+3.3V #PWR?
U 1 1 5DF8DCB5
P 8100 3050
AR Path="/5DF8DCB5" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DCB5" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8100 2900 50  0001 C CNN
F 1 "+3.3V" V 8115 3178 50  0000 L CNN
F 2 "" H 8100 3050 50  0001 C CNN
F 3 "" H 8100 3050 50  0001 C CNN
	1    8100 3050
	0    -1   1    0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5DF8DCBB
P 8100 2950
AR Path="/5DF8DCBB" Ref="#PWR?"  Part="1" 
AR Path="/5DF89F54/5DF8DCBB" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8100 2700 50  0001 C CNN
F 1 "GNDD" V 8104 2840 50  0000 R CNN
F 2 "" H 8100 2950 50  0001 C CNN
F 3 "" H 8100 2950 50  0001 C CNN
	1    8100 2950
	0    1    -1   0   
$EndComp
Text Label 8100 1650 2    50   ~ 0
T_IRQ
Text Label 8100 1750 2    50   ~ 0
T_DO
Text Label 8100 1850 2    50   ~ 0
T_DIN
Text Label 8100 1950 2    50   ~ 0
T_~CS
Text Label 8100 2050 2    50   ~ 0
T_CLK
Text Label 8100 2250 2    50   ~ 0
LCD_SDO
Text Label 8100 2450 2    50   ~ 0
LCD_SCK
Text Label 8100 2550 2    50   ~ 0
LCD_SDI
Text Label 8100 2650 2    50   ~ 0
LCD_DC\~RS
Text Label 8100 2750 2    50   ~ 0
LCD_~RESET
Text Label 8100 2850 2    50   ~ 0
LCD_~CS
Text Label 8100 2350 2    50   ~ 0
LCD_LED
Text Label 2250 2200 0    50   ~ 0
SD_SCK
Text Label 2250 2300 0    50   ~ 0
SD_MISO
Text Label 2250 2400 0    50   ~ 0
SD_MOSI
Text Label 2250 2500 0    50   ~ 0
SD_~CS
Wire Wire Line
	7050 2350 7100 2350
Wire Wire Line
	7050 2250 7100 2250
Wire Wire Line
	7050 2050 7100 2050
Wire Wire Line
	7050 1950 7100 1950
Wire Wire Line
	7050 1850 7100 1850
Wire Wire Line
	7050 1750 7100 1750
Wire Wire Line
	7050 1650 7100 1650
Wire Wire Line
	3050 2500 3000 2500
Wire Wire Line
	3050 2400 3000 2400
Wire Wire Line
	3050 2300 3000 2300
Wire Wire Line
	3050 2200 3000 2200
Wire Wire Line
	2250 2500 2200 2500
Wire Wire Line
	2250 2400 2200 2400
Wire Wire Line
	2250 2300 2200 2300
Wire Wire Line
	2250 2200 2200 2200
Wire Wire Line
	8100 1650 8150 1650
Wire Wire Line
	8100 1750 8150 1750
Wire Wire Line
	8100 1850 8150 1850
Wire Wire Line
	8100 1950 8150 1950
Wire Wire Line
	8100 2050 8150 2050
Wire Wire Line
	8100 2250 8150 2250
Wire Wire Line
	8100 2350 8150 2350
Wire Wire Line
	8100 2450 8150 2450
Wire Wire Line
	8100 2550 8150 2550
Wire Wire Line
	8100 2650 8150 2650
Wire Wire Line
	8100 2750 8150 2750
Wire Wire Line
	8100 2850 8150 2850
Wire Wire Line
	8100 2950 8150 2950
Wire Wire Line
	8100 3050 8150 3050
Text HLabel 5900 4400 0    50   Input ~ 0
SDA
Text HLabel 5900 4500 0    50   Input ~ 0
SCL
$Comp
L Connector_Generic:Conn_01x09 J?
U 1 1 5DFB8DFB
P 8350 2650
F 0 "J?" H 8450 2550 50  0000 C CNN
F 1 "LCD_Conn" H 8600 2650 50  0000 C CNN
F 2 "" H 8350 2650 50  0001 C CNN
F 3 "~" H 8350 2650 50  0001 C CNN
	1    8350 2650
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5DFB8ED1
P 8350 1850
F 0 "J?" H 8450 1750 50  0000 C CNN
F 1 "TP_Conn" H 8600 1850 50  0000 C CNN
F 2 "" H 8350 1850 50  0001 C CNN
F 3 "~" H 8350 1850 50  0001 C CNN
	1    8350 1850
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 5DFBC023
P 2000 2400
F 0 "J?" H 2150 2300 50  0000 C CNN
F 1 "SD_Card_Conn" H 2350 2400 50  0000 C CNN
F 2 "" H 2000 2400 50  0001 C CNN
F 3 "~" H 2000 2400 50  0001 C CNN
	1    2000 2400
	-1   0    0    1   
$EndComp
Text HLabel 3050 5700 0    50   Input ~ 0
SCK
Text HLabel 3050 5800 0    50   Input ~ 0
MOSI
Text HLabel 3050 5900 0    50   Input ~ 0
MISO
Text HLabel 3050 5300 0    50   Input ~ 0
DC\~RS~_LCD
Text HLabel 3050 5400 0    50   Input ~ 0
~RESET~_LCD
Text HLabel 3050 5500 0    50   Input ~ 0
~CS~_LCD
Text HLabel 3050 4700 0    50   Input ~ 0
~CS~_T
Text HLabel 3050 4400 0    50   Input ~ 0
IRQ_T
Text HLabel 3050 4200 0    50   Input ~ 0
~CS~_SD
$EndSCHEMATC
