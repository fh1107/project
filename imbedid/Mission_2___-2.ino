int pin_LED0 =5;
int pin_LED1 = 6;
int pin_LED2 = 8;
int pin_LED3 = 9;
int pin_LED4 = 10;
int pin_LED5 = 11;
int pin_LED6 = 12;
int pin_LED7 = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_LED0,OUTPUT);
  pinMode(pin_LED1,OUTPUT);
  pinMode(pin_LED2,OUTPUT);
  pinMode(pin_LED3,OUTPUT);
  pinMode(pin_LED4,OUTPUT);
  pinMode(pin_LED5,OUTPUT);
  pinMode(pin_LED6,OUTPUT);
  pinMode(pin_LED7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_LED0,1);
  digitalWrite(pin_LED1,1);
  digitalWrite(pin_LED0,0);
  digitalWrite(pin_LED1,0);
  delay(175);
  digitalWrite(pin_LED2,1);
  digitalWrite(pin_LED3,1);
  digitalWrite(pin_LED2,0);
  digitalWrite(pin_LED3,0);
  delay(175);
  digitalWrite(pin_LED4,1);
  digitalWrite(pin_LED5,1);
  digitalWrite(pin_LED4,0);
  digitalWrite(pin_LED5,0);
  delay(175);
  digitalWrite(pin_LED6,1);
  digitalWrite(pin_LED7,1);
  digitalWrite(pin_LED6,0);
  digitalWrite(pin_LED7,0);
  delay(175);

}
