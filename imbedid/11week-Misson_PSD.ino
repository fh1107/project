int pin_PSD = A0;
int distance = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin_PSD, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int volt = map(analogRead(pin_PSD), 0, 1023, 0, 5000);
  distance = (27.61 / (volt - 0.1696)) * 1000;
  Serial.print("Dist : ");
  Serial.print(distance);
  Serial.println("[Cm]");
  delay(500);
}

