int pin_LED_R = 9;
int pin_LED_G = 10;
int pin_LED_B = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_LED_R,OUTPUT);
  pinMode(pin_LED_G,OUTPUT);
  pinMode(pin_LED_B,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Red
  analogWrite(pin_LED_R,255);
  delay(3000);
  
  //OrangeLed
  analogWrite(pin_LED_G,127);
  delay(3000);
  
  //YellowLed
  analogWrite(pin_LED_G,255);
  delay(3000);

  //GreenLed
  analogWrite(pin_LED_R,0);
  analogWrite(pin_LED_G,51);
  delay(3000);

  //BlueLed
  analogWrite(pin_LED_G,255);
  analogWrite(pin_LED_B,255);
  delay(3000);
  
  //IndigoLed
  analogWrite(pin_LED_G,0);
  analogWrite(pin_LED_B,255);
  delay(3000);


  //violetLed
  analogWrite(pin_LED_R,128);
  analogWrite(pin_LED_B,255);
  delay(3000);
}
