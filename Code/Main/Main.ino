#include "Header.h"

void setup() {
    Setup;
}
void loop() {  
    if(Serial1.available() > 0) bluetooth;
    else local;
}
