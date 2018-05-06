void logClear(){
  Serial1.write("log  \n");
  Serial1.write("log  \n");
  Serial1.write("log  \n");
  Serial1.write("log  \n");
  Serial1.write("log  \n");
  Serial1.write("log  \n");
}

void exeBluetooth(){
    if(data[0]== 'c' && data[1]== 'o' && 
       data[2]== 'n' && data[3]== 'n' &&
       data[4]== 'e' && data[5]== 'c' && 
       data[6]== 't'){
       logClear();
       Serial1.write("log \t\t\t\tGrzesiek Robot v2.2\n");
       Serial1.write("log \t\t\t\t\t\tConnected\n");
       Serial1.write("log \t\t\t\t\tEnter Password\n");
       remote=1;
    }

        if(data[0]== 's' && data[1]== 'e' && 
           data[2]== 'r' && data[3]== 'v' &&
           data[4]== 'o'){
           if(RPassword){
              unsigned int val = atof(data+6);
              servo.write(val);
           }else{
              logClear();
              Serial1.write("log \t\t\t\t\tEnter Password\n");
              Serial1.write("vib\n");
           }
        }
        if(data[0]== 'f' && data[1]== 'l'){
            if(RPassword){
              if(!FL){FL=1; digitalWrite(lLP, HIGH);}
              else{FL=0; digitalWrite(lLP, LOW);}
            }else{
              logClear();
              Serial1.write("log \t\t\t\t\tEnter Password\n");
              Serial1.write("vib\n");
            }
        }
        if(data[0]== 'f' && data[1]== 'r'){
            if(RPassword){  
              if(!FR){FR=1; digitalWrite(lPP, HIGH);}
              else{FR=0; digitalWrite(lPP, LOW);}
            }else{
              logClear();
              Serial1.write("log \t\t\t\t\tEnter Password\n");
              Serial1.write("vib\n");
            }
        }
        if(data[0]== 'b' && data[1]== 'l'){
            if(RPassword){
              if(!BL){BL=1; digitalWrite(lLT, HIGH);}
              else{BL=0; digitalWrite(lLT, LOW);}
            }else{
              logClear();
              Serial1.write("log \t\t\t\t\tEnter Password\n");
              Serial1.write("vib\n");
            }
        }
        if(data[0]== 'b' && data[1]== 'r'){
            if(RPassword){
              if(!BR){BR=1; digitalWrite(lPT, HIGH);}
              else{BR=0; digitalWrite(lPT, LOW);}
            }else{
              logClear();
              Serial1.write("log \t\t\t\t\tEnter Password\n");
              Serial1.write("vib\n");
            }
        }
    

    if(data[0]== 'c' && data[1]== 'o' && 
       data[2]== 'n'&& data[3]== ' '){
           if(data[4]== '1' &&
           data[5]== '3' && data[6]== '3' && 
           data[7]== '7'){
           RPassword=1;
           logClear();
           Serial1.write("log \t\t\t\t\tPassword correct\n");
           }else{
             logClear();
             Serial1.write("log \t\t\t\tPassword incorrect\n");
             Serial1.write("vib\n");
           }
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
