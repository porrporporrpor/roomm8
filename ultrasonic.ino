// #define trigPin1 9
// #define echoPin1 8
// #define trigPin2 11
// #define echoPin2 10
#define trigPin3 13
#define echoPin3 12
long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;
void setup() {
  Serial.begin (9600);
  // pinMode(trigPin1, OUTPUT);
  // pinMode(echoPin1, INPUT);
  // pinMode(trigPin2, OUTPUT);
  // pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  // SonarSensor(trigPin1, echoPin1);
  // RightSensor = distance;
  // SonarSensor(trigPin2, echoPin2);
  // LeftSensor = distance;
  SonarSensor(trigPin3, echoPin3);
  FrontSensor = distance;
  // Serial.print(LeftSensor);
  // Serial.print(" - ");
  Serial.print(FrontSensor);
  Serial.print(" - ");
  Serial.println();
  // Serial.println(RightSensor);
  delay(200);
}
void SonarSensor(int trigPin,int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
}
