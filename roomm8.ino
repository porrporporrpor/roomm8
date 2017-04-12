#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SPI.h>  // not used here, but needed to prevent a RTClib compile error
#include <RTClib.h>

RTC_DS3231 RTC;

//env of project
int debug = 0;

//LCD setup
LiquidCrystal_I2C lcd(0x3F, 16, 2);

//DS3231 setup
//DS3231 rtc(SDA, SCL);
// RTC_DS3231 RTC;

//Function declaring
const int function_register = 4;
char function[function_register][10] = {"Runner", "Guard", "Alarm", "Clock"};
int function_called = 0;
int function_id = 0;

//Distance that ROOMM8 needs between object and itself (in cm).
int space = 20;
int pre_distances[3] = {0,0,0};

//Movemnet
int movement_stack = 0;

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
int RM2 = 6;      // left motor
int LM1 = 4;
int LM2 = 5;       // right motor
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

//adjust time
int adjust_time[2] = {0, 0};

void setup() {

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);

  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(initPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  //Logo Output
  display_standby();
  delay(2000);

  //rtc.begin();
  Wire.begin();
  RTC.begin();

  int time_global = millis();
  // RTC.adjust(DateTime(__DATE__, __TIME__));
  DateTime now = RTC.now();
  int second = now.second();
  randomSeed(second);
}

void loop() {

  while (debug) {
    debug_log();
  }

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


  if (function_called == 0 && millis() % 1000 == 0) {
    display_standby();
    if (guard_enable == 1) {
      guard();
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
