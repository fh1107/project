#include<Servo.h>

int pin_SERVO = 13;
int sw1 = 3;
int sw2 = 4;
Servo SERVO;
char input[4];
 int i =0 ;
void setup() {
  // put your setup code here, to run once:
 SERVO.attach(pin_SERVO);
 pinMode(sw1,INPUT);
 pinMode(sw2,INPUT);
 Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
    uint8_t SW1,SW2;
    char temp;
  
    int j;
    SW1 = digitalRead(sw1);
    SW2 = digitalRead(sw2);
    do{
    while(temp!='\r'){
    if(Serial.available()){
      temp=Serial.read();
      input[i]=temp;
      i++;
    } 
    }
    temp=' ';
    }while((j>=0)||(j<181));
    j=atoi(input);
    for(int i2=0;i2<4;i2++)
    {
    input[i2]=' ';
    }
    Serial.println(j);
  if((SW1 == 1)&&(SW2 == 0))
  {
    SERVO.write(j);
    delay(15);
  }
  else if((SW1 ==0)&&(SW2 ==1))
  {
   for(int s = 0; s<=j; s++)
   {
    SERVO.write(s);
    delay(15); 
   }
   for(int s = j; s>=0; s--)
   {
    SERVO.write(s);
    delay(15); 
   }
  }
}
