/*
CE    → Pin 7
CS(N) → Pin 8
MOSI  → Pin 11
MISO  → Pin 12
SCK   → Pin 13
Vcc   → 3.3v
GND   → GND
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int LED = 31;
int green = 33;
int red = 32;
int text;
int LIN1 = 40; int LIN2 = 41; int RIN3 = 42; int RIN4 = 43;
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(LED, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(LIN1, OUTPUT); pinMode(LIN2, OUTPUT); 
  pinMode(RIN3, OUTPUT); pinMode(RIN4, OUTPUT);
  
  
}
void loop() {
  digitalWrite(LED, HIGH);delay(100);digitalWrite(LED, LOW);delay(100);
   if (radio.available()) {
    digitalWrite(green, HIGH);  
    radio.read(&text, sizeof(text));
    Serial.println(text);
    
    if (text == 1){
      digitalWrite(green, HIGH);
      digitalWrite(LIN1, HIGH);
      digitalWrite(LIN2, LOW);
      digitalWrite(RIN3, LOW);
      digitalWrite(RIN4, HIGH);
    }
    else if (text == 2){
      digitalWrite(green, HIGH);
      digitalWrite(LIN1, LOW);
      digitalWrite(LIN2, HIGH);
      digitalWrite(RIN3, HIGH);
      digitalWrite(RIN4, LOW);
   
    }
    else if (text == 3){
      digitalWrite(green, HIGH);
      digitalWrite(LIN1, HIGH);
      digitalWrite(LIN2, LOW);
      digitalWrite(RIN3, HIGH);
      digitalWrite(RIN4, LOW);

    }
   else if (text == 0){
 
      digitalWrite(LIN1, LOW);
      digitalWrite(LIN2, LOW);
      digitalWrite(RIN3, LOW);
      digitalWrite(RIN4, LOW);

    digitalWrite(red, HIGH);
   }
  }
}
