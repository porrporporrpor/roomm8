void movement() {

  if (pre_distances[0] != 0 && pre_distances[1] != 0 && pre_distances[2] != 0) {
    front = (getDistance(initPin1, echoPin1)+pre_distances[0])/2;
    left = (getDistance(initPin2, echoPin2)+pre_distances[1])/2;
    right = (getDistance(initPin3, echoPin3)+pre_distances[2])/2;
  } else {
    front = getDistance(initPin1, echoPin1);
    left = getDistance(initPin2, echoPin2);
    right = getDistance(initPin3, echoPin3);
  }

  front = distance_guard(front);
  left = distance_guard(left);
  right = distance_guard(right);

  analogWrite(speed, 150);

  if (front < space || left < space || right < space) {
    if (front < space) { //Front side is about to reach something.
      if (left < space && right < space) { //dead end way
        digitalWrite(LM1, HIGH);
        digitalWrite(LM2, LOW);
        digitalWrite(RM1, HIGH);
        digitalWrite(RM2, LOW);
        Serial.print("Dead End");
      } else {
        if (left < space) { //Turn Right
          digitalWrite(LM1, LOW);
          digitalWrite(LM2, HIGH);
          digitalWrite(RM1, HIGH);
          digitalWrite(RM2, LOW);
          Serial.print("Collision avoid");
        } else { //Turn Left
          digitalWrite(LM1, HIGH);
          digitalWrite(LM2, LOW);
          digitalWrite(RM1, LOW);
          digitalWrite(RM2, HIGH);
          Serial.print("Collision avoid");
        }
      }
    } else { //Front is not about to reach something.
      if (left < space) { //Avoid Left side
        digitalWrite(LM1, LOW);
        digitalWrite(LM2, HIGH);
        digitalWrite(RM1, LOW);
        digitalWrite(RM2, LOW);
        Serial.print("Side avoid");
      } else {
        if (right < space) { //Avoid Right side
          digitalWrite(LM1, LOW);
          digitalWrite(LM2, LOW);
          digitalWrite(RM1, LOW);
          digitalWrite(RM2, HIGH);
          Serial.print("Side avoid");
        } else {
          digitalWrite(LM1, LOW);
          digitalWrite(LM2, HIGH);
          digitalWrite(RM1, LOW);
          digitalWrite(RM2, HIGH);
          Serial.print("Running");
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
  }

pre_distances[0] = front;
pre_distances[1] = left;
pre_distances[2] = right;

// debug
Serial.print("= Average : ");
Serial.print(front);
Serial.print(" ");
Serial.print(left);
Serial.print(" ");
Serial.print(right);
Serial.println();

delay(300);

}

void movement_stop() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void movement_guard() {
  analogWrite(speed, 50);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

int distance_guard(int distance) {
  if (distance > 300) {
    distance = 300;
  }
  return distance;
}

void movement_alert() {
  digitalWrite(speed, 230);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}
