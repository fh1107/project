int servoPin = 13;
int pin_DC_A = 5;
int pin_DC_B = 6;
int pin_LED_R = 9;
int pin_LED_G = 10;
int pin_LED_B = 11;
int cased = 0;

void setup()
{
  Serial1.begin(9600);
  pinMode(pin_DC_A, OUTPUT);
  pinMode(pin_DC_B, OUTPUT);
  pinMode(servoPin , OUTPUT);
  pinMode(pin_LED_R, OUTPUT);
  pinMode(pin_LED_G, OUTPUT);
  pinMode(pin_LED_B, OUTPUT);
}

void loop() {
  if (Serial1.available() > 0)
  {
    cased = Select_Choice();

    switch (caesed) {
      case '1':
        initialize();
        Serial1.println("1 : RGB");
        setColor(150, 150, 100);
        delay(3000);
        break;
      case '2':

        initialize();
        Serial1.println("2 : SERVO");
        int16_t pos;
        servo_ON();
        break;

      case '3':

        initialize();
        Serial1.println("3 : DC MOTER");
        uint16_t Speed;
        for (Speed = 0; Speed < 256; Speed++)
        {
          forwardRotation(Speed);
          delay(20);
        }
        delay(1000);
        Stop();
        delay(200);

        for (Speed = 0; Speed < 256; Speed++)
        {
          reverseRotation(Speed);
          delay(20);
        }
        delay(1000);
        Stop();
        delay(200);
        Choice = Select_Choice();
        break;
      case '4' :
        initialize();
        delay(500);
        break;
      default :
        Serial1.println("Invalid Select");
        Choice = Select_Choice();
        initialize();
        break;
    }
  }
}
void initialize()
{
  Stop();
  digitalWrite(servoPin, LOW);
  setColor(0, 0, 0);
  Serial1.flush();
}

int Select_Choice()
{
  int result = 0;
  char temp = ' ';
  Serial1.println("----------------------------");
  Serial1.println("Choice 1~3");
  temp = Serial1.read();
  Serial1.print("Choice : ");
  Serial1.println(temp);
  result = int(temp);
  return result;
}

void Select_Color()
{
  int Red = 0;
  int Green = 0;
  int Blue = 0;
  String c_red = "";
  String c_green = "";
  String c_blue = "";

  c_red = Serial1.read();
  Red = c_red.toInt();

  c_green = Serial1.read();
  Green = c_red.toInt();

  c_red = Serial1.read();
  Blue = c_red.toInt();

  Serial1.print("Red : ");
  Serial1.print(Red);
  Serial1.print("Green : ");
  Serial1.print(Green);
  Serial1.print("Blue : ");
  Serial1.print(Blue);
}
void setColor(int red, int green, int blue)
{
  analogWrite(pin_LED_R, red);
  analogWrite(pin_LED_G, green);
  analogWrite(pin_LED_B, blue);
}

void servo_ON() {
  int m_max = 2400; //아두이노 default 펄스값 min 544 max 2400

  for (int i = 544; i < 2400; i++)
  { //0도에서 180도로 회전
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(i);  // i = 전류 공급 간격 = 각도
    digitalWrite(servoPin, LOW);
    delayMicroseconds(m_max - i); //전류 차단 = 파형생성 = 회전속도
  }
}


void forwardRotation(uint8_t Speed)
{
  digitalWrite(pin_DC_A, LOW);
  analogWrite(pin_DC_B, Speed);
}

void reverseRotation(uint8_t Speed)
{
  digitalWrite(pin_DC_B, LOW);
  analogWrite(pin_DC_A, Speed);
}

void Stop(void)
{
  digitalWrite(pin_DC_A, LOW);
  digitalWrite(pin_DC_B, LOW);
}

void DC()
{
  int CW = Serial1.parseInt();
  uint16_t Speed = abs(CW) * 2;

  Serial1.println("속력:" + CW);
  if (CW >= 0 && CW < 127) {
    digitalWrite(pin_DC_B, LOW);
    analogWrite(pin_DC_A, Speed);
    delay(50);
  }
  else if (CW < 0 && CW >= -127) {
    digitalWrite(pin_DC_A, LOW);
    analogWrite(pin_DC_B, Speed);
    delay(50);
  }
  else if (CW > -127 && CW <= 128)
  {
    Serial1.println("-127 ~ 126 입력");
  }

  Serial1.println("-----------");
  Serial1.println("재입력");
}
}

