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
