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
const int function_register = 3;
char function[function_register][10] = {"Runner", "Guard", "Alarm"};
int function_called = 0;
int function_id = 0;

//Distance that ROOMM8 needs between object and itself (in cm).
int space = 10;

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
float temp = 0, arr[10];
int count = 0;
float temp_predict;

// keypad
int val[4];

//buzzer
int buzzer = 2;

//alarm
int alarm_status = 0;
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

  
//  if(!Serial){
  //  RTC.adjust(DateTime(0,0,0,adjust_time[0],adjust_time[1],0));
//  }else{
  //  RTC.adjust(DateTime(__DATE__, __TIME__));
//  }

  RTC.adjust(DateTime(__DATE__, __TIME__));
  DateTime now = RTC.now();
  int second = now.second();
  randomSeed(second);
}

void loop() {

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

  while (debug) {
    debug_log();
  }

  if (RTC.checkIfAlarm(1)) { //alarm triggered
    Serial.println("Alarm Triggered");
    game();
    delay(1000);
    Serial.println("sample text");
    lcd.clear();
    if(alarm_status == 0){
      //call game
      //call sound
      Serial.println("sample text");
    }
  }

  // temperature
  temp = RTC.getTemperature();
  temperature(temp, arr);
  if (count<9)
  count++;

  //Detect input
  detect_key();
  for (int i = 0; i < 4; i++) {
    if (val[i] == 1) {
      Serial.println("Stop!");
      function_called = 0;
      movement_stop();
      function_definder();
      if (function_called == 0) {
        display_standby();
      }
      break;
    }
  }
}
