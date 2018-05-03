void setup(){
  pinMode(53, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(33, OUTPUT);
  
  
  digitalWrite(53, LOW);
  digitalWrite(51, HIGH);
  digitalWrite(49, LOW);
  digitalWrite(47, HIGH);
  
  digitalWrite(45, LOW);
  digitalWrite(43, HIGH);
  digitalWrite(41, HIGH);
  
  digitalWrite(39, LOW);
  digitalWrite(37, HIGH);
  digitalWrite(35, LOW);
  digitalWrite(33, HIGH);
}
void loop(){}
