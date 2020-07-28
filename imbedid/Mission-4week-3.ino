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
int count;
int prevState = 0;   // 스위치의 이전상태
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
if(SW1_data != prevState)
{
  if(SW1_data == 1)
  {
    count++;
  }
  digitalWrite(pin_LED0,count%2);
  digitalWrite(pin_LED1,(count>>1)%2);
  digitalWrite(pin_LED2,(count>>2)%2);
  digitalWrite(pin_LED3,(count>>3)%2);
  digitalWrite(pin_LED4,(count>>4)%2);
  digitalWrite(pin_LED5,(count>>5)%2);
  digitalWrite(pin_LED6,(count>>6)%2);
  digitalWrite(pin_LED7,(count>>7)%2);
  prevState = SW1_data;
}
if(SW2_data == 1)
  {
    count =0;
     digitalWrite(pin_LED0,0);
  digitalWrite(pin_LED1,0);
  digitalWrite(pin_LED2,0);
  digitalWrite(pin_LED3,0);
  digitalWrite(pin_LED4,0);
  digitalWrite(pin_LED5,0);
  digitalWrite(pin_LED6,0);
  digitalWrite(pin_LED7,0);
  }
  delay(50);
}
