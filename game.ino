void game() {
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

    // print check arr[i]
    // for (int i=0; i<n; i++)
       // printf("%d ", arr[i]);
    // printf("<-- arr\n");

    // input to number array
    for (int i=0; i<n; i++)
    {
        scanf("%d", &input);
        number[i] = input;
    }

    // print check number[i]
    // for (int i=0; i<n; i++)
        // printf("%d " , number[i]);
    // printf("<-- number\n");

    for (int i=0; i<n; i++)
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
        // stop buzzer alarm function
    }
}
