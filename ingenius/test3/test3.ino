#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(7, 8); // CE, CSN



int arr[4];

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void loop() {
  if (radio.available()) 
  
  {
    while(radio.available())
    {
      for(int i=0;i<4;i++)
      {
        radio.read(&arr[i], sizeof(arr[i]));
      }
      
   
    
    Serial.print(arr[0]);
    Serial.print("\t");
    Serial.print(arr[1]);
    Serial.print("\t");
    Serial.print(arr[2]);
    Serial.print("\t");
    Serial.print(arr[3]);
    Serial.print("\n");

    }
  }
}
