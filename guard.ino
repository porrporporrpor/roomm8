/*Guard(main function) is the feature of ROOMM8 that keep tracking movement around itself
and warn user if there's anything uncommon.*/

void guard() {

  if (position_stack[0] == 0 && position_stack[1] == 0 && position_stack[2] == 0) {
    Serial.println("Set guard env");
    position_stack[0] = getDistance(initPin1, echoPin1);
    position_stack[1] = getDistance(initPin2, echoPin2);
    position_stack[2] = getDistance(initPin3, echoPin3);
  }

  int rt_front, rt_left, rt_right;

  rt_front = getDistance(initPin1, echoPin1);
  rt_left = getDistance(initPin2, echoPin2);
  rt_right = getDistance(initPin3, echoPin3);
  Serial.print("Guard : ");

  if (abs(rt_front - position_stack[0]) > 15 || abs(rt_left - position_stack[1]) > 15 || abs(rt_right - position_stack[2]) > 15) {
    Serial.print("Detect movement");
    if (abs(rt_front - position_stack[0]) > 15) {
      Serial.print("Front");
    }
    if (abs(rt_left - position_stack[1]) > 15) {
      Serial.print("Left");
    }
    if (abs(rt_right - position_stack[2]) > 15) {
      Serial.print("Right");
    }
    suspect++;
    sample++;
  } else {
    Serial.print("Normal");
    if (suspect != 0) {
      sample++;
    }
  }
  Serial.println();

  if (sample == 10) {
    sample = 0;
    if (suspect > 4) {
      display_guard_warning();
      movement_alert();
      buzzer_alert();
      movement_stop();
    } else {
      suspect = 0;
    }
  }

  if (suspect != 0) {
    Serial.print(suspect);
    Serial.print(" out of ");
    Serial.print(sample);
  }

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
