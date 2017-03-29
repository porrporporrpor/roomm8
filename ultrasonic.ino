/*
CODE HERE
Array of HC-SR04 ultrasonic sensors
*/


//Sonar 1
int echoPin1 =12;
int initPin1 =13;
int distance1 =0;

//Sonar 2
int echoPin2 =10;
int initPin2 =11;
int distance2 =0;

//Sonar 3
int echoPin3 =8;
int initPin3 =9;
int distance3 =0;


void setup() {
  
  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(initPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  distance1 = getDistance(initPin1, echoPin1);
  printDistance(1, distance1);
  delay(150);
  
  distance2 = getDistance(initPin2, echoPin2);
  printDistance(2, distance2);
  delay(150);
  
  distance3 = getDistance(initPin3, echoPin3);
  printDistance(3, distance3);
  delay(150);
  
  delay(500);
  
}

int getDistance (int initPin, int echoPin){

 digitalWrite(initPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(initPin, LOW); 
 unsigned long pulseTime = pulseIn(echoPin, HIGH); 
 int distance = pulseTime/58;
 return distance;
 
}
 
 void printDistance(int id, int dist){
  
     Serial.print(id);
    if (dist >= 250 || dist <= 0 ){
      Serial.println(" Out of range");
    }else
    for (int i = 0; i <= dist; i++) { 
         Serial.print("-");
    }
    Serial.print(dist, DEC);
    Serial.println(" cm");
    
 }
