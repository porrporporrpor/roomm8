void set_alarm()
{
  int cursor_i = 0;
  display_alarm_set(alarm_time[0], alarm_time[1], alarm_time[2]);
  while (true)
  {
    detect_key();
    if (val[1] == 1)
    {
      alarm_time[cursor_i] ++;
      if (cursor_i == 0)
      {
        alarm_time[0] = hr_guard(alarm_time[0]);
      }
      else
      {
        if (cursor_i == 1)
        {
          alarm_time[1] = minu_guard(alarm_time[1]);
        }
        else
        {
          alarm_time[2] = enable_guard(alarm_time[2]);
        }
      }
      display_alarm_set(alarm_time[0], alarm_time[1], alarm_time[2]);
      delay(500);
    }
    else
    {
      if (val[2] == 1)
      {
        alarm_time[cursor_i] --;
        if (cursor_i == 0)
        {
          alarm_time[0] = hr_guard(alarm_time[0]);
        }
        else
        {
          if (cursor_i == 1)
          {
            alarm_time[1] = minu_guard(alarm_time[1]);
          }
          else
          {
            alarm_time[2] = enable_guard(alarm_time[2]);
          }
        }
        display_alarm_set(alarm_time[0], alarm_time[1], alarm_time[2]);
        delay(500);
      }
    }
    if (val[0] == 1 && val[3] == 1)
    {
      RTC.setAlarm1Simple(alarm_time[0], alarm_time[1]);
      break;
    }
    if (val[3] == 1)
    {
      cursor_i++;
      cursor_i = cursor_i_guard(cursor_i);
      delay(500);
    }
    else
    {
      if (val[0] == 1)
      {
        cursor_i--;
        cursor_i = cursor_i_guard(cursor_i);
        delay(500);
      }
    }
  }
}

int hr_guard(int hr)
{
  if (hr < 0)
  {
    hr = 23;
  }
  else
  {
    if (hr > 23)
    {
      hr = 0;
    }
  }
  return hr;
}

int cursor_i_guard(int i)
{
  if (i > 2)
  {
    i = 0;
  }
  else
  {
    if (i < 0)
    {
      i = 2;
    }
  }
  return i;
}

int minu_guard(int minu)
{
  if (minu > 59)
  {
    minu = 0;
  }
  else
  {
    if (minu < 0)
    {
      minu = 59;
    }
  }
  return minu;
}

int enable_guard(int enable)
{
  if (enable < 0)
  {
    enable = 1;
  }
  else
  {
    if (enable > 1)
    {
      enable = 0;
    }
  }
  return enable;
}

void adjust_time_function()
{
  DateTime now = RTC.now();
  adjust_time[0] = now.hour();
  adjust_time[1] = now.minute();
  int cursor_adjust = 0;
  display_adjust(adjust_time[0], adjust_time[1]);
  while(true){
    detect_key();
    if(val[1] == 1){
      adjust_time[cursor_adjust]++;
      if(cursor_adjust == 0){
        adjust_time[0] = hr_guard(adjust_time[0]);
      }
      if(cursor_adjust == 1){
        adjust_time[1] = minu_guard(adjust_time[1]);
      }
      display_adjust(adjust_time[0], adjust_time[1]);
      delay(500);
    }
    if(val[2] == 1){
      adjust_time[cursor_adjust]--;
      if(cursor_adjust == 0){
        adjust_time[0] = hr_guard(adjust_time[0]);
      }
      if(cursor_adjust == 1){
        adjust_time[1] = minu_guard(adjust_time[1]);
      }
      display_adjust(adjust_time[0], adjust_time[1]);
      delay(500);
    }
    if(val[0] == 1){
      cursor_adjust--;
      cursor_adjust = cursor_adjust_guard(cursor_adjust);
    }
    if(val[3] == 1){
      cursor_adjust++;
      cursor_adjust = cursor_adjust_guard(cursor_adjust);
    }
    if(val[0] == 1 && val[3] == 1){
      RTC.adjust(DateTime(0, 0, 0, adjust_time[0], adjust_time[1], 0));
      break;
    }
  }
}

int cursor_adjust_guard(int i)
{
  if (i > 1)
  {
    i = 0;
  }
  else
  {
    if (i < 0)
    {
      i = 1;
    }
  }
  return i;
}
