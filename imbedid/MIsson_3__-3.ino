int pin_BUZZER =12;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_BUZZER,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_BUZZER,HIGH);
  delay(1000);
  digitalWrite(pin_BUZZER,LOW);
  delay(1000);
  digitalWrite(pin_BUZZER,HIGH);
  delay(2500);
  digitalWrite(pin_BUZZER,LOW);
  delay(2500);
  digitalWrite(pin_BUZZER,HIGH);
  delay(700);
  digitalWrite(pin_BUZZER,LOW);
  delay(700);
  digitalWrite(pin_BUZZER,HIGH);
  delay(1200);
  digitalWrite(pin_BUZZER,LOW);
  delay(1200);
  digitalWrite(pin_BUZZER,HIGH);
  delay(3000);
  digitalWrite(pin_BUZZER,LOW);
  delay(3000);

}
