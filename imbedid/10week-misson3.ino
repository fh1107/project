int pin_TEMP = A4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin_TEMP, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t ADC_data = 0;
  ADC_data = analogRead(pin_TEMP);
  double Temp;
  Temp = ADC_data * 5.0 * 100.0 / 1023.0;
  Serial.print("Temp : e.g.");
  Serial.print(Temp);
  Serial.println("[C]");
  delay(500);
}
