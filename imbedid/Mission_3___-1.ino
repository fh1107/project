int pin_FND[8] = {5,6,8,9,10,11,12,13};

uint8_t FND_Data_play[4] = {0x73,0x38,0x77,0x6E};
uint8_t FND_Data_num[36] = {0x3F, 0x06,0x5B,0x4F,
0x66,0x6D, 0x7D, 0x27,
0x7F, 0x6F, 0x77, 0x7C,
0x39, 0x5E, 0x79,0x71,
0x3D, 0x76, 0x30,0x1E,
0x7A, 0x1C, 0x55,0x54,
0x5C, 0x59, 0x67,0x50,
0x6D, 0x78, 0x1C,0x3E,
0x6A, 0x36, 0x6E, 0x49};

void setup() {
  // put your setup code here, to run once:
  for(int i =0 ; i<8; i++)
  {
    pinMode(pin_FND[i],OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i2=0;i2<4;i2++){
    FND_Ctrl(FND_Data_play[i2]);
    delay(800);
  }
   delay(1000);
  for(int i =0; i<36; i++)
  {
    FND_Ctrl(FND_Data_num[i]);
    delay(500);
  }

}

void FND_Ctrl(uint8_t Ctrl_data)
{
  for(int j=0; j<8; j++)
  {
    digitalWrite(pin_FND[j],(Ctrl_data>>j) & 0x01);
  }
}

