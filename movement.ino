void movement(int front, int left, int right) {

//Front Sensor is close to some object.
if (front < space && left >= space && right >= space) {
  Serial.print("Break! --> ");
  // Which turn to use, based on distance on both side.
  if (left > right) {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    delay(100);
    Serial.print("Left turn : ");
    display_run_mode("Break!", "Go Left");
  } else {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    delay(100);
    Serial.print("Right turn : ");
    display_run_mode("Break!", "Go Right");
  }
  } else {
  //Turn Left : Right Sensor is close to some object.
  if(right < space) {
    // Front Sensor is also close too. Turn Left to avoid collision.
    if (front < space) {
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      buzzer_alarm();
      delay(100);
      Serial.print("Left turn : ");
      display_run_mode("Left turn!", "none");
    } else {
      // Front Sensor isn't close. Avoid Right.
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      buzzer_too_close();
      delay(50);
      Serial.print("Right Avoid : ");
      display_run_mode("Right Avoid!", "none");
    }

  } else {
    //Turn Right : Left Sensor is close to some object.
    if(left < space) {
      if (front < space) {
        // Front Sensor is also close too. Turn Right to avoid collision.
        digitalWrite(LM1, LOW);
        digitalWrite(LM2, HIGH);
        digitalWrite(RM1, HIGH);
        digitalWrite(RM2, LOW);
        delay(100);
        buzzer_alarm();
        Serial.print("Right turn : ");
        display_run_mode("Right turn!", "none");
      } else {
        // Front Sensor isn't close. Avoid Left.
        digitalWrite(LM1, LOW);
        digitalWrite(LM2, HIGH);
        digitalWrite(RM1, LOW);
        digitalWrite(RM2, LOW);
        buzzer_too_close();
        delay(50);
        Serial.print("Left Avoid:");
        display_run_mode("Left Avoid!", "none");
      }
    } else {
      display_run_mode("Normal", "none");
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
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

void movement_stop() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
