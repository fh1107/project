int pin_LED_R = 9;
int pin_LED_G =10;
int pin_LED_B =11;
void setup() {
  // put your setup code here, to run once:
 pinMode(pin_LED_R,OUTPUT);
 pinMode(pin_LED_G,OUTPUT);
 pinMode(pin_LED_B,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int brightness;
  for(brightness=255; brightness==0;brightness--)
  {
    analogWrite(pin_LED_R,brightness);
    analogWrite(pin_LED_G,brightness);
    analogWrite(pin_LED_B,brightness);
    delay(20);
  }
  digitalWrite(pin_LED_R,0);
  digitalWrite(pin_LED_G,0);
  digitalWrite(pin_LED_B,0);

}
