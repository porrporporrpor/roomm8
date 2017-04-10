void display_run_mode(char text[16], char status[16]) {
  lcd.clear();
  lcd.print(text);
  if (status != "none") {
    lcd.setCursor(0,1);
    lcd.print("=>");
    lcd.print(status);
  }
}
void display_menu_mode(int point) {
  lcd.clear();
  lcd.print("-----ROOMM8-----");
  lcd.setCursor(0,1);
  lcd.print("Menu : ");
  lcd.setCursor(7,1);
  lcd.print(function[point]);
}
void display_standby(){
  lcd.clear();
  lcd.print("-----ROOMM8-----");
  lcd.setCursor(0,1);
  DateTime now = RTC.now();
  leading_zero(now.hour());
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  leading_zero(now.minute());
  lcd.print(now.minute(), DEC);
  lcd.print(" >> ");
  lcd.print(RTC.getTemperature());
  lcd.print(char(223));
  lcd.print("C");
}

void display_alarm_set(int hr, int minu, int enable){
  lcd.clear();
  lcd.print("Alarm:");
  lcd.setCursor(0,1);
  leading_zero(hr);
  lcd.print(hr);
  lcd.print(":");
  leading_zero(minu);
  lcd.print(minu);
  lcd.print(" >> ");
  if (enable == 1) {
    lcd.print("ON");
  } else {
    lcd.print("OFF");
  }
}

void display_guard_set(int guard){
  lcd.clear();
  lcd.print("-----ROOMM8-----");
  lcd.setCursor(0,1);
  lcd.print("Guard: ");
  if (guard == 1) {
    lcd.print("ON");
  } else {
    lcd.print("OFF");
  }
}

//Helping function
void leading_zero(int number) {
  if (number < 10) {
    lcd.print("0");
  }
}
