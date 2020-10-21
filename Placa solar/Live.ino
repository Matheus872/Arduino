#include <Servo.h>

int ldr1=A0, ldr2=A1, ldr3=A2, ldr4=A3;
int l1, l2, l3, l4;
int i;
int aservo, auxs=0;
Servo right;
Servo left;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left.attach(13);
  right.attach(12);
  for(i;i>0;i--){
    right.write(i);
    left.write(150-i);
  }
  delay(20);
}

void loop() {
  // put your main code here, to run repeatedly:

  l1 = analogRead(ldr1); //Valor leitura ldr 1 (entre 0 e 1023).
  l2 = analogRead(ldr2); //Valor leitura ldr 2
  l3 = analogRead(ldr3); //Valor leitura ldr3
  l4 = analogRead(ldr4); //Valor leitura ldr4
  if(l1>l4){
    right.write(i+1);
    left.write(i+1);
  delay(20);
  }
  
  if(l4>l1){
    right.write(i+1);
    left.write(i+1);
  delay(20);
  }

  Serial.println(l1);Serial.println( l4);
  Serial.println();
 }
 
