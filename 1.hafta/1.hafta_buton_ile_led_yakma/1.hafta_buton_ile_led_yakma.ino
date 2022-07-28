void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);

}

void loop() {
 
 if(digitalRead(3)==HIGH){
  digitalWrite(2,HIGH);
 }
 else if(digitalRead(3)==LOW){
  digitalWrite(2,LOW);
 }
}
