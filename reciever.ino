nRF24
#include <Servo.h>
#include <SPI.h>
#include "RF24.h"
Servo servo1;

RF24 radio(9,10);
const uint64_t pipe = 0xF0F0F0F000LL; 
int msg[1]; 
int data; 
int pos;
int fspeed;           // forward speed 
int bspeed;           // backward speed
const int in1 = 2;    // direction pin 1
const int in2 = 4;    // direction pin 2
const int ena = 5;    // PWM pin to change speed

void setup()
{
  
  pinMode(in1, OUTPUT);      // connection to L298n
  pinMode(in2, OUTPUT);      // connection to L298n
  pinMode(ena, OUTPUT);      // connection to L298n
servo1.attach(3); 
delay(50);
radio.begin();
radio.openReadingPipe(1,pipe); 
radio.startListening();
}

void loop()
{
  if (radio.available())radio.read(msg, 1);
  if (msg[0] <127 && msg[0] >-1)data = msg[0], pos = map(data, 0, 126, 7, 67),servo1.write(pos);
  
  
  if (msg[0] >=128 && msg[0] <=189)data = msg[0], bspeed = map(data, 255, 201, 0, 255), backward(bspeed);
  if (msg[0] >=201 && msg[0] <=255)data = msg[0], fspeed = map(data, 189, 128, 0, 255), forward(fspeed);
  if (msg[0] >190 && msg[0] <200)data = msg[0], stop();
}

void stop()
{
  
  analogWrite(ena, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void forward(int fspeed)
{
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, fspeed);
}

void backward(int bspeed)
{
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, bspeed);
}
