int LM1 = 4;      // left motor
int RM1 =  5;       // right motor

void motor_loop(int front, int left, int right)
{
  Serial.print(front);
  Serial.print(" ");
  Serial.print(left);
  Serial.print(" ");
  Serial.print(right);
  Serial.println();

 //forward
 digitalWrite(LM1, HIGH);
 digitalWrite(RM1, HIGH);
 Serial.print("Forward ");

 //turn left
 if(front < 30 && right < 30)
 {
  digitalWrite(RM1, HIGH);
  digitalWrite(LM1, LOW);
  Serial.println("Left");
  delay(600);
 } else {//turn right
 if(front < 30 && left < 30)
 {
  digitalWrite(RM1, LOW);
  digitalWrite(LM1, HIGH);
  Serial.println("Right");
  delay(600);
 }
 }
 
}

