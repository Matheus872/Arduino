  #include<Servo.h>
  
  int PServo1=5; //Definindo os pinos de saída PWM e os relacionando com servos
  int PServo2=6;
  int PServo3=10;
  int PServo4=11;
  int d = 10; //Delay entre cada movimento dos Servos
  int p1, p2, p3, p4; //Grau de inclinação de cada Servo
  int valx=0,valy=0,EstadoB=0; //Armazenamento dos dados da leitura das posições do Joystick
  int Px=A0,Py=A1,PBotao=3; //Atribuindo cada eixo do Joystick a sua respectiva porta
  
  Servo servo1; // Define os servos como objetos Servo 
  Servo servo2;
  Servo servo3;
  Servo servo4;

  //Função de cada passo
  void passo1(){
    
    for(p3; p3>=30;p3--){
      servo3.write(p3);
      servo4.write(p4--);
      delay(d);
    }

    for(p3; p3<=85;p3++){
      servo3.write(p3);
      servo4.write(p4++);
      delay(d);
    }

    for(p3; p3<=145;p3++){
      servo3.write(p3);
      servo4.write(p4++);
      delay(d);
    }

    for(p3;p3>=85;p3--){
      servo3.write(p3);
      servo4.write(p4--);
      delay(d);
    }
    
    do{
      if(p3>=30 && p4<=145){
        servo3.write(p3--);
        servo4.write(p4++);
      } else if(p3<30 && p4<=145){
        servo4.write(p4++);
      } else if(p3>=30 && p4>145){
        servo3.write(p3--);
      }
      delay(d);
    }while(p3>=30 || p4<=145);

    do{
      if(p3<=85 && p4>=85){
        servo3.write(p3++);
        servo4.write(p4--);
      } else if(p3>85 && p4>=85){
        servo4.write(p4--);
      } else if(p3<=85 && p4<85){
        servo3.write(p3++);
      }
      delay(d);
    }while(p3<=85 || p4>=85);

    delay(d);
  }

 void passo2(){
    do{
      if(p1<=145 && p2>=30){
        servo1.write(p1++);
        servo2.write(p2--);
      } else if(p1>145 && p2>=30){
        servo2.write(p2--);
      } else if(p1<=145 && p2<30){
        servo1.write(p1++);
      }
      delay(d);
    }while(p1<=145 || p2>=30);

    do{
      if(p1>=85 && p2<=85){
        servo1.write(p1--);
        servo2.write(p2++);
      } else if(p1<85 && p2<=85){
        servo2.write(p2++);
      } else if(p1>=85 && p2>85){
        servo1.write(p1--);
      }
      delay(d);
    }while(p1>=85 || p2<=85);

    do{
      if(p2<=145 && p1>=30){
        servo2.write(p2++);
        servo1.write(p1--);
      } else if(p2>145 && p1>=30){
        servo1.write(p1--);
      } else if(p2<=145 && p2<30){
        servo2.write(p2++);
      } else {
        break;
      }
      delay(d);
    }while(p2<145 || p1>30);

    do{
      if(p2>=85 && p1<=85){
        servo2.write(p2--);
        servo1.write(p1++);
      } else if(p2<85 && p1<=85){
        servo1.write(p1++);
      } else if(p2>=85 && p1>85){
        servo2.write(p2--);
      }
      delay(d);
    }while(p2>=85 || p1<=85);

    for(p1;p1>=30;p1--){
      servo1.write(p1);
      servo2.write(p2--);
      delay(d);
    }

    for(p1;p1<=85;p1++){
      servo1.write(p1);
      servo2.write(p2++);
      delay(d);
    }

    for(p1;p1<=145;p1++){
      servo1.write(p1);
      servo2.write(p2++);
      delay(d);
    }

    for(p1;p1>=85;p1--){
      servo1.write(p1);
      servo2.write(p2--);
      delay(d);
    }
 }

 void passo3(){
    for(p1;p1>=30;p1--){
      servo1.write(p1);
      servo3.write(p3--);
      delay(d);
    }

    for(p1;p1<=85;p1++){
      servo1.write(p1);
      servo3.write(p3++);
      delay(d);
    }

    for(p2;p2<=145;p2++){
      servo2.write(p2);
      servo4.write(p4++);
      delay(d);
    }

    for(p2;p2>=85;p2--){
      servo2.write(p2);
      servo4.write(p4--);
      delay(d);
    }

    for(p1;p1<=145;p1++){
      servo1.write(p1);
      servo3.write(p3++);
      delay(d);
    }

    for(p1;p1>=85;p1--){
      servo1.write(p1);
      servo3.write(p3--);
      delay(d);
    }

    for(p2;p2>=30;p2--){
      servo2.write(p2);
      servo4.write(p4--);
      delay(d);
    }

    for(p2;p2<=85;p2++){
      servo2.write(p2);
      servo4.write(p4++);
      delay(d);
    }    
 }

 void passo4(){
    do{
      if(p1>=30 && p4<=145){
        servo1.write(p1--);
        servo4.write(p4++); 
      } else if(p1<30 && p4<=145){
        servo4.write(p4++);
      } else if(p1>=30 && p4>145){
        servo1.write(p1--);
      }
      delay(d);
    }while(p1>=30 && p4<=145);

    do{
      if(p1<=85 && p4>=85){
        servo1.write(p1++);
        servo4.write(p4--);
      } else if(p1>85 && p4>=85){
        servo4.write(p4--);
      } else if(p1<=85 && p4<85){
        servo1.write(p1++);
      }
      delay(d);
    }while(p1<=85 && p4>=85);

    do{
      if(p2<=145 && p3>=30){
        servo2.write(p2++);
        servo3.write(p3--);
      } else if(p2>145 && p3>=30){
        servo3.write(p3--);
      } else if(p2<=145 && p3<30){
        servo2.write(p2++);
      }
      delay(d);
    }while(p2<=145 && p3>=30);

    do{
      if(p2>=85 && p3<=85){
        servo2.write(p2--);
        servo3.write(p3++);
      } else if(p2<85 && p3<=85){
        servo3.write(p3++);
      } else if(p2>=85 && p3>85){
        servo2.write(p2--);
      }
      delay(d);
    }while(p2>=85 && p3<=85);
 }

 void lp5(Servo servo, int del){ //Função que será executada para cada servo no passo5.
    servo.write(145);
    delay(del);
    servo.write(85);
    delay(del);
    servo.write(30);
    delay(del);
    servo.write(85);
    delay(del);
 }

 void passo5(){
    lp5(servo1, 600); //Chamando a função lp5 para cada servo.
    lp5(servo2, 600);
    lp5(servo3, 600);
    lp5(servo4, 600);
 }


void setup() {
  Serial.begin(9600); //Iniciando a Interface Serial

  servo1.attach(PServo1); // relaciona cada servo com seu respectivo pino digital
  servo2.attach(PServo2);
  servo3.attach(PServo3);
  servo4.attach(PServo4);

}

void loop() {
    p1 = 85; //Definindo a inclinação inicial de cada servo, em graus.
    p2 = 85;
    p3 = 85;
    p4 = 85;    
    servo1.write(p1); //Atribuindo a cada servo sua inclinação inicial.
    servo2.write(p2);
    servo3.write(p3);
    servo4.write(p4);
    valx = analogRead(Px); //Leitura de cada eixo do Joystick
    valy = analogRead(Py);
    EstadoB=digitalRead(PBotao);
    delay(125);
    valx=map(valx,0,1023,0,255); //Transformando o valor lido de cada eixo (0-1023) para um valor no raio de 0-255
    valy=map(valy,0,1023,0,255);
  if(valx<120 && valy>120 && valy <130){ //Verificando a posição de cada eixo do Joystick para que seja realizado seu respectivo passo
    passo1();
  } else if(valx>130 && valy>120 && valy<130){
    passo2();
  } else if(valy<120 && valx>120 && valx<130){
    passo3();
  } else if(valy>130 && valx>120 && valx<130){
    passo4();
  } else if(EstadoB==LOW){
    passo1();
    passo2();
    passo3();
    passo4();
    passo5();
  }
  
}
