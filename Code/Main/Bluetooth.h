void bluetooth(){
    sign = Serial1.read();
    if (sign == '\n'){
      data[dataIndex] = 0;
      if(data[0]== 's'){
        unsigned int val = atof(data+2);
        servo.write(val);
      }
      dataIndex = 0;
    }else{
      data[dataIndex] = sign;
      if(dataIndex < 99)dataIndex++;
    }
}
