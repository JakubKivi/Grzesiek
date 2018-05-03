#include <Servo.h>

Servo kappa; //pozdrawiam Welter

void setup() {
  kappa.attach(11);  
}

void loop() {
  for (int i = 0; i <= 180; i++) {
    kappa.write(i);
    delay(20);
  }
  delay(1000);
  for (int i = 180; i >= 0; i--) {
    kappa.write(i);
    delay(20);
  }
  delay(1000);
}
