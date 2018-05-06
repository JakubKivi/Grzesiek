#include <Password.h>         //biblioteka do haseł 
#include <Keypad.h>           //biblioteka do klawiatury
#include <LiquidCrystal.h>    //biblioteka do wyświetlacza
#include <Servo.h>            //biblioteka do serwa

#define prox        38       //czujnik zbliżeniowy
#define trig        36
#define echo        34      //trigger i echo do czujnika dźwiękowego
#define PP          2
#define PT          3
#define LP          4
#define LT          5
#define SPEEDP      6
#define SPEEDL      7       //silniki
#define lPP         47
#define lLP         51
#define lPT         37
#define lLT         33      //swiatła
#define eyeL        41
#define eyeP        43      //swiatła u góry
#define buzz        13
#define pinServo    11

char data[100];
byte dataIndex;
char sign;                //zmienne do bluetooth

bool RPassword = 0;
bool remote = 0;

bool FR = 0;
bool FL = 0;
bool BR = 0;
bool BL = 0;        //zmienne przechowujace czy pala sie swiatla

LiquidCrystal lcd(52, 50, 48, 46, 44, 42);    //definiuje gdzie wpiąłem wyświetlacz
Servo servo;                     //definiuje nazwe serwa

const byte ROWS = 4; // 4 wiersze
const byte COLS = 4; // 4 kolumny
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};                    //opisuję układ klawiszy na keypadzie
byte rowPins[ROWS] = {32, 30, 28, 26}; //definiuje gdzie podpiąłem wiersze
byte colPins[COLS] = {24, 22, 23, 25}; //definiuje gdzie podpiąłem kolumny
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //jakieś opisanie do klawiaturki
Password password = Password( "1337" );   //ustalam hasło

void Setup(){
    Serial1.begin(9600);
    servo.attach(11);

    lcd.begin(16, 2);
    
    int myEraser = 7;             
    TCCR2B &= ~myEraser;   
    int myPrescaler = 1;          
    TCCR2B |= myPrescaler;    //zmieniam częstotliwość PWM dziękiczemu silniki nie piszczą(nie do konca wiem jak)

    pinMode(53, OUTPUT);
    digitalWrite(53, LOW);
    pinMode(53, OUTPUT);
    digitalWrite(49, LOW);
    pinMode(49, OUTPUT);
    digitalWrite(45, LOW);
    pinMode(45, OUTPUT);
    digitalWrite(39, LOW);
    pinMode(39, OUTPUT);
    digitalWrite(35, LOW);
    pinMode(35, OUTPUT);    //ziemie dla diod

    pinMode(lPP , OUTPUT);
    pinMode(lPT , OUTPUT);
    pinMode(lLP , OUTPUT);
    pinMode(lLT , OUTPUT);
    pinMode(eyeP , OUTPUT);
    pinMode(eyeL , OUTPUT);
    pinMode(buzz , OUTPUT); //swiatła jako wyjscie

    pinMode(PP , OUTPUT);
    pinMode(PT , OUTPUT);
    pinMode(LP , OUTPUT);
    pinMode(LT , OUTPUT);
    pinMode(SPEEDP , OUTPUT);
    pinMode(SPEEDL , OUTPUT); //silniki jako wyjscia

    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(prox , INPUT);   //czyjniki jako wejscie
}

#include "Keyboard.h"
#include "Functions.h"
#include "Local.h"
#include "Bluetooth.h"
