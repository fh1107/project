int pin_SW1 = 3;
int pin_SW2 =4;
int pin_LED0 = 5;
int pin_LED1 = 6;
int pin_LED2 = 8;
int pin_LED3 = 9;
int pin_LED4 = 10;
int pin_LED5 = 11;
int pin_LED6 = 12;
int pin_LED7 = 13;

void setup() {
  // put your setup code here, to run once:
pinMode(pin_SW1,INPUT);
pinMode(pin_SW2,INPUT);
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
  uint8_t SW1_data, SW2_data;
  SW1_data = digitalRead(pin_SW1);
  SW2_data = digitalRead(pin_SW2);
  digitalWrite(pin_LED0,SW1_data);
  digitalWrite(pin_LED1,SW1_data);
  digitalWrite(pin_LED2,SW1_data);
  digitalWrite(pin_LED3,SW1_data);
  digitalWrite(pin_LED4,SW2_data);
  digitalWrite(pin_LED5,SW2_data);
  digitalWrite(pin_LED6,SW2_data);
  digitalWrite(pin_LED7,SW2_data);
  delay(1000);

}
