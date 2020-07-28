int pin_SLIDE = A5;
int pin_FND[8] = {5, 6, 8, 9, 10, 11, 12, 13};
uint8_t FND_Data[16] = {0x3F, 0x06, 0x5B, 0x4F,
                        0x66, 0x6D, 0x7D, 0x27,
                        0x7F, 0x6F, 0x77, 0x7C,
                        0x39, 0x5E, 0x79, 0x71
                       };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin_SLIDE, INPUT);
  for (int i = 0; i < 8; i++)
  {
    pinMode(pin_FND[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t ADC_data = 0;
  ADC_data = analogRead(pin_SLIDE);
  if ((ADC_data >= 0) && (ADC_data < 64))
  {
    FND_Ctrl(FND_Data[0]);
    delay(500);
  }
  else if ((ADC_data >= 64) && (ADC_data < 128))
  {
    FND_Ctrl(FND_Data[1]);
    delay(500);
  }
  else if ((ADC_data >= 128) && (ADC_data < 192))
  {
    FND_Ctrl(FND_Data[2]);
    delay(500);
  }
  else if ((ADC_data >= 192) && (ADC_data < 256))
  {
    FND_Ctrl(FND_Data[3]);
    delay(500);
  }
  else if ((ADC_data >= 256) && (ADC_data < 320))
  {
    FND_Ctrl(FND_Data[4]);
    delay(500);
  }
  else if ((ADC_data >= 320) && (ADC_data < 384))
  {
    FND_Ctrl(FND_Data[5]);
    delay(500);
  }
  else if ((ADC_data >= 384) && (ADC_data < 448))
  {
    FND_Ctrl(FND_Data[6]);
    delay(500);
  }
  else if ((ADC_data >= 448) && (ADC_data < 512))
  {
    FND_Ctrl(FND_Data[7]);
    delay(500);
  }
  else if ((ADC_data >= 512) && (ADC_data < 576))
  {
    FND_Ctrl(FND_Data[8]);
    delay(500);
  }
  else if ((ADC_data >= 576) && (ADC_data < 640))
  {
    FND_Ctrl(FND_Data[9]);
    delay(500);
  }
  else if ((ADC_data >= 640) && (ADC_data < 704))
  {
    FND_Ctrl(FND_Data[10]);
    delay(500);
  }
  else if ((ADC_data >= 704) && (ADC_data < 768))
  {
    FND_Ctrl(FND_Data[11]);
    delay(500);
  }
  else if ((ADC_data >= 768) && (ADC_data < 832))
  {
    FND_Ctrl(FND_Data[12]);
    delay(500);
  }
  else if ((ADC_data >= 832) && (ADC_data < 896))
  {
    FND_Ctrl(FND_Data[13]);
    delay(500);
  }
  else if ((ADC_data >= 896) && (ADC_data < 960))
  {
    FND_Ctrl(FND_Data[14]);
    delay(500);
  }
  else if ((ADC_data >= 960) && (ADC_data < 1024))
  {
    FND_Ctrl(FND_Data[15]);
    delay(500);
  }
  Serial.print("ADC Data: ");
  Serial.println(ADC_data);
  delay(500);
}

void FND_Ctrl(uint8_t Ctrl_data)
{
  for (int j = 0; j < 8; j++)
  {
    digitalWrite(pin_FND[j], Ctrl_data & (0x01 << j));
  }
}

