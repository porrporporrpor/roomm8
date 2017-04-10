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

  front = getDistance(initPin1, echoPin1);
  left = getDistance(initPin2, echoPin2);
  right = getDistance(initPin3, echoPin3);
  Serial.print(" : ");
  Serial.print(front);
  Serial.print(" ");
  Serial.print(left);
  Serial.print(" ");
  Serial.print(right);
  Serial.println();

  delay(450);
}
