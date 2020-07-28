int pin_TEMP = A4;
int pin_DC_A = 5;
int pin_DC_B = 6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin_DC_A, OUTPUT);
  pinMode(pin_DC_B, OUTPUT);
  pinMode(pin_TEMP, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t ADC_data = 0;
  ADC_data = analogRead(pin_TEMP);
  uint16_t Temp;
  Temp = ADC_data * 5 * 100 / 1023;
  if (Temp >= 28)
  {
    forwardRotation(Temp * 10);
  }
  else if ((Temp >= 24) && (Temp < 28))
  {
    Stop();
  }
  else
  {
    reverseRotation(Temp * 5);
  }
  Serial.print("Temp : ");
  Serial.print(Temp);
  Serial.println("[C]");
  delay(500);
}
void forwardRotation(int8_t Speed)
{
  digitalWrite(pin_DC_A, LOW);
  analogWrite(pin_DC_B, Speed);
}

void reverseRotation(int8_t Speed)
{
  digitalWrite(pin_DC_B, LOW);
  analogWrite(pin_DC_A, Speed);
}
void Stop()
{
  digitalWrite(pin_DC_A, LOW);
  digitalWrite(pin_DC_B, LOW);
}
