int pin_SLIDE = A5;
int pin_LED_R = 9;
int pin_LED_G = 10;
int pin_LED_B = 11;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin_SLIDE, INPUT);
  pinMode(pin_LED_R, OUTPUT);
  pinMode(pin_LED_G, OUTPUT);
  pinMode(pin_LED_B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t ADC_data = 0;
  ADC_data = analogRead(pin_SLIDE);
  uint16_t hue = map(ADC_data, 0, 1023, 0, 360);
  uint16_t brss = map(ADC_data, 0, 1023, 0, 255);
  Serial.print("ADC Data: ");
  Serial.println(hue);
  if ((hue >= 0) && (hue < 60))  //빨강->노랑
  {
    analogWrite(pin_LED_R, 255);
    analogWrite(pin_LED_G, brss);
    analogWrite(pin_LED_B, 0);
  }
  else if ((hue >= 60) && (hue < 120)) //노랑->초록
  {
    analogWrite(pin_LED_R, 255 - brss);
    analogWrite(pin_LED_G, 255);
    analogWrite(pin_LED_B, 0);
  }
  else if ((hue >= 120) && (hue < 180)) // 초록->하늘색
  {
    analogWrite(pin_LED_R, 0);
    analogWrite(pin_LED_G, 255);
    analogWrite(pin_LED_B, brss);
  }
  else if ((hue >= 180) && (hue < 240)) // 하늘->파랑
  {
    analogWrite(pin_LED_R, 0);
    analogWrite(pin_LED_G, 255 - brss);
    analogWrite(pin_LED_B, 255);
  }
  else if ((hue >= 240) && (hue < 300)) // 파랑->보라
  {
    analogWrite(pin_LED_R, brss);
    analogWrite(pin_LED_G, 0);
    analogWrite(pin_LED_B, 255);
  }
  else if ((hue >= 300) && (hue <= 360)) // 보라->빨강
  {
    analogWrite(pin_LED_R, 255);
    analogWrite(pin_LED_G, 0);
    analogWrite(pin_LED_B, 255 - brss);
  }
}

