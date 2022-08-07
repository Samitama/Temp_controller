#include <Servo.h>
Servo motor;
void setup()
{
  motor.attach(11);
}

void loop()
{
 	int a = analogRead(A0);
  	a=map(a,0,1023,0,180);
  	motor.write(a);
}