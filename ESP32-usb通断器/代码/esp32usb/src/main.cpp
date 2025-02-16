#include <Arduino.h>
const int u1= 5;
const int u2= 6;
const int u3= 7;
const int u4= 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(u1, OUTPUT);
  pinMode(u2, OUTPUT);
  pinMode(u3, OUTPUT);
  pinMode(u4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(u1, HIGH);
  digitalWrite(u2, HIGH);
  digitalWrite(u3, HIGH);
  digitalWrite(u4, HIGH);
  delay(1000);
  digitalWrite(u1, LOW);
  digitalWrite(u2, LOW);
  digitalWrite(u3, LOW);
  digitalWrite(u4, LOW);
}