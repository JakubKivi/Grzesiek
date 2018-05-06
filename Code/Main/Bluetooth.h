void exeBluetooth(){
    if(data[0]== 's' && data[1]== 'e' && 
       data[2]== 'r' && data[3]== 'v' &&
       data[4]== 'o'){
      unsigned int val = atof(data+6);
      servo.write(val);
    }
    if(data[0]== 'f' && data[1]== 'l'){
      if(!FL){FL=1; digitalWrite(lLP, HIGH);}
      else{FL=0; digitalWrite(lLP, LOW);};
    }
    if(data[0]== 'f' && data[1]== 'r'){
      if(!FR){FR=1; digitalWrite(lPP, HIGH);}
      else{FR=0; digitalWrite(lPP, LOW);};
    }
    if(data[0]== 'b' && data[1]== 'l'){
      if(!BL){BL=1; digitalWrite(lLT, HIGH);}
      else{BL=0; digitalWrite(lLT, LOW);};
    }
    if(data[0]== 'b' && data[1]== 'r'){
      if(!BR){BR=1; digitalWrite(lPT, HIGH);}
      else{BR=0; digitalWrite(lPT, LOW);};
    }
}

void bluetooth(){
    sign = Serial1.read();
    if (sign == '\n'){
      data[dataIndex] = 0;
      exeBluetooth();
      dataIndex = 0;
    }else{
      data[dataIndex] = sign;
      if(dataIndex < 99)dataIndex++;
    }
}
