int pin_LED_R=9;
int pin_LED_G=10;
int pin_LED_B=11;

char input[4];
int i=0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 
 pinMode(pin_LED_R, OUTPUT);
 pinMode(pin_LED_G, OUTPUT);
 pinMode(pin_LED_B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char temp;
  int r,g,b;
  
  while(temp!='\r'){
    if(Serial.available()){
      temp=Serial.read();
      input[i]=temp;
      i++;
    }
  }
  temp=' ';
  i=0;
  r=atoi(input);
  for(int i2=0;i2<4;i2++){
    input[i2]=' ';
  }
  Serial.print("RGB_R : ");
  Serial.println(r);

 while(temp!='\r'){
    if(Serial.available()){
      temp=Serial.read();
      input[i]=temp;
      i++;
    }
  }
  temp=' ';
  i=0;
  g=atoi(input);
  for(int i2=0;i2<4;i2++){
    input[i2]=' ';
  }
  Serial.print("RGB_G : ");
  Serial.println(g);

  
  while(temp!='\r'){
    if(Serial.available()){
      temp=Serial.read();
      input[i]=temp;
      i++;
    }
  }
  temp=' ';
  i=0;
  b=atoi(input);
  for(int i2=0;i2<4;i2++){
    input[i2]=' ';
  }
  Serial.print("RGB_B : ");
  Serial.println(b);

  analogWrite(pin_LED_R, r);
  analogWrite(pin_LED_G, g);
  analogWrite(pin_LED_B, b);

  Serial.println("===================================");

}
