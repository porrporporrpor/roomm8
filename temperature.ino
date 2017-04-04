void temperature(float temp, float arr[10]) {
  arr[count] = temp;
  Serial.print(temp);
  Serial.print(" : ");
  for (int i=0; i<10; i++){
    Serial.print("| arr ");
    Serial.print(arr[i]);
  }

}
