int LM1 = 7;      // left motor
int RM1 =  6;       // right motor

void motor_loop(int front, int left, int right)
{

 //forward
 digitalWrite(LM1, HIGH);
 digitalWrite(RM1, HIGH);

if (front < 30 && left >= 30 && right >= 30)
{
  Serial.print("Break! --> ");
  display("Break!");
  delay(1000);
  if (left > right) {
    digitalWrite(RM1, HIGH);
    digitalWrite(LM1, LOW);
    Serial.print("Left turn : ");
    display("Left turn!");
    delay(600);
  } else {
    digitalWrite(RM1, LOW);
    digitalWrite(LM1, HIGH);
    Serial.print("Right turn : ");
    display("Right turn!");
    delay(600);
  }
} else {
  //turn left
  if(right < 30)
  {
    if (front < 30) {
      digitalWrite(RM1, HIGH);
      digitalWrite(LM1, LOW);
      Serial.print("Left turn : ");
      display("Left turn!");
      delay(600);
    } else {
      digitalWrite(RM1, HIGH);
      digitalWrite(LM1, LOW);
      Serial.print("Right Avoid : ");
      display("Right Avoid!");
      delay(600);
    }

  } else {//turn right
  if(left < 30)
  {
    if (front < 30) {
      digitalWrite(RM1, LOW);
      digitalWrite(LM1, HIGH);
      Serial.print("Right turn : ");
      display("Right turn!");
      delay(600);
    } else {
      digitalWrite(RM1, LOW);
      digitalWrite(LM1, HIGH);
      Serial.print("Left Avoid:");
      display("Left Avoid!");
      delay(600);
    }
 } else {
   display("Normal");
   Serial.print("Normal : ");
 }
}
}

 Serial.print(front);
 Serial.print(" ");
 Serial.print(left);
 Serial.print(" ");
 Serial.print(right);
 Serial.println();

}
