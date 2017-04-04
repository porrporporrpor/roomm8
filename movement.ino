void movement(int front, int left, int right) {

 //forward
 digitalWrite(LM1, HIGH);
 digitalWrite(RM1, HIGH);

//Front Sensor is close to some object.
if (front < 30 && left >= 30 && right >= 30) {
  Serial.print("Break! --> ");
  // Which turn to use, based on distance on both side.
  if (left > right) {
    digitalWrite(RM1, HIGH);
    digitalWrite(LM1, LOW);
    Serial.print("Left turn : ");
    display_run_mode("Break!", "Go Left");
  } else {
    digitalWrite(RM1, LOW);
    digitalWrite(LM1, HIGH);
    Serial.print("Right turn : ");
    display_run_mode("Break!", "Go Right");
  }
} else {
  //Turn Left : Right Sensor is close to some object.
  if(right < 30) {
    // Front Sensor is also close too. Turn Left to avoid collision.
    digitalWrite(RM1, HIGH);
    digitalWrite(LM1, LOW);
    if (front < 30) {
      Serial.print("Left turn : ");
      display_run_mode("Left turn!", "none");
    } else {
      // Front Sensor isn't close. Avoid Right.
      Serial.print("Right Avoid : ");
      display_run_mode("Right Avoid!", "none");
    }

  } else {
    //Turn Right : Left Sensor is close to some object.
    if(left < 30) {
      digitalWrite(RM1, LOW);
      digitalWrite(LM1, HIGH);
      if (front < 30) {
        // Front Sensor is also close too. Turn Right to avoid collision.
        Serial.print("Right turn : ");
        display_run_mode("Right turn!", "none");
      } else {
        // Front Sensor isn't close. Avoid Left.
        Serial.print("Left Avoid:");
        display_run_mode("Left Avoid!", "none");
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
