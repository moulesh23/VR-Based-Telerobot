#include <Servo.h>
Servo myservo;

void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  int x= analogRead(A0);
  int val= map(x,280,423,0,180);
  Serial.println(x);
  myservo.write(val);
  delay(10);
}
