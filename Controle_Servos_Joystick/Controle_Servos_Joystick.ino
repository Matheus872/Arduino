#include<Servo.h>

int PServo1=11, PServo2=10, PServo3=6, PServo4=5;
int valx=0,valy=0, EstadoB = 0;
int Px=A0,Py=A1,PBotao=2;
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;

void setup() {
  
Serial.begin(9600);
Servo1.attach(PServo1);   //atribuindo cada porta ao seu respectivo servo
Servo2.attach(PServo2);
Servo3.attach(PServo3);
Servo4.attach(PServo4);
}

void loop() {
EstadoB=digitalRead(PBotao);  //lê se o botão está pressionado
valx = analogRead(Px);
valy = analogRead(Py);
delay(100);

valx=map(valx,0,1023,0,255);
valy=map(valy,0,1023,0,255);

Servo1.write(valx);
Servo2.write(valx);
Servo3.write(valy);
Servo4.write(valy);
delay(100);

 if(EstadoB==LOW){
  Servo1.write(30);
  Servo2.write(30);
  Servo3.write(30);
  Servo4.write(30);
  for(int k=30;k<145;k++){
    Servo1.write(k);
    Servo2.write(k);
    Servo3.write(k);
    Servo4.write(k);
    delay(20);
  }
  for(int k=145;k>30;k--){
    Servo1.write(k);
    Servo2.write(k);
    Servo3.write(k);
    Servo4.write(k);
    delay(20);
  }
 }

}
