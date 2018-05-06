void local(){
    if(remote){
        lcd.setCursor(0, 0);
        lcd.print(" Remote control");
        lcd.setCursor(0, 1);
        lcd.print(" Disconnect - #");
    }else{}
}

