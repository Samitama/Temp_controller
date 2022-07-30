int ledPinleri[] = {2,3,4,5,6,7,8,9};
void setup() {
  for(int i=0;i<9;i++){
    pinMode(ledPinleri [i],OUTPUT); 
  }
}
void loop() {
  int p=analogRead(A0);
  p=map(p,0,1023,0,255);
  for(int i=0;i<9;i++){
    digitalWrite(ledPinleri [i],HIGH);
    delay(p);
    digitalWrite(ledPinleri [i],LOW);  
    }
}
