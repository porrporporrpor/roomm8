void game() {
  int n = 4, arrow, input, count=0, i;
  int arr[4], number[4];
  int getIn = 0;
  int time_stack = millis();
  int keypress = 0;
  arrow_generator(i, n, arrow, arr);

  while (true) {
    detect_key();

    if (keypress == 0) {
      buzzer_wakeup();
      movement();
      if (val[0] == 1 || val[1] == 1 || val[2] == 1 || val[3] == 1) {
        movement_stop();
        keypress = 1;
      }
    } else {

      if (millis()%time_stack > 1000) {
        buzzer_wakeup();
      }

      if (val[0] == 1 && val[1] == 0 && val[2] == 0 && val[3] == 0) {
        number[getIn] = 0;
        display_game(0);
        getIn++;
        delay(500);
      }
      if (val[0] == 0 && val[1] == 1 && val[2] == 0 && val[3] == 0) {
        number[getIn] = 1;
        display_game(1);
        getIn++;
        delay(500);
      }
      if (val[0] == 0 && val[1] == 0 && val[2] == 1 && val[3] == 0) {
        number[getIn] = 2;
        display_game(2);
        getIn++;
        delay(500);
      }
      if (val[0] == 0 && val[1] == 0 && val[2] == 0 && val[3] == 1) {
        number[getIn] = 3;
        display_game(3);
        getIn++;
        delay(500);
      }

      if (getIn == 4) {
        for (i=0; i<n; i++) {
          if (number[i] != arr[i]) {
            Serial.print("try again!\n");
            display_game_fail();
            arrow_generator(i, n, arrow, arr);
            getIn = 0;
            count = 1;
            int arr[4], number[4];
            break;
          }
        }
        if (count != 1) {
          Serial.print("you're done\n");
          buzzer_stop();
          display_game_success();
          alarm_time[2] = 0;
          break;
        }
        count = 0;
      }
    }
  }
}

void arrow_generator(int i, int n, int arrow, int arr[4]) {
  lcd.clear();
  lcd.print("Wake! :");
  // random arrow
  for (i=0; i<n; i++) {
    arrow = random(4);
    arr[i] = arrow;
    if (arrow == 1) {
      Serial.print("^ ");
      lcd.print("^ ");
    } else {
      if (arrow == 2) {
        Serial.print("v ");
        lcd.print("v ");
      } else {
        if (arrow == 0) {
          Serial.print("< ");
          lcd.print("< ");
        } else {
          Serial.print("> ");
          lcd.print("> ");
        }
      }
    }
  }
  lcd.setCursor(0,1);
}
