#include <Servo.h> 
#define LU A0 
#define LD A1 
#define RU A2 
#define RD A3 
#define error 10 
 
int Spoint = 10; 
Servo servo; 
 
void setup() { 
  Serial.begin(9600); 
  servo.attach(11); 
  servo.write(Spoint); 
  // No need for delay here 
} 
 
void loop() { 
  pinMode(LU, INPUT); 
  pinMode(LD, INPUT); 
  pinMode(RU, INPUT); 
  pinMode(RD, INPUT); 
  pinMode(6, OUTPUT); 
 
  int lu = analogRead(LU); 
  int ld = analogRead(LD); 
  int ru = analogRead(RU); 
  int rd = analogRead(RD); 
 
  if ((lu <= error)  (ld <= error))  (ru <= error) || (rd <= error)  { 
    // Do nothing 
  } else { 
    if (lu > ld) { 
      Spoint = --Spoint; 
    } 
    if (lu < ld) { 
      Spoint = ++Spoint; 
    if (rd < ru) { 
      Spoint = 
    } 
    } 
  } 
 
  servo.write(Spoint); 
  delay(80); 
}
