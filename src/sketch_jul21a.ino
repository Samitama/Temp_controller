#include <LiquidCrystal.h>
LiquidCrystal lcd(10,9,7,6,5,4);

float tempMin = 30.0;
float tempMax = 35.5;
int fan_hizi; 
void setup() {
  pinMode(3,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  
  float temp = ((analogRead(A0)/1023.0)*5000)/10.0;

  Serial.print(temp);
  Serial.print("\t");
  Serial.println(fan_hizi);
  if((temp >= tempMin) && (temp <=tempMax)){
    fan_hizi = map(temp,tempMin,tempMax,0,255);
    analogWrite(3,fan_hizi);
  }
  else if(temp < tempMin){
    fan_hizi=0;
    digitalWrite(3,LOW);
  }

  lcd.clear();
  lcd.home();
  lcd.setCursor(2,0); 
  lcd.print(temp);
  lcd.print(" derece");
  lcd.setCursor(0,1); 
  lcd.print(fan_hizi);
  lcd.print("% ");
  delay(1000);
}
