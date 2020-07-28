// SW1 pin number 3
int pin_SW1 = 3;
// SW2 pin number 4
int pin_SW2 = 4;
int count;
void setup() {  //등록
// SW1 pin Input Setup
pinMode(pin_SW1, INPUT);
// SW2 pin Input Setup
pinMode(pin_SW2, INPUT);
}


void loop() {
   uint8_t SW1_data, SW2_data;
 
   SW1_data = digitalRead(pin_SW1); 
   SW2_data = digitalRead(pin_SW2);

   
 
  if(SW1_data == 1){ 
    count++;
    Serial.println(count);
  }     
  delay(50);
   if (SW2_data == 1){
     count--;
     Serial.println(count);
   }
   delay(50);
}
  

