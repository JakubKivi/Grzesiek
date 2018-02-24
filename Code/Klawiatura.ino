void cls() {
  lcd.clear();
  lcd.home();
  lcd.print("ENTER PASSWORD:");
  lcd.setCursor(0,1); }

  void checkPassword(){
  if (password.evaluate()){

  }else{
   
  }

}

void onClick(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:                      
        lcd.print('*');         
  switch (eKey){
    case '*': checkPassword();
    break;
    case '#': password.reset(); cls(); break;
    default: password.append(eKey);
     }
  }
}


