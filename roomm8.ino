/*

This is ROOMM8's main file which act 
like a bridge to every files in this robot.

*/

//include things that use

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>

//RTC_DS3231 is a Real-time Clock and Temperature sensor.
RTC_DS3231 RTC;

//Just a debug things so I can easily read the output. change to 1 to activate debugging
int debug = 0;

//LCD setup using I2C
LiquidCrystal_I2C lcd(0x3F, 16, 2);

//Function declaring
const int function_register = 4;
char function[function_register][10] = {"Runner", "Guard", "Alarm", "Clock"};
int function_called = 0;
int function_id = 0;

//Distance that ROOMM8 needs between object and itself (in cm).
int space = 20;
int pre_distances[3] = {0,0,0};

//Movemnet
int movement_stack[3] = {0,0,0};

//Sonar Front
int echoPin1 =12;
int initPin1 =13;
int front;

//Sonar Left
int echoPin2 =10;
int initPin2 =11;
int left;

//Sonar Right
int echoPin3 =8;
int initPin3 =9;
int right;

// Motors
int RM1 = 7;
int RM2 = 6; // left motor
int LM1 = 4;
int LM2 = 5; // right motor
int speed = 3;

// temperature
float temp = 0, arr[50];
int count = 0;
float temp_predict;

// keypad
int val[4];

//buzzer
int buzzer = 2;

//alarm
int alarm_time[3] = {0, 0, 0};
int alarm_pre = -1;

//guard
int guard_enable = 0;
int suspect = 0;
int sample = 0;
int position_stack[3] = {0,0,0};

//adjust time
int adjust_time[2] = {0, 0};

void setup() {

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);

  // ultrasonic pinMode
  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(initPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  // end ultrasonic pinMode

  pinMode(buzzer, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);

  Serial.begin(9600); //using serial monitor

  //start the lcd
  lcd.begin();
  lcd.backlight();

  //Logo Output
  display_standby();
  delay(2000);

  Wire.begin(); // use for I2C communication
  RTC.begin(); // use for RTC_DS3231 (Real-time Clock and Temperature)
  DateTime now = RTC.now(); // get the time
  int second = now.second(); // get the second
  randomSeed(second); // use second to generate random thing
}

void loop() {

  // debugging things
  while (debug) {
    debug_log();
  }

  // Set up alarm on RTC
  if (alarm_pre != alarm_time[2]) {
    if (alarm_time[2] == 1) {
      Serial.println("Alarm : On");
      RTC.turnOnAlarm(1);
    } else {
      Serial.println("Alarm : Off");
      RTC.turnOffAlarm(1);
    }
    alarm_pre = alarm_time[2];
  }

  // Route to all functions in ROOMM8
  if (function_called == 0 && millis() % 1000 == 0) {
    display_standby();
    if (guard_enable == 1) {
      guard();
    } else {
      position_stack[0] = 0;
      position_stack[1] = 0;
      position_stack[2] = 0;
    }
  }

  if (function_called == 1) {
    function_caller(function_id);
  }

  if (RTC.checkIfAlarm(1)) { //alarm triggered
    Serial.println("Alarm Triggered");
    game();
    lcd.clear();
  }

  // temperature
  temp = RTC.getTemperature();
  temperature(temp, arr);
  if (count<50)
  count++;
  temp_monitor();

  //Detect input
  detect_key();
  if (val[0] == 1 && val[3] == 1) {
    Serial.println("Stop!");
    function_called = 0;
    movement_stop();
    function_definder();
    if (function_called == 0) {
      display_standby();
    }
  }
}
