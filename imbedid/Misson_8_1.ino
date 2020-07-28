#include<Servo.h>

int pin_SERVO = 13;

Servo SERVO;

void setup() {
  // put your setup code here, to run once:
 SERVO.attach(pin_SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:
 int16_t pos;
 for(pos=0; pos<=180;pos++)
 {
  SERVO.write(pos);
  delay(15);
 }
 for(pos=180;pos>=0;pos--)
 {
  SERVO.write(pos);
  delay(15);
 }
}
