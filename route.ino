int function_definder() {
  int pre_function_id;

  display_menu_mode(0);

  while (true) {
    detect_key();

    pre_function_id = function_id;

    if (val[0] == 1) {
      function_id++;
      delay(500);
    } else {
      if (val[3] == 1) {
        function_id--;
        delay(500);
      }
    }

    function_id = id_guard(function_id);

    if (pre_function_id != function_id) {
      display_menu_mode(function_id);
    }

    if (val[1] == 1) {
      function_called = 1;
      break;
    }
  }
}

int id_guard (int function_id) {
  if (function_id < 0) {
    function_id = function_register-1;
  } else {
    if (function_id > function_register-1) {
      function_id = 0;
    }
  }
  return function_id;
}

//Route >> This is the gateway to all function in ROOMM8.
void function_caller(int function_id) {
  switch (function_id) {
    case 0 : movement();
    break;
    case 1 : set_alarm();
    break;
    case 2 : set_alarm();
    break;
    default : loop();
    break;
  }
}
