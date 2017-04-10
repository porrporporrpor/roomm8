void guard() {
  front = getDistance(initPin1, echoPin1);
  left = getDistance(initPin2, echoPin2);
  right = getDistance(initPin3, echoPin3);

  int rt_front, rt_left, rt_right;

  rt_front = getDistance(initPin1, echoPin1);
  rt_left = getDistance(initPin2, echoPin2);
  rt_right = getDistance(initPin3, echoPin3);

  if (rt_front - front > 15 || rt_left - left > 15 || rt_right - right > 15) {
    Serial.println("Detect movement");
    Serial.print(" : ");
    Serial.print(front);
    Serial.print(" ");
    Serial.print(left);
    Serial.print(" ");
    Serial.print(right);
    Serial.println();
    suspect++;
  }

  if (sample == 10) {
    sample = 0;
    if (suspect > 6) {
      buzzer_alert();
    } else {
      suspect = 0;
    }
  }

  sample++;
}

void guard_setup() {
  display_guard_set(guard_enable);
  while (true) {
    detect_key();
    if (val[1] == 1) {
      guard_enable++;
      guard_enable = enable_guard(guard_enable);
      display_guard_set(guard_enable);
      delay(500);
    } else {
      if (val[2] == 1) {
        guard_enable--;
        guard_enable = enable_guard(guard_enable);
        display_guard_set(guard_enable);
        delay(500);
      }
    }

    if (val[0] == 1 && val[3] == 1) {
      break;
    }

  }
}
