#include <Password.h>         //biblioteka do haseł 
#include <Keypad.h>           //biblioteka do klawiatury
#include <LiquidCrystal.h>    //biblioteka do wyświetlacza
#include <Servo.h>            //biblioteka do serwa

#define zblizeniowy 1       //czujnik zbliżeniowy
#define triger      2
#define echo        3       //trigger i echo do czujnika dźwiękowego
#define PP          4
#define PT          5
#define LP          6
#define LT          7
#define SPEEDP      8
#define SPEEDL      9
#define LIGHTP      10
#define LIGHTL      11
#define tLIGHTP     12
#define tLIGHTL     13
#define buzz        14
#define infoD       15
#define pinServo    16


LiquidCrystal lcd(22, 24, 26, 28, 30, 32);    //definiuje gdzie wpiąłem wyświetlacz
Servo servo;                     //definiuje nazwe serwa

const byte ROWS = 4; // 4 wiersze
const byte COLS = 4; // 4 kolumny
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};                    //opisuję układ klawiszy na keypadzie
byte rowPins[ROWS] = {14, 15, 16, 17}; //definiuje gdzie podpiąłem wiersze
byte colPins[COLS] = {18, 19, 20, 21}; //definiuje gdzie podpiąłem kolumny
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //jakieś opisanie do klawiaturki
Password password = Password( "1337" );   //ustalam hasło

void setup() {
    int myEraser = 7;             
    TCCR2B &= ~myEraser;   
    int myPrescaler = 1;          
    TCCR2B |= myPrescaler;    //zmieniam częstotliwość PWM dziękiczemu silniki nie piszczą
    
    Serial.begin(9600);   //rozpoczynam komunikacje
    
    servo.attach(pinServo);         //ustalam serwo na swój pin
    servo.write(90);           //ustawiam na 90 

    pinMode (PP, OUTPUT);
    pinMode (PT, OUTPUT);
    pinMode (LP, OUTPUT);
    pinMode (LT, OUTPUT);

    digitalWrite(PP, LOW);
    digitalWrite(PT, LOW);
    digitalWrite(LP, LOW);
    digitalWrite(LT, LOW);

    analogWrite(SPEEDP, 200);
    analogWrite(SPEEDL, 200);     //deklaruje wszystko do pinów z silnika
    
    lcd.begin (16, 2);    //rozpoczynam wyświelacz 16x2
    lcd.setCursor(5, 0);
    lcd.print("MANUAL");
    lcd.setCursor(6, 1);
    lcd.print("MODE");   //piszę manual mode
   
    keypad.addEventListener(onClick);
}

void loop() {  
  if(Serial.available() > 0){
    
  }

}
