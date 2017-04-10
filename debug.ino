void debug_log() {
  detect_key();
  Serial.println("Keypad Debug");
  Serial.print(val[0]);
  Serial.print(" ");
  Serial.print(val[1]);
  Serial.print(" ");
  Serial.print(val[2]);
  Serial.print(" ");
  Serial.print(val[3]);
  Serial.println();
  delay(500);
}
