void movement() {

  front = getDistance(initPin1, echoPin1);
  left = getDistance(initPin2, echoPin2);
  right = getDistance(initPin3, echoPin3);

  analogWrite(speed, 70);

  if (front < space || left < space || right < space) {
    if (front < space) { //Front side is about to reach something.
      if (left < space && right < space) { //dead end way
        digitalWrite(LM1, HIGH);
        digitalWrite(LM2, LOW);
        digitalWrite(RM1, HIGH);
        digitalWrite(RM2, LOW);
        Serial.print("Dead End");
        display_run_mode("Break!", "Reverse");
      } else {
        if (left < space) { //Turn Right
          digitalWrite(LM1, LOW);
          digitalWrite(LM2, HIGH);
          digitalWrite(RM1, HIGH);
          digitalWrite(RM2, LOW);
          Serial.print("Collision avoid");
          display_run_mode("Break!", "Go Right");
        } else { //Turn Left
          digitalWrite(LM1, HIGH);
          digitalWrite(LM2, LOW);
          digitalWrite(RM1, LOW);
          digitalWrite(RM2, HIGH);
          Serial.print("Collision avoid");
          display_run_mode("Break!", "Go Left");
        }
      }
    } else { //Front is not about to reach something.
      if (left < space) { //Avoid Left side
        digitalWrite(LM1, LOW);
        digitalWrite(LM2, HIGH);
        digitalWrite(RM1, LOW);
        digitalWrite(RM2, LOW);
        Serial.print("Side avoid");
        display_run_mode(">>>>>>>>>>>>>>>>", "none");
      } else {
        if (right < space) { //Avoid Right side
          digitalWrite(LM1, LOW);
          digitalWrite(LM2, LOW);
          digitalWrite(RM1, LOW);
          digitalWrite(RM2, HIGH);
          Serial.print("Side avoid");
          display_run_mode("<<<<<<<<<<<<<<<<", "none");
        } else {
          digitalWrite(LM1, LOW);
          digitalWrite(LM2, HIGH);
          digitalWrite(RM1, LOW);
          digitalWrite(RM2, HIGH);
          Serial.print("Running");
          display_run_mode("^^^^^^^^^^^^^^^^", "none");
        }
      }
    }
  } else {
    //Keep straight forward
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    Serial.print("Running");
    display_run_mode("^^^^^^^^^^^^^^^^", "none");
  }

  // debug
  Serial.print(" : ");
  Serial.print(front);
  Serial.print(" ");
  Serial.print(left);
  Serial.print(" ");
  Serial.print(right);
  Serial.println();
  delay(200);

}

void movement_stop() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
