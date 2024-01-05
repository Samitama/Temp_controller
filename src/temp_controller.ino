#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

float tempMin = 25.0;
float tempMax = 29.0;
int fan_hizi;
double line;


void setup() {
  pinMode(3, OUTPUT);
  lcd.begin();
  Serial.begin(9600);
}

void loop() {

  int temp = ((analogRead(A0) / 1023.0) * 5000) / 10.0;

  if ((temp >= tempMin) && (temp <= tempMax)) {
    fan_hizi = map(temp, tempMin, tempMax, 0, 255);
    analogWrite(3, fan_hizi);
  } else if (temp < tempMin) {
    fan_hizi = 0;
    digitalWrite(3, LOW);
  } else if (temp > tempMax) {
    fan_hizi = 255;
  }


  line = ((double)fan_hizi / 255) * 100;

  Serial.print(temp);
  Serial.print("\t");
  Serial.println(fan_hizi);


  lcd.clear();
  lcd.home();
  lcd.setCursor(2, 0);
  lcd.print(temp);
  lcd.print(" derece");
  lcd.setCursor(2, 1);
  lcd.print(line);
  lcd.print("% ");
  delay(500);
}

