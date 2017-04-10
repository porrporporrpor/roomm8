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
char function[function_register][10] = {"Runner", "Clock", "Alarm", "Standby"};
int function_called = 0;
int function_id = 0;

//Distance that ROOMM8 needs between object and itself (in cm).
int space = 30;

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

// temperature
float temp = 0, arr[10];
int count = 0;

// keypad
int val[4];

//buzzer
int buzzer = 2;

//alarm  status
int alarm_status = 0;

//int for count
int round_count = 0;
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
  lcd.print("-----ROOMM8-----");
  lcd.setCursor(0,1);
  delay(2000);

  //rtc.begin();
  Wire.begin();
  RTC.begin();

  RTC.adjust(DateTime(__DATE__, __TIME__));
}

void loop() {

  while (debug) {
    debug_log();
  }
  if (RTC.checkAlarmEnabled(1)) {
    Serial.println("Alarm Enabled");
  }

  if (RTC.checkIfAlarm(1)) { //alarm triggered
    Serial.println("Alarm Triggered");
    buzzer_wakeup();
    //call game
    //call sound
    delay(1000);
    Serial.println("sample text");
    lcd.clear();
    if(alarm_status == 0){
      //call game
      //call sound
      Serial.println("sample text");
    }
  }


  if (!function_called) {
    Serial.println("Function has not been set up!");
    delay(1000);
    function_definder();
  } else {

    function_caller(function_id);

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
        movement_stop();
        function_called = 0;
        break;
      }
    }
  }
  round_count++;
  if(round_count <= 1000){
    round_count = 0;
  }
}
