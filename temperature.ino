void temperature(float temp, float arr[10]) {
  int i, j;
  arr[count] = temp;
  if (count == 9) {
    // uncommnet when complete linearforcast function
    linearRegression(arr);

    // sorting
    for (i=1, j=0; j<10; i++,j++) {
      arr[j] = arr[i];
    }

  }
  for (int k = 0; k<10; k++) {
    Serial.print(arr[k]);
    Serial.print(" | ");
  }
}

// This loop will sol linearforcast

void linearRegression(float arr[10])
{
  Serial.print("temperature will be at ");
  int i, n=1;
  float sumx, sumxsq, sumy, sumxy, a0, a1, denom;
  sumx = 0;
  sumxsq = 0;
  sumy = 0;
  sumxy = 0;
  for(i = 0; i < 10; i++) {
    sumx += n;
    sumxsq += pow(n, 2);
    sumy += arr[i];
    sumxy += n * arr[i];
    n++;
  }
  denom = 10 * sumxsq - pow(sumx, 2);
  a0 = (sumy * sumxsq - sumx * sumxy) / denom;
  a1 = (10 * sumxy - sumx * sumy) / denom;
  Serial.print((a1*50)+a0);
  Serial.print(" >> ");
}
