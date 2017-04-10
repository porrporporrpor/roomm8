void set_alarm(){
  int alarm_time[2] = {0, 0};
  int cursor_i = 0;
     while(true){
      detect_key();
      RTC.setAlarm1Simple(alarm_time[0], alarm_time[1]);
      
      if (val[1] == 1) {
        alarm_time[cursor_i]++;
        if(cursor_i == 0){
         alarm_time[0] = hr_guard (alarm_time[0]);
      }else{
        if(cursor_i == 1){
          alarm_time[1] = minu_guard(alarm_time[1]);
        }
      }
      
        display_num(alarm_time[0], alarm_time[0]);
        delay(500);
      } else {
        if (val[2] == 1) {
          alarm_time[cursor_i]--;
          if(cursor_i == 0){
        alarm_time[0] = hr_guard (alarm_time[0]);
      }else{
        if(cursor_i == 1){
          alarm_time[1] = minu_guard(alarm_time[1]);
        }
      }
          display_num(alarm_time[0], alarm_time[1]);
        }
      }
     if(val[3] == 1){
          cursor_i++;
          cursor_i_guard(cursor_i);
        }
        else{
          if(val[0] == 1){
            cursor_i--;
            cursor_i_guard(cursor_i);
          }
     }
  }
}

int hr_guard (int hr) {
  if (hr < 0) {
    hr = 23;
  } else {
    if (hr > 23) {
      hr = 0;
    }
  }
  return hr;
}

int cursor_i_guard(int i){
  if(i > 1){
    i = 0;
  }else{
    if(i < 0){
      i = 1;
    }
  }
  return i;
}

int minu_guard(int minu){
  if(minu > 59){
    minu = 0;
  }else{
    if(minu < 0){
      minu = 59;
    }
  }
  return minu;
}

