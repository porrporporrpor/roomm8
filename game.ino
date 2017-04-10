void game(int val[4]) {
    int n = 4, arrow, input, count=0, i;
    int arr[4], number[4];
    // random arrow
    for (i=0; i<n; i++)
    {
        arrow = random(4);
        arr[i] = arrow;
        if (arrow == 0)
            Serial.print("^ ");
        else if (arrow == 1)
            Serial.print("v ");
        else if (arrow == 2)
            Serial.print("< ");
        else 
            Serial.print("> ");
    }

    for (i=0; i<n; i++)
    {
        if (val[i] == 1 && val[i] == 0 && val[i] == 0 && val[i] == 0)
           number[i] = 0;
        if (val[i] == 0 && val[i] == 1 && val[i] == 0 && val[i] == 0)
           number[i] = 1;
        if (val[i] == 0 && val[i] == 0 && val[i] == 1 && val[i] == 0)
           number[i] = 2;
        if (val[i] == 0 && val[i] == 0 && val[i] == 0 && val[i] == 1)
           number[i] = 3;
    }
       
    for (i=0; i<n; i++)
    {
        if (number[i] != arr[i])
        {
            Serial.print("try again!\n");
            count = 1;
            break;
        }
    }
    if (count != 1)
    {
        Serial.print("you done\n");
        buzzer_stop();
    }
}
