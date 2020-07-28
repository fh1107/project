#include<Servo.h>

int pin_SERVO = 13;
Servo SERVO;
char input[4];
int i =0;
int16_t j;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SERVO.attach(pin_SERVO);
}


void loop() {
  // put your main code here, to run repeatedly:
    uint8_t SW1,SW2;
    char temp;
    
    while(temp!='\r'){
    if(Serial.available()){
      temp=Serial.read();
      input[i]=temp;
      i++;
    }
    }
    temp=' ';
    i=0;
    j=atoi(input);
     for(int i2=0;i2<4;i2++){
      input[i2]=' ';
     }
     if((j<0)||(j>180))
     {
      Serial.println("재입력하시오");
      j=0;
     }
     else{
     Serial.println(j);
     SERVO.write(j);
     delay(15);
     }
  }
