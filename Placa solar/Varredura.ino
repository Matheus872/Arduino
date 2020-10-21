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
    delay(20);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i;i>0;i--){
    right.write(60+i);
    left.write(120-i);
    delay(20);
  }
  auxs = 0;
  
  for(i;i<150;i++){
    l1 = analogRead(ldr1); //Valor leitura ldr 1 (entre 0 e 1023).
    l2 = analogRead(ldr2); //Valor leitura ldr 2
    l3 = analogRead(ldr3); //Valor leitura ldr3
    l4 = analogRead(ldr4); //Valor leitura ldr4
    right.write(60+i);
    left.write(150-i);
    Serial.println("Valor leitura ldr na subida: "); Serial.println(l1+l2+l3+l4);
    if(l1+l2+l3+l4<auxs){
      aservo = right.read();
      auxs = l1+l2+l3+l4;
    }
    delay(20);
  }

  for(i;i>0;i--){
    l1 = analogRead(ldr1); //Valor leitura ldr 1 (entre 0 e 1023).
    l2 = analogRead(ldr2); //Valor leitura ldr 2
    l3 = analogRead(ldr3); //Valor leitura ldr3
    l4 = analogRead(ldr4); //Valor leitura ldr4
    right.write(i);
    left.write(150-i);
    if(l1+l2+l3+l4<auxs){
      aservo = i;
      auxs = l1+l2+l3+l4;
    }
    delay(20);
  }

  Serial.println(auxs);
  Serial.println(aservo);
  delay(1000);

  for(i;i<=aservo;i++){
    right.write(i);
    left.write(150-i);
    delay(20);
  }
  
  delay(5000);
}
