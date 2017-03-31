int LM1 = 7;      // left motor
int RM1 =  6;       // right motor

void motor_loop(int front, int left, int right)
{

 //forward
 digitalWrite(LM1, HIGH);
 digitalWrite(RM1, HIGH);

 //turn left
 if(front < 30 && right < 30)
 {
  digitalWrite(RM1, HIGH);
  digitalWrite(LM1, LOW);
  Serial.print("Left Avoid:");
  display("Left Avoid!");
  delay(600);
 } else {//turn right
 if(front < 30 && left < 30)
 {
  digitalWrite(RM1, LOW);
  digitalWrite(LM1, HIGH);
  Serial.print("Right Avoid:");
  display("Right Avoid!");
  delay(600);
} else {
  display("Normal");
}
 }

 Serial.print(front);
 Serial.print(" ");
 Serial.print(left);
 Serial.print(" ");
 Serial.print(right);
 Serial.println();

}
