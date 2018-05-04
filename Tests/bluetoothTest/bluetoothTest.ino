#include <Servo.h>

char data[100];
byte dataIndex;
char sign;

Servo servo;

void setup() {
  Serial1.begin(9600);
  servo.attach(11);
}

void exeData(){
  if(data[0]== 's'){
    unsigned int val = atof(data+2);
    servo.write(val);
  }
}

void loop() {
  if(Serial1.available() > 0){
    sign = Serial1.read();
    if (sign == '\n'){
      data[dataIndex] = 0;
      exeData();
      dataIndex = 0;
    }else{
      data[dataIndex] = sign;
      if(dataIndex < 99)dataIndex++;
    }
  }
  

}
