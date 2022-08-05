void setup()
{
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop()
{
 	int a = analogRead(A0);
  	a=map(a,0,1023,0,255);
  int b = analogRead(A1);
    b=map(b,0,1023,0,255);
    analogWrite(3,a);
    analogWrite(5,b);
}