void temperature(float temp, float arr[N]) {
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
    *(&count) = 2;
  }

}

// This loop will sol linearforcast

void linearforcast(float arr[N])
{
    int i;
    float total = 0;

    //This loop for sol
    for (i = 0; i < 3; i++)
    {
        total += arr[i];
    }

    Serial.println(total/N);
}
