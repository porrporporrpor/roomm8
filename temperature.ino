void temperature(float temp, float arr[50]) {
  int i, j;
  arr[count] = temp;
  if (count == 49) {
    // uncommnet when complete linearforcast function
    linearRegression(arr);

    // sorting
    for (i=1, j=0; j<50; i++,j++) {
      arr[j] = arr[i];
    }

  }
}

// This loop will sol linearforcast

void linearRegression(float arr[50])
{
  int i, n=1;
  float sumx, sumxsq, sumy, sumxy, a0, a1, denom;
  sumx = 0;
  sumxsq = 0;
  sumy = 0;
  sumxy = 0;
  for(i = 0; i < 50; i++) {
    sumx += n;
    sumxsq += pow(n, 2);
    sumy += arr[i];
    sumxy += n * arr[i];
    n++;
  }
  denom = 50 * sumxsq - pow(sumx, 2);
  a0 = (sumy * sumxsq - sumx * sumxy) / denom;
  a1 = (50 * sumxy - sumx * sumy) / denom;
  temp_predict = (a1*50)+a0;
}

void temp_monitor() {
  if (temp_predict > 40) {
    Serial.println("Temperature notices some dramatically change!");
    display_temp_mode();
    buzzer_alert();
    delay(3000);
  }
}
