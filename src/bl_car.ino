#define ENA 9
#define IN1 4
#define IN2 5
#define ENB 10
#define IN3 3
#define IN4 2
char veri[15];
int PWM = 100;
unsigned long currentMillis;
unsigned long startMillis;
const unsigned long period=500;
void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  startMillis = millis();
}

void loop() {
  int i=0;
  currentMillis = millis(); 
  if (currentMillis - startMillis >= period){
    if(Serial.available()>0){
      while (Serial.available() > 0) {
        veri[i] = (char)Serial.read();
        i++;
      }
    veri[i]='\0';
    Motor_Protocol(veri);
    } 
  }
}

void dur(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void Motor_Protocol(char inStr[]){   
  int i;
  int m;
  Serial.println(inStr);
  
  if(!strcmp(inStr,"forward")){      
    dur();
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, PWM);
    analogWrite(ENB, PWM);
    Serial.println("İlerliyorum");
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}
       
  else if(!strcmp(inStr,"right")){    
    dur();
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, PWM);
    analogWrite(ENB, PWM);
    Serial.println("Sağa dönüyorum");
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}
   
  else if(!strcmp(inStr,"left")){      
    dur();
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, PWM);
    analogWrite(ENB, PWM);
    Serial.println("Sola dönüyorum");
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;
    }

  else if(!strcmp(inStr, "stop")){
    dur();
    Serial.println("Durdum");
    for (m=0; m<11; m++) {
    inStr[m]=0;}
    i=0;}

  else if(!strcmp(inStr, "back")){
    dur();
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, PWM);
    analogWrite(ENB, PWM);
    Serial.println("Geriye gidiyorum");
    for (m=0; m<11; m++) {
    inStr[m]=0;}
    i=0;}
  

    else if(!strcmp(inStr, "pwm+")){
    PWM+=50;
    if(PWM>255){PWM=255;}
    analogWrite(ENA, PWM);
    analogWrite(ENB, PWM);
    Serial.println("Hızlanıyorum");
    for (m=0; m<11; m++) {
    inStr[m]=0;}
    i=0;}

  else if(!strcmp(inStr, "pwm-")){
    PWM-=50;
    if(PWM<0){PWM=0;}
    analogWrite(ENA, PWM);
    analogWrite(ENB, PWM);
    Serial.println("Yavaşlıyorum");
    for (m=0; m<11; m++) {
    inStr[m]=0;}
    i=0;}

    else{
    dur();
    for(m=0;m<11;m++){
      inStr[m]=0;}
    i=0;}
}

