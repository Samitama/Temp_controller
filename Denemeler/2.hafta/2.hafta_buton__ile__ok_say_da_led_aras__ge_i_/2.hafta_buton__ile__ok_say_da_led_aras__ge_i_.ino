void setup() {
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,INPUT);
 Serial.begin(9600);
}
void loop() {
  for(int i=2;i<=9;){
    Serial.println(i);
    digitalWrite(i,HIGH);
    delay(200);
     if(digitalRead(10)==HIGH){
    digitalWrite(i,LOW);
    delay(200);
    i++;
    if(i==10){
      i=2;  
    }
  } 
  }
}
