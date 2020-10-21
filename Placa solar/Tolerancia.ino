#include <Servo.h>

Servo myservo;
Servo myservo2;

int pos = 90;   // Posição inicial
int sens1 = A0; // LRD 1
int sens2 = A3; //LDR 2
int tolerancia = 2;

void setup(){
  myservo.attach(12);  //Liga o pino ao objeto servo
  myservo2.attach(13); 
  pinMode(sens1, INPUT);
  pinMode(sens2, INPUT);
  myservo.write(pos);
  myservo2.write(150-pos);
  delay(2000);
}

void loop() {
  int val1 = analogRead(sens1);
  int val2 = analogRead(sens2);
  
  if(val1-val2<=tolerancia||val2-val1<=tolerancia{}
  else{
    if(val1 > val2){ 
      pos = pos*(-1); 
    }
    if(val1 < val2){
      pos = ++pos; 
    }
  }
  
  if(pos > 180){
    pos = 180; 
  } 

  if(pos < 0) {
    pos = 0; 
  } 
  
  myservo.write(pos);
  myservo2.write(150-pos);
  delay(50);

}
