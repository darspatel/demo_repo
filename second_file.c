// Name: Darshan Patel
// Date: July 16, 2018
// Project: Microproject - Central Door Locking System
// Version: 1.0
// MC: Arduino UNO
// Company: KPIT

#include <Servo.h>

int pos = 0;
int button1 = 0;
int button2 = 0;
int doorLock = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9);		// Lock Motor
  servo_9.write(0);
  pinMode(2, INPUT);		// Lock Button
  pinMode(3, INPUT);		// Unlock Button
  pinMode(4, INPUT);		// DOORS Logic
  pinMode(12, OUTPUT); 		// Green LED
  pinMode(13, OUTPUT);		// Red LED
  pinMode(11, OUTPUT);		// Interior Light
}


void loop()
{
  button1 = digitalRead(2);
  button2 = digitalRead(3);
  doorLock = digitalRead(4);
  
  if(button1 == HIGH && doorLock == HIGH)
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    servo_9.write(90);
    delay(15);
  }
  else if(button1 == HIGH && doorLock == LOW)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    servo_9.write(0);
    delay(15);
  }
  else if(button2 == HIGH)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    servo_9.write(0);
    delay(15);
  }
  if (doorLock == LOW)
  {
    digitalWrite(11, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    servo_9.write(0);
    delay(15);
  }
  else if (doorLock == HIGH)
  {
    digitalWrite(11, LOW);
  }
}