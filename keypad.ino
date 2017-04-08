void detect_key()
{
  val[0] = analogRead(A0);
  val[1] = analogRead(A1);
  val[2] = analogRead(A2);
  val[3] = analogRead(A3);

  for ( int i= 0; i < 4; i++ ) {
    if (val[i] < 50) {
      val[i] = 1;
    } else {
      val[i] = 0;
    }
  }
}
