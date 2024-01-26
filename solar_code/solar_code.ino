#include <Servo.h>

#define LU A0
#define LD A1
#define RU A2
#define RD A3
#define error 10

int Spoint180 = 10;
int Spoint360 = 10;
Servo servo180;
Servo servo360;

void setup() {
  Serial.begin(9600);
  servo180.attach(11);
  servo360.attach(12);
  servo180.write(Spoint180);
  servo360.write(Spoint360);
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

  if ((lu <= error) && (ld <= error) && (ru <= error) && (rd <= error)) {
  } else {
    if ((ld != lu) || (rd != ru) || (ru != lu) || (rd != ld)) {
      if (lu > ld) {
        Spoint180 = --Spoint180;
      }
      if (lu < ld) {
        Spoint180 = ++Spoint180;
      }
      if (rd < ru) {
        Spoint180 = ++Spoint180;
      }
      servo180.write(Spoint180);
    } else {
      Spoint360 = ++Spoint360;
      servo360.write(Spoint360);
    }
  }

  delay(80);
}

