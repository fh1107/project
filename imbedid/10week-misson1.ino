int pin_CDS = A1;
int pin_LED0 = 5;
int pin_LED1 = 6;
int pin_LED2 = 8;
int pin_LED3 = 9;
int pin_LED4 = 10;
int pin_LED5 = 11;
int pin_LED6 = 12;
int pin_LED7 = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin_CDS, INPUT);
  pinMode(pin_LED0, OUTPUT);
  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
  pinMode(pin_LED3, OUTPUT);
  pinMode(pin_LED4, OUTPUT);
  pinMode(pin_LED5, OUTPUT);
  pinMode(pin_LED6, OUTPUT);
  pinMode(pin_LED7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t ADC_data = 0;
  ADC_data = analogRead(pin_CDS);
  digitalWrite(pin_LED0, (ADC_data >> 2) % 2);
  digitalWrite(pin_LED1, (ADC_data >> 3) % 2);
  digitalWrite(pin_LED2, (ADC_data >> 4) % 2);
  digitalWrite(pin_LED3, (ADC_data >> 5) % 2);
  digitalWrite(pin_LED4, (ADC_data >> 6) % 2);
  digitalWrite(pin_LED5, (ADC_data >> 7) % 2);
  digitalWrite(pin_LED6, (ADC_data >> 8) % 2);
  digitalWrite(pin_LED7, (ADC_data >> 9) % 2);
  Serial.print("ADC Data: ");
  Serial.println(ADC_data);
  delay(1000);
}
