
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define button 4

RF24 radio(7, 8); // CE, CSN

const byte addresses[][6] = {"00001", "00002"};

Servo myServo;
boolean buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  myServo.attach(5);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00002
  radio.openReadingPipe(1, addresses[1]); // 00001
  radio.setPALevel(RF24_PA_MAX);
  Serial.begin(9600);
}
void loop() {
  //delay(5);
  radio.startListening();
  if ( radio.available()) {
    while (radio.available()) {
      

       int x = 0;
      radio.read(&x, sizeof(x));
      myServo.write(x);
      Serial.print("x=  ");
      Serial.print(x);
      Serial.print("\t");
      
     // delay(5);

      int y = 0;
      radio.read(&y, sizeof(y));
      myServo.write(y);
      Serial.print("y= ");
      Serial.print(y);
      Serial.print("\t");

   //   delay(5);

         int gx = 0;
      radio.read(&gx, sizeof(gx));
      myServo.write(gx);
      Serial.print("gx=  ");
      Serial.print(gx);
      Serial.print("\t");

   //   delay(5);

      int gy = 0;
      radio.read(&gy, sizeof(gy));
      myServo.write(gy);
      Serial.print("gy= ");
      Serial.print(gy);
      Serial.print("\n");

      delay(500);
    }
  }
}
