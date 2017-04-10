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
void display_time_mode(){
  DateTime now = RTC.now();
  lcd.print("Time : ");
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
}

void display_alarm_set(int hr, int minu, int enable){
  lcd.clear();
  lcd.print("Alarm:");
  lcd.setCursor(0,1);
  lcd.print(hr);
  lcd.print(":");
  lcd.print(minu);
  lcd.print(" >> ");
  if (enable == 1) {
    lcd.print("ON");
  } else {
    lcd.print("OFF");
  }
}

