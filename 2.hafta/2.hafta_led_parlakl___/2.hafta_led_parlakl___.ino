void setup() {
  pinMode(3,OUTPUT);
}

void loop() {
  int p=analogRead(A0);
  p=map(p,0,1023,0,255);
  analogWrite(3,p);
}
