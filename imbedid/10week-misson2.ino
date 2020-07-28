int pin_CDS = A1;
int pin_R = 9;
int pin_G = 10;
int pin_B = 11;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin_CDS, INPUT);
  pinMode(pin_R, OUTPUT);
  pinMode(pin_G, OUTPUT);
  pinMode(pin_B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t ADC_data = 0;
  ADC_data = analogRead(pin_CDS);
  uint16_t brss = map(ADC_data, 0, 1023, 0, 255);
  analogWrite(pin_R, 255 - brss);
  analogWrite(pin_G, 255 - brss);
  analogWrite(pin_B, 255 - brss);
  Serial.print("ADC Data: ");
  Serial.println(ADC_data);
  delay(1000);
}
