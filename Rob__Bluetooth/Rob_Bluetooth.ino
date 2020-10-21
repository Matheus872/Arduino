#include<Ultrasonic.h>       //importando biblioteca do Sensor ultrasssônico
#define pino_trigger 4        // Definindo pino do trigger em 4 e do echo em 5
#define pino_echo 5
int escolha=0,opcao,n1=1,n2=1,n3=1,n4=1, bl=1;
int IN1=11,IN2=10,IN3=9,IN4=8,Br=2,Vm=3;  // declarando variáveis inteiras
float cm;                                 // declarando variável de distância em cm

Ultrasonic ultrasonic(pino_trigger,pino_echo); // definindo os pinos do objeto ultrasonic

void esquivador(){
  
  long microsec=ultrasonic.timing();        // declarando a variável microsec, sendo o tempo que o sensor ultrassônico leva para emitir um sinal e receber ele por completo
  cm = ultrasonic.convert(microsec,Ultrasonic::CM);  // realiza o cálculo da distância em cm com base no tempo em microsegundos
  if (cm<20){                 //Se a distância detectada for menor que 20 cm faz o seguinte
    Serial.println("Obstaculo à frente");
    digitalWrite(IN1,HIGH);     //IN1 e IN2 em HIGH Trava o motor A (freio)
    digitalWrite(IN2,HIGH);    
    digitalWrite(IN3,HIGH);     //IN3 e IN4 em HIGH Trava o motor B (freio)
    digitalWrite(IN4,HIGH);
    digitalWrite(Vm,HIGH);      // Liga o Led vermelho
    delay(500);                // continua no mesmo estado por 500 milissegundos

    digitalWrite(Vm,LOW);       // Desliga o Led vermelho
    digitalWrite(IN1,LOW);      // IN1 em LOW e IN2 em HIGH motor A sentido inverso (Ré)
    digitalWrite(IN2,HIGH);     
    digitalWrite(IN3,LOW);      // IN3 em LOW e IN4 em HIGH motor B sentido inverso (Ré)
    digitalWrite(IN4,HIGH);
    digitalWrite(Br,HIGH);      // Acende o Led branco
    delay(500);                 // continua no mesmo estado por 500 milissegundos

    digitalWrite(IN1,LOW);      // IN1 em LOW e IN2 em HIGH motor A sentido inverso 
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);     // IN3 em LOW e IN4 em HIGH motor B sentido direto (motores girando em sentidos opostos alterando a direção do robô)
    digitalWrite(IN4,LOW);
    delay(175);

    digitalWrite(Br,LOW);      // Desliga o Led Branco
  }else{                     
    digitalWrite(IN1,HIGH);   // IN1 em HIGH e IN2 em LOW motor A sentido direto (Robô em frente)
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);   // IN3 em HIGH e IN4 em LOW motor A sentido direto (Robô em frente)
    digitalWrite(IN4,LOW);
  }
}

void controleB(){
  bl = 0;
  opcao=Serial.read()-'0';
  switch(opcao){
    case 5: // Aciona o Freio.
        digitalWrite(Br,LOW);      // Apaga o Led branco  
        digitalWrite(IN1,HIGH);     //IN1 e IN2 em HIGH Trava o motor A (freio)
        digitalWrite(IN2,HIGH);    
        digitalWrite(IN3,HIGH);     //IN3 e IN4 em HIGH Trava o motor B (freio)
        digitalWrite(IN4,HIGH);
        digitalWrite(Vm,HIGH);      // Liga o Led vermelho       
    break;
    case 6: 
      n1++;
      if(n1%2==0){               //  vai para frente até que aperte o botão para cima novamente
        Serial.println("Em frente");
        digitalWrite(Vm,LOW);       // Desliga o Led vermelho
        digitalWrite(IN1,HIGH);   // IN1 em HIGH e IN2 em LOW motor A sentido direto (Robô em frente)
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,HIGH);   // IN3 em HIGH e IN4 em LOW motor A sentido direto (Robô em frente)
        digitalWrite(IN4,LOW);
      }else{
        Serial.println("Em Espera");
        digitalWrite(IN1,HIGH);     //IN1 e IN2 em HIGH Trava o motor A (freio)
        digitalWrite(IN2,HIGH);    
        digitalWrite(IN3,HIGH);     //IN3 e IN4 em HIGH Trava o motor B (freio)
        digitalWrite(IN4,HIGH);
        digitalWrite(Vm,HIGH);      // Liga o Led vermelho
      }
    break;
    
    case 7:
      n2++;
      if(n2%2==0){               //  vai para trás até que aperte o botão para baixo novamente
        Serial.println("Para Tras");
        digitalWrite(Vm,LOW);       // Desliga o Led vermelho
        digitalWrite(IN1,LOW);      // IN1 em LOW e IN2 em HIGH motor A sentido inverso (Ré)
        digitalWrite(IN2,HIGH);     
        digitalWrite(IN3,LOW);      // IN3 em LOW e IN4 em HIGH motor B sentido inverso (Ré)
        digitalWrite(IN4,HIGH);
        digitalWrite(Br,HIGH);      // Acende o Led branco
      }else{
        Serial.println("Em Espera");
        digitalWrite(Br,LOW);      // Apaga o Led branco  
        digitalWrite(IN1,HIGH);     //IN1 e IN2 em HIGH Trava o motor A (freio)
        digitalWrite(IN2,HIGH);    
        digitalWrite(IN3,HIGH);     //IN3 e IN4 em HIGH Trava o motor B (freio)
        digitalWrite(IN4,HIGH);
        digitalWrite(Vm,HIGH);      // Liga o Led vermelho
      }
    break;
    case 8://  vira 90° para a esquerda
        Serial.println("Virando à Esquerda");
        digitalWrite(Vm,LOW);       // Desliga o Led vermelho
        digitalWrite(IN1,LOW);      // IN1 em LOW e IN2 em HIGH motor A sentido inverso (Ré)
        digitalWrite(IN2,HIGH);     
        digitalWrite(IN3,HIGH);      // IN3 em HIGH e IN4 em LOW motor B sentido Direto 
        digitalWrite(IN4,LOW);
        delay(200);
        digitalWrite(Br,LOW);      // Apaga o Led branco  
        digitalWrite(IN1,HIGH);     //IN1 e IN2 em HIGH Trava o motor A (freio)
        digitalWrite(IN2,HIGH);    
        digitalWrite(IN3,HIGH);     //IN3 e IN4 em HIGH Trava o motor B (freio)
        digitalWrite(IN4,HIGH);
        digitalWrite(Vm,HIGH);      // Liga o Led vermelho 
    break;
    case 9://  vira 90° para a direita
        Serial.println("Virando à Direita");
        digitalWrite(Vm,LOW);       // Desliga o Led vermelho
        digitalWrite(IN1,HIGH);      // IN1 em HIGH e IN2 em LOW motor A sentido Direto
        digitalWrite(IN2,LOW);     
        digitalWrite(IN3,LOW);      // IN3 em LOWe IN4 em HIGH motor B sentido inverso (Ré) 
        digitalWrite(IN4,HIGH);
        delay(200);
        digitalWrite(Br,LOW);      // Apaga o Led branco  
        digitalWrite(IN1,HIGH);     //IN1 e IN2 em HIGH Trava o motor A (freio)
        digitalWrite(IN2,HIGH);    
        digitalWrite(IN3,HIGH);     //IN3 e IN4 em HIGH Trava o motor B (freio)
        digitalWrite(IN4,HIGH);
        digitalWrite(Vm,HIGH);      // Liga o Led vermelho             
    break;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);                     // Definindo modo das portas como saídas
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(Br,OUTPUT);
  pinMode(Vm,OUTPUT);
  Serial.println("Escolha o Modo de funcionamento do Robo: '1' para modo Esquivador ou '2' para modo de controle bluetooth ");

}

void loop () {

  int opc=Serial.read()-'0';
  if(opc==1){
    escolha=1;
    Serial.println("Modo Esquivador ativado! ");  
  }
  else if(opc==2){
    Serial.println("Modo de Controle Bluetooth Ativado!");
    escolha=2;
  }
  if(escolha==1){                // Modo esquivador
    bl=1;
    esquivador();
  }else if(escolha==2){
    if(bl==1){
      digitalWrite(IN1,HIGH);     //IN1 e IN2 em HIGH Trava o motor A (freio)
      digitalWrite(IN2,HIGH);    
      digitalWrite(IN3,HIGH);     //IN3 e IN4 em HIGH Trava o motor B (freio)
      digitalWrite(IN4,HIGH);
    }
    digitalWrite(Vm,LOW);       // Desliga o Led vermelho
    digitalWrite(Br,HIGH);      // Liga o Led Branco 
    delay(100);
    digitalWrite(Vm,HIGH);      // Liga o Led Vermelho 
    digitalWrite(Br,LOW);       // Desliga o Led Branco
    delay(100);
    digitalWrite(Vm,HIGH);      // Liga o Led Vermelho 
    digitalWrite(Br,HIGH);      // Liga o Led Branco 
    delay(100);
    digitalWrite(Vm,LOW);       // Desliga o Led vermelho
    digitalWrite(Vm,LOW);       // Desliga o Led Branco
    controleB();
  }
}
