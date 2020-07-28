#include <Servo.h>
int pin_SERVO = 13;
Servo SERVO;
int pin_SLIDE = A5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin_SLIDE, INPUT);
  SERVO.attach(pin_SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t ADC_data = 0;
  ADC_data = analogRead(pin_SLIDE);
  SERVO.write(ADC_data / 6);
  Serial.print("ADC Data: ");
  Serial.println(ADC_data);

  delay(500);
}
