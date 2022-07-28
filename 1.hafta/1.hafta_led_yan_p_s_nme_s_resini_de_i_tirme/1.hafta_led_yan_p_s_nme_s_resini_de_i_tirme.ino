unsigned long lasttime=0;
int sure=500;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
}

void loop() {
  if(millis()-lasttime>=sure){
    digitalWrite(2,!digitalRead(3));
    lasttime=millis();
  }
 if(digitalRead(3)==HIGH){
   sure=sure+250;
 if(sure>2000){
    sure=500;
 }
 }
  Serial.println(sure);
}
