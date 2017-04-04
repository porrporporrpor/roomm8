void temperature(float temp, float arr[10]) {
  int i, j;
  arr[count] = temp;
  Serial.print(temp);
  Serial.print(" : ");
  if (count == N) {
    // uncommnet when complete linearforcast function
    //linearforcast(arr);

    // sorting
    for (i=0; i<N; ++i)
      for (j=0; j<N-1; ++j)
        arr[j+1] = arr[j];
    *(&count) = 1;
  }

}
