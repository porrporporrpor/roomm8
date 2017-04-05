//int j = 1; // integer used in scanning the array designating column number
////2-dimensional array for asigning the buttons and there high and low values
//int Button[5][3] = {{1, 837, 838}, // button 1 - up
//                    {2, 737, 738}, // button 2 - down
//                    {3, 610, 611}, // button 3 - left
//                    {4, 318, 319}, // button 4 - right
//int analogpin = 3; // analog pin to read the buttons
//int label = 0;  // for reporting the button label
//int counter = 0; // how many times we have seen new value
//long time = 0;  // the last time the output pin was sampled
//int debounce_count = 50; // number of millis/samples to consider before declaring a debounced input
//int current_state = 0;  // the debounced input value
//int ButtonVal[5], arrow_check;
//
//void game()
//{
//  // If we have gone on to the next millisecond
// if (millis() != time)
// {
//   // check analog pin for the button value and save it to ButtonVal
//   ButtonVal = analogRead(buttonPin);
//   if(ButtonVal == current_state && counter >0)
//   { 
//     counter--;
//   }
//   if(ButtonVal != current_state)
//   {
//     counter++;
//   }
//   // If ButtonVal has shown the same value for long enough let's switch it
//   if (counter >= debounce_count)
//   {
//     counter = 0;
//     current_state = ButtonVal;
//     //Checks which button or button combo has been pressed
//     if (ButtonVal > 0)
//     {
//       ButtonCheck();
//     }
//   }
//   time = millis();
// }
//}
//
//void ButtonCheck()
//{
// // loop for scanning the button array.
// for(int i = 0; i <= 21; i++)
// {
//   // checks the ButtonVal against the high and low vales in the array
//   if(ButtonVal >= Button[i][j] && ButtonVal <= Button[i][j+1])
//   {
//     // stores the button number to a variable
//     label = Button[i][0];
//     Action();      
//   }
// }
//}
//
//void randomArrow(int buttonArrow, int index) {
//  randomNumber = random(1, 4);
//  switch(randomNumber) {
//    case 1 :
//      Serial.print("^ ");
//      buttonArrow[index] = 'W';
//      break;
//    case 2 :
//      Serial.print("v ");
//      buttonArrow[index] = 'S';
//      break;
//    case 3 :
//      Serial.print("< ");
//      arrow_check = 3;
//      buttonArrow[index] = 'A';
//      break;
//    case 4 :
//      Serial.print("> ");
//      arrow_check = 4;
//      buttonArrow[index] = 'D';
//      break;
//    default :
//      printf("Invalid Random\n" );
//  }
//}
//
//void inputButton(int buttonPin, int level) {
//  for (int i=1; i<=level; ++i) {
//    for (int j=0; j<i; ++j) {
//      randomArrow();
//      index++;
//    }
//    for (int k=0; k<i; ++k)
//      buttonVal[k] = analogRead(buttonPin);
//  }
//
//  // check input is match in display
//  for (int i=0; i<level; ++i) {
//  
//  }  
//
//}
//      
// //Serial.println("Button =:");
// //Serial.println(label);
// //delay(200);
// 
// 
//}
//

