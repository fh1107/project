int pin_SW1 = 3;
int pin_SW2 =4;
int pin_FND[8] = {5,6,8,9,10,11,12,13};
uint8_t FND_Data_num[3] = {0x06,0x5B,0x4F};
void setup() {
  // put your setup code here, to run once:
pinMode(pin_SW1,INPUT);
pinMode(pin_SW2,INPUT);
  for(int i =0 ; i<8; i++)
  {
    pinMode(pin_FND[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 uint8_t SW1_data, SW2_data;
  SW1_data = digitalRead(pin_SW1);
  SW2_data = digitalRead(pin_SW2);
  if((SW1_data == 1)&&(SW2_data == 0))
  {
    FND_Ctrl(FND_Data_num[0]);
  }
  else if((SW1_data == 0)&&(SW2_data==1))
  {
    FND_Ctrl(FND_Data_num[1]);
  }
  else if((SW1_data == 1)&&(SW2_data==1))
  {
    FND_Ctrl(FND_Data_num[2]);
  }
  else{}
  delay(100);
  
}

void FND_Ctrl(uint8_t Ctrl_data)
{
  for(int j=0; j<8; j++)
  {
  digitalWrite(pin_FND[j],Ctrl_data &(0x01 <<j));
  }
}

