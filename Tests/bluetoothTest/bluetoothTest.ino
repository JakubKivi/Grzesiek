void setup(){
  Serial1.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}
void loop(){
  if(Serial1.read()==1) digitalWrite(13, HIGH);
}

