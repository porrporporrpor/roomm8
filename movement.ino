void movement(int front, int left, int right)
{

 //forward
 digitalWrite(LM1, HIGH);
 digitalWrite(RM1, HIGH);

if (front < 30 && left >= 30 && right >= 30)
{
  Serial.print("Break! --> ");
  if (left > right) {
    digitalWrite(RM1, HIGH);
    digitalWrite(LM1, LOW);
    Serial.print("Left turn : ");
    display_run_mode("Break!", "Go Left");
    delay(600);
  } else {
    digitalWrite(RM1, LOW);
    digitalWrite(LM1, HIGH);
    Serial.print("Right turn : ");
    display_run_mode("Break!", "Go Right");
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
      display_run_mode("Left turn!", "none");
      delay(600);
    } else {
      digitalWrite(RM1, HIGH);
      digitalWrite(LM1, LOW);
      Serial.print("Right Avoid : ");
      display_run_mode("Right Avoid!", "none");
      delay(600);
    }

  } else {//turn right
  if(left < 30)
  {
    if (front < 30) {
      digitalWrite(RM1, LOW);
      digitalWrite(LM1, HIGH);
      Serial.print("Right turn : ");
      display_run_mode("Right turn!", "none");
      delay(600);
    } else {
      digitalWrite(RM1, LOW);
      digitalWrite(LM1, HIGH);
      Serial.print("Left Avoid:");
      display_run_mode("Left Avoid!", "none");
      delay(600);
    }
 } else {
   display_run_mode("Normal", "none");
   Serial.print("Normal : ");
 }
}
}

// debug
 Serial.print(front);
 Serial.print(" ");
 Serial.print(left);
 Serial.print(" ");
 Serial.print(right);
 Serial.println();

}
