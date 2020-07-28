int pin_DC_A = 5;
int pin_DC_B = 6;
char input[4];
int i =0;
void setup() {
  // put your setup code here, to run once:
 pinMode(pin_DC_A,OUTPUT);
 pinMode(pin_DC_B,OUTPUT);
 Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int j;
  char temp;
  do{
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
  }while((j>126)||(j<-127));
  for(int i2=0;i2<4;i2++){
    input[i2]=' ';
  }
  Serial.print("Speed :");
  Serial.println(j);
  if(j > 0)
  {
    forwardRotation(j*2);
    delay(20);
  }
  else if(j<0)
  {
    reverseRotation(j*(-2));
    delay(20);
  }
  else{
    Stop();
    delay(200);
  }
}
void forwardRotation(int8_t Speed)
{
  digitalWrite(pin_DC_A,LOW);
  analogWrite(pin_DC_B,Speed);
}

void reverseRotation(int8_t Speed)
{
  digitalWrite(pin_DC_B,LOW);
  analogWrite(pin_DC_A,Speed);
}
void Stop()
{
  digitalWrite(pin_DC_A,LOW);
  digitalWrite(pin_DC_B,LOW);
}
