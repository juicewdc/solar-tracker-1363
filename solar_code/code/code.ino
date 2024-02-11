#include <Servo.h>

#define LU A0
#define LD A1
#define RU A2
#define RD A3
#define error 70

int Spoint180 = 10;
int Spoint360 = 50;
Servo servo180;
Servo servo360;

void setup() {
  Serial.begin(9600);
  servo180.attach(5);
  servo360.attach(6);
}

void loop() {
  servo180.write(Spoint180);
  servo360.write(Spoint360);
  int lu = analogRead(LU);
  int ld = analogRead(LD);
  int ru = analogRead(RU);
  int rd = analogRead(RD);

  int d = (rd + ld) / 2;
  int r = (ru + rd) / 2;
  int u = (ru + lu) / 2;
  int l = (ld + lu) / 2;

  Serial.print(l);
  Serial.print(", ");
  Serial.print(r);
  Serial.print(", ");
  Serial.print(u);
  Serial.print(", ");
  Serial.println(d);


  if ((lu <= error) && (ld <= error) && (ru <= error) && (rd <= error)) {
    // Do nothing
  } else {
    if (d > 600) {
    servo180.write(90)  ;
    }
    if (u > 600) {
      servo180.write(180);
    }
  }

  if ((lu <= error) && (ld <= error) && (ru <= error) && (rd <= error)) {
    // Do nothing
  } else {
    if (r > 600) {
      servo360.write(0);
    }
    if (l > 600) {
      servo360.write(180);
    } else {
      servo360.write(90);
    }
  }

  delay(100);
}
