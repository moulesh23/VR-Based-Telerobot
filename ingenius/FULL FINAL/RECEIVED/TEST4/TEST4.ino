#include <SPI.h> 
#include <nRF24L01.h> 
#include <RF24.h> 
#include<Servo.h>

Servo v,h;


const int l1=4;
const int l2=5;
const int r1=2;
const int r2=3;

const int pinCE = 7; 
const int pinCSN = 8; 
int gotArray[4]; 

RF24 wirelessSPI(pinCE, pinCSN);  
const uint64_t pAddress = 0xB00B1E5000LL;  

void setup()   
{
 Serial.begin(9600);  
 wirelessSPI.begin();  
 wirelessSPI.setAutoAck(1);             
 wirelessSPI.enableAckPayload();        
 wirelessSPI.setRetries(5,15);        
 wirelessSPI.openReadingPipe(1,pAddress);   
 wirelessSPI.startListening();      
 wirelessSPI.printDetails();     

 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);

 v.attach(10);
 h.attach(9);
 
}

void loop()  
{   
  while(wirelessSPI.available()){ 
    wirelessSPI.read( &gotArray, sizeof(gotArray) ); 
    Serial.print("Recieved array:"); 
 /*   for (byte i=0; i<4; i++){
      Serial.println(gotArray[i]);
    }
    Serial.println(); */
   }

// MAPPING X OF MOTOR
   if(gotArray[0]<=70)
    gotArray[0]=0;

    else if(gotArray[0]>=110)
      gotArray[0]=180;

    else
      gotArray[0]=90;

// MAPPING Y OF MOTOR
      
   if(gotArray[1]<=70)
    gotArray[1]=0;

    else if(gotArray[1]>=110)
      gotArray[1]=180;

    else
      gotArray[1]=90;

// MOTOR CONTROL

  if(gotArray[0]==90 && gotArray[1]==90)
    {
    
    }

   else if(gotArray[0]==180 && gotArray[1]==90)
   {
      digitalWrite(l1,HIGH);
      digitalWrite(l2,LOW);
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
      
   }

   else if(gotArray[0]==90 && gotArray[1]==0)
   {
      digitalWrite(l2,HIGH);
      digitalWrite(l1,LOW);
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
      
   }

   else if(gotArray[0]==90 && gotArray[1]==180)
   {
      digitalWrite(l1,HIGH);
      digitalWrite(l2,LOW);
      digitalWrite(r2,HIGH);
      digitalWrite(r1,LOW);
      
   }

   
  
   h.write(gotArray[2]);

    v.write(gotArray[3]);
   
 delay(100);    
 
 
}
