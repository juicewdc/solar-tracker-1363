#include <Servo.h>

#define LU A0
#define LD A1
#define RU A2
#define RD A3
#define error 160

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

  int d = rd + ld;
  int r = ru + rd;
  int u = ru + lu;
  int l = ld + lu;

  if ((lu <= error) && (ld <= error) && (ru <= error) && (rd <= error)) {
    // Do nothing
  } else {
    if (d > 100) {
      Spoint180--;
    }
    if (u > 100) {
      Spoint180++;
    }
    servo180.write(Spoint180);
  }

  if ((lu <= error) && (ld <= error) && (ru <= error) && (rd <= error)) {
    // Do nothing
  } else {
    if (l > 100) {
      Spoint360++;
    }
    if (r > 100) {
      Spoint360--;
    }
    servo360.write(Spoint360);
  }

  delay(80);
}


