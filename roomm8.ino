#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LCD setup
LiquidCrystal_I2C lcd(0x3F, 16, 2);

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
int LM1 = 7;      // left motor
int RM1 =  6;       // right motor


void setup() {

  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(initPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  //Logo Output
  lcd.print("-----ROOMM8-----");
  lcd.setCursor(0,1);
  lcd.print("Standby Mode");
  delay(2000);

}

void loop() {

  // Ultrasonic Get Distances
  distance_front = getDistance(initPin1, echoPin1);
  distance_left = getDistance(initPin2, echoPin2);
  distance_right = getDistance(initPin3, echoPin3);

  // send Distances to movement handle
  movement(distance_front, distance_left, distance_right);
  delay(500);

}
