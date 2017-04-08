#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>

//LCD setup
LiquidCrystal_I2C lcd(0x3F, 16, 2);

//DS3231 setup
DS3231 rtc(SDA, SCL);

//Distance that ROOMM8 needs between object and itself (in cm).
int space = 60;

//Sonar Front
int echoPin1 =12;
int initPin1 =13;
int distance_front =0;

//Sonar Left
int echoPin2 =10;
int initPin2 =11;
int distance_left =0;

//Sonar Right
int echoPin3 =8;
int initPin3 =9;
int distance_right =0;

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
int buzzer = 3;

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
  lcd.print("Standby Mode");
  delay(2000);

  rtc.begin();
  function_definder();
}

void loop() {

  detect_key();

  for (int i = 0; i < 4; i++) {
    if (val[i] == 1) {
      Serial.println("Stop!");
      movement_stop();
      function_definder();
      break;
    }
  }

  // Ultrasonic Get Distances
  distance_front = getDistance(initPin1, echoPin1);
  distance_left = getDistance(initPin2, echoPin2);
  distance_right = getDistance(initPin3, echoPin3);

  // send Distances to movement handle
  movement(distance_front, distance_left, distance_right);

  // temperature
  // temp = (rtc.getTemp() - 32) / 1.8;
  temp = rtc.getTemp();
  temperature(temp, arr);
  if (count<9)
  count++;
  // game
  // game(buttonPin);
}
