
int pin_SW1 = 3;
int pin_LED[] = { 5, 6, 8, 9, 10, 11, 12, 13 };

int led_check;
bool flag = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_SW1, INPUT);

  pinMode(pin_LED[0], OUTPUT);
  pinMode(pin_LED[1], OUTPUT);
  pinMode(pin_LED[2], OUTPUT);
  pinMode(pin_LED[3], OUTPUT);
  pinMode(pin_LED[4], OUTPUT);
  pinMode(pin_LED[5], OUTPUT);
  pinMode(pin_LED[6], OUTPUT);
  pinMode(pin_LED[7], OUTPUT);

  attachInterrupt(0, blink, RISING);
}

void blink() {
  flag = !flag;
}


void loop() {
  // put your main code here, to run repeatedly:
  if(flag == false && led_check == 9)
    led_check = 0;
  else if(flag == true && led_check == -1)
    led_check = 8;

  digitalWrite(pin_LED[led_check], !digitalRead(pin_LED[led_check]));
  delay(700);
  digitalWrite(pin_LED[led_check], !digitalRead(pin_LED[led_check]));
   
  if(flag == false)
    led_check++;
  else
    led_check--;
}
