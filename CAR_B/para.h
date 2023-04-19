#include <SPI.h>
#include <RFID.h>
#define SDA_DIO 48
#define RESET_DIO 51
RFID RC522(SDA_DIO, RESET_DIO);

#define SENSOR_L A11 //สีเขียว
#define SENSOR_C A12 //สีเหลือง
#define SENSOR_R A13 //สีเนื้อ
int now_x;
int sts = 0;
int sts_k = 0;
char key=" ";
char xx_key=" ";
String data="0";
int alrm = A8;
int lamp = A9;
int ll,cc,rr;
#define MtrBrake 0
#define ClockWise 1
#define CClockWise 2
#define GndBreak 3
#define CounterSenseThresHold 100

#include "HX711.h"

float calibration_factor = 52865.00;
#define zero_factor 8694261.00
#define DOUT  A14
#define CLK   A15
#define DEC_POINT  2

float offset = 0;
float get_units_kg();

HX711 scale(DOUT, CLK);

int statpin = 13;
int inApin[2] = { 7, 4 };  // INA Clockwise Controll
int inBpin[2] = { 8, 9 };  // INB Counter-clockwise Controll
int pwmpin[2] = { 5, 6 };  // PWM (Pulse with modulation ) Input
int cspin[2] = { 2, 3 };   // CS Current sense for analog input
int enpin[2] = { 0, 1 };
int tag = 999;
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {36, 34, 32, 30};
byte colPins[COLS] = {28, 26, 24, 22};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
