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

  analogWrite(speed, 80);

  if (front < space || left < space || right < space) {
    if (front < space) { //Front side is about to reach something.
      if (left < space && right < space) { //dead end way
        digitalWrite(LM1, HIGH);
        digitalWrite(LM2, LOW);
        digitalWrite(RM1, HIGH);
        digitalWrite(RM2, LOW);
        Serial.print("Dead End");
        movement_stack[1] = 1;
      } else {
        if (left < space) { //Turn Right
          digitalWrite(LM1, LOW);
          digitalWrite(LM2, HIGH);
          digitalWrite(RM1, HIGH);
          digitalWrite(RM2, LOW);
          Serial.print("Collision avoid");
          movement_stack[1] = 2;
        } else { //Turn Left
          digitalWrite(LM1, HIGH);
          digitalWrite(LM2, LOW);
          digitalWrite(RM1, LOW);
          digitalWrite(RM2, HIGH);
          Serial.print("Collision avoid");
          movement_stack[1] = 3;
        }
      }
    } else { //Front is not about to reach something.
      if (left < space) { //Avoid Left side
        digitalWrite(LM1, LOW);
        digitalWrite(LM2, HIGH);
        digitalWrite(RM1, LOW);
        digitalWrite(RM2, LOW);
        Serial.print("Side avoid");
        movement_stack[1] = 4;

      } else {
        if (right < space) { //Avoid Right side
          digitalWrite(LM1, LOW);
          digitalWrite(LM2, LOW);
          digitalWrite(RM1, LOW);
          digitalWrite(RM2, HIGH);
          Serial.print("Side avoid");
          movement_stack[1] = 5;

        } else {
          digitalWrite(LM1, LOW);
          digitalWrite(LM2, HIGH);
          digitalWrite(RM1, LOW);
          digitalWrite(RM2, HIGH);
          Serial.print("Running");
          movement_stack[1] = 0;
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
    movement_stack[1] = 0;
  }

  /*Movement stack is here to prevent any loop of turning by checking if ROOMM8
  use too many same turn function.
  0. Normal >> always allow.
  1. Dead End
  2. Collision Avoid -> left turn
  3 Collision Avoid -> Right turn
  4. Side Avoid -> Left side
  5. Side Avoid -> Right side
  */

  if (movement_stack[0] == movement_stack[1] && movement_stack[1] != 0) {
    Serial.print(" << same turn I used to move.");
    if (movement_stack[2] >= 5) {
      Serial.print(" -> too many times!");
      movement_stack[2] = 0;
      movement_stack[0] = 0;
      movement_stop();
      delay(500);
      movement_search();
      movement_stop();
      delay(1000);
    } else {
      Serial.print(" << count this move.");
      movement_stack[2]++;
    }
  } else {
    Serial.print(" << new move or allow this move to repeat.");
    if (movement_stack[1] == 0) {
      movement_stack[0] = 0;
      movement_stack[2] = 0;
    } else {
      movement_stack[0] = movement_stack[1];
    }
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

void movement_alert() {
  digitalWrite(speed, 230);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void movement_search() {
  digitalWrite(speed, 70);
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  delay(1500);
}

int distance_guard(int distance) {
  if (distance > 150) {
    distance = 150;
  }
  return distance;
}
