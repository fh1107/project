int pin_DC_A = 5;
int pin_DC_B = 6;
void setup() {
  // put your setup code here, to run once:
 pinMode(pin_DC_A,OUTPUT);
 pinMode(pin_DC_B,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t Speed;
  for(Speed = 0; Speed <256;Speed++)
  {
    forwardRotation(Speed);
    delay(20);
   }
   for(;Speed >0;Speed--)
   {
    forwardRotation(Speed);
    delay(20);
   }
    Stop();
    delay(500);
    for(Speed =0; Speed<256;Speed++)
    {
      reverseRotation(Speed);
      delay(20);
    }
    delay(1000);
    for(;Speed >0;Speed--)
   {
    reverseRotation(Speed);
    delay(20);
   } 
   Stop();
    delay(500);
}

void forwardRotation(uint8_t Speed)
{
  digitalWrite(pin_DC_A,LOW);
  analogWrite(pin_DC_B,Speed);
}

void reverseRotation(uint8_t Speed)
{
  digitalWrite(pin_DC_B,LOW);
  analogWrite(pin_DC_A,Speed);
}
void Stop()
{
  digitalWrite(pin_DC_A,LOW);
  digitalWrite(pin_DC_B,LOW);
}


