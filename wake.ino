void set_alarm(){
  int hr = 0;
  int minu = 0;
  int cursor_select = 0;
  while true{
     DateTime now = RTC.now();
     //cursor[0][1]
     //cursor[0]
     if(cursor_select == 0){
      if(cursor_select == 1){
        if(val[1] == 1){
          cursor_select = 1;
        }
      if(val[1] == 1){
        hr++;
      }else{
        if(val[2] == 1){
          hr--;
        }
      }
     }else{
      if(cursor_select == 1){
        if(val[0] == 1){
          cursor_select = 0;
        }
        else
        if(val[1] == 1){
          minu++;
        }else{
          if(val[2] == 1){
            minu--;
          }
        }
      }
     }
     RTC.setAlarm1Simple(hr, minu);
    void detect_key();
    if(val[0] == 1 && val[3] == 1){
      break;
    }
  }
}

