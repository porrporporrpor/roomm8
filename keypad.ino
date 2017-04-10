void detect_key()
{
  val[0] = analogRead(A0);
  val[1] = analogRead(A1);
  val[2] = analogRead(A2);
  val[3] = analogRead(A3);
  
  if (debug == 1) {
    for (int i =0; i<4; i++) {
      Serial.print(val[i]);
      Serial.print(" | ");
    }
    Serial.println();
  }

  for ( int i= 0; i < 4; i++ ) {
    if (val[i] < 900) {
      val[i] = 1;
    } else {
      val[i] = 0;
    }
  }

  game(val);
  
}
