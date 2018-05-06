void error(int number, String errorName){
    digitalWrite(PP, LOW);
    digitalWrite(PT, LOW);
    digitalWrite(LP, LOW);
    digitalWrite(LT, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ERROR ");
    lcd.print(number);
    lcd.setCursor(0, 1);
    lcd.print(errorName);   //wypisz errora
    
    for(int i=0; i<number; i++){  //zamigaj i zabrzęcz errora
      
    }
}

int survey(){

  digitalWrite(trig, HIGH);
  delayMicroseconds(1);
  digitalWrite(trig, LOW);
  
  return pulseIn(echo, HIGH)/ 58;
}



