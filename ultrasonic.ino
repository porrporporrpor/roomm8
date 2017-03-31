int distance_front;
int distance_left;
int distance_right;

//Sonar Front
int echoPin1 =12;
int initPin1 =13;
int distance1 =0;

//Sonar Left
int echoPin2 =10;
int initPin2 =11;
int distance2 =0;

//Sonar Right
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
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);

  lcd.begin();
  lcd.backlight();

  Serial.begin(9600);

}

void loop() {

  distance1 = getDistance(initPin1, echoPin1);
  distance_front = printDistance(1, distance1);

  distance2 = getDistance(initPin2, echoPin2);
  distance_left = printDistance(2, distance2);

  distance3 = getDistance(initPin3, echoPin3);
  distance_right = printDistance(3, distance3);

  motor_loop(distance_front, distance_left, distance_right);

}

int getDistance (int initPin, int echoPin){

 digitalWrite(initPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(initPin, LOW);
 unsigned long pulseTime = pulseIn(echoPin, HIGH);
 int distance = pulseTime/58;
 return distance;

}

 int printDistance(int id, int dist){

//     Serial.print(id);
    if (dist >= 250 || dist <= 0 ){
//      Serial.println(" Out of range");
    }else
    for (int i = 0; i <= dist; i++) {
//         Serial.print("-");
    }
//    Serial.print(dist, DEC);
//    Serial.println(" cm");
    return dist;

 }
