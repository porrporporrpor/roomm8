void display_run_mode(char text[16], char status[16])
{
  lcd.clear();
	lcd.print(text);
  if (status != "none") {
    lcd.setCursor(0,1);
    lcd.print("=>");
    lcd.print(status);
  }
}
