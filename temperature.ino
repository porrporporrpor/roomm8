void temperature(float temp, float arr[2]) {
  int i, j;
  arr[count] = temp;
  if (count == 2) {
    // uncommnet when complete linearforcast function
    // linearforcast(arr);

    // sorting
    arr[0] = arr[1];
    arr[1] = arr[2];
  }
}

//// This loop will sol linearforcast
//
//void linearforcast(float arr[N])
//{
//    int i;
//    float total = 0;
//
//    //This loop for sol
//    for (i = 0; i < 3; i++)
//    {
//        total += arr[i];
//    }
//
//    Serial.println(total/N);
//}
