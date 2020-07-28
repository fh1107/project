int pin_DC_A = 5;
int pin_DC_B = 6;
int pin_LED_R = 9;
int pin_LED_G = 10;
int pin_LED_B = 11;
int pin_SW_1 = 3;
int pin_SW_2 = 4;
int speed_count;

 
void setup() {
  // put your setup code here, to run once:
 pinMode(pin_DC_A,OUTPUT);
 pinMode(pin_DC_B,OUTPUT);
 pinMode(pin_LED_R,OUTPUT);
 pinMode(pin_LED_G,OUTPUT);
 pinMode(pin_LED_B,OUTPUT);
 pinMode(pin_SW_1,INPUT);
 pinMode(pin_SW_2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 uint8_t SW1_data ,SW2_data;

 SW1_data = digitalRead(pin_SW_1);
 SW2_data = digitalRead(pin_SW_2);
 if((SW1_data ==1)&&(SW2_data==0))
 {
    speed_count++;
   SW1_data = 0;
 }
  delay(20);
 if((SW1_data ==0)&&(SW2_data==1))
 {
    speed_count--;
   SW2_data =0;
 }
 delay(20);
 
  if(speed_count==0){
    Stop();
    delay(200);
  }else if(speed_count>0){
    forwardRotation(speed_count*10);
    switch(speed_count){
      case 1:
      analogWrite(pin_LED_R,speed_count*10);
       digitalWrite(pin_LED_G,0);
    digitalWrite(pin_LED_B,0);
      break;
      case 2:
      analogWrite(pin_LED_R,speed_count*40);
       digitalWrite(pin_LED_G,0);
    digitalWrite(pin_LED_B,0);
      break;
      case 3:
      analogWrite(pin_LED_R,speed_count*60);
       digitalWrite(pin_LED_G,0);
    digitalWrite(pin_LED_B,0);
      break;
      default:
      break;
    }
  }
  else{
    reverseRotation(speed_count*-10);
    switch(speed_count){
      case -1:
      analogWrite(pin_LED_B,speed_count*-10);
      digitalWrite(pin_LED_R,0);
    digitalWrite(pin_LED_G,0);
      break;
      case -2:
      analogWrite(pin_LED_B,speed_count*-40);
      digitalWrite(pin_LED_R,0);
    digitalWrite(pin_LED_G,0);
      break;
      case -3:
      analogWrite(pin_LED_B,speed_count*-60);
      digitalWrite(pin_LED_R,0);
    digitalWrite(pin_LED_G,0);
      break;
      default:
      break;
    }
  }
}


void forwardRotation(int Speed)
{
  digitalWrite(pin_DC_A,LOW);
  analogWrite(pin_DC_B,Speed);
}

void reverseRotation(int Speed)
{
  digitalWrite(pin_DC_B,LOW);
  analogWrite(pin_DC_A,Speed);
}
void Stop()
{
  digitalWrite(pin_DC_A,LOW);
  digitalWrite(pin_DC_B,LOW);
      digitalWrite(pin_LED_R,0);
    digitalWrite(pin_LED_G,0);
    digitalWrite(pin_LED_B,0);
}

