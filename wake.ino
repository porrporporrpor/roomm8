int RTC_and_Alarm(){
  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__));
  int hr = 0;
  int minu = 0; //minute
  int alarm_hr = 0;
  int alarm_minu = 0;
  int out_alarm = 0;

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
 
  //set clock
  DateTime now = RTC.now();
  RTC.setAlarm1Simple(hr, minu);
  display_time_mode(hr, minu);

  //set alarm
  RTC.turnOnAlarm(1); //enable alarm mode
  RTC.setAlarm1Simple(alarm_hr, alarm_minu);
  display_time_mode(alarm_hr, alarm_minu);
  if (RTC.checkIfAlarm(1)) {
   Serial.println("Please wake up");
   delay(1000);
   lcd.clear();
   //Insert game function(if pass; return out_alarm = 1)
   //Insert sound function
   //if(out_alarm == 0){
   // call game function
   // call sound function
   //}else{
   //  serial.println("success");
   //}
   }
}

