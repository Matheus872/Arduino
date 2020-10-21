#include <Keypad.h> //INCLUSÃO DE BIBLIOTECA
 
const byte qtdLinhas = 4; //QUANTIDADE DE LINHAS DO TECLADO
const byte qtdColunas = 4; //QUANTIDADE DE COLUNAS DO TECLADO
 
//CONSTRUÇÃO DA MATRIZ DE CARACTERES
char matriz_teclas[qtdLinhas][qtdColunas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
 
byte PinosqtdLinhas[qtdLinhas] = {3, 4, 5, 6}; //PINOS UTILIZADOS PELAS LINHAS
byte PinosqtdColunas[qtdColunas] = {31, 33, 35,37}; //PINOS UTILIZADOS PELAS COLUNAS

int t1=45;
int t2=47;
int t3=49;

//INICIALIZAÇÃO DO TECLADO
Keypad teclado = Keypad( makeKeymap(matriz_teclas), PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas); 
 
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  Serial.println("Aperte uma tecla..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(); //QUEBRA UMA LINHA NO MONITOR SERIAL

  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(t3, OUTPUT);
}
  
void loop(){
  char tecla_pressionada = teclado.getKey(); //VERIFICA SE ALGUMA DAS TECLAS FOI PRESSIONADA
  
  if (tecla_pressionada=='1'){ //SE ALGUMA TECLA FOR PRESSIONADA, FAZ
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
    digitalWrite(t1, HIGH);
    digitalWrite(t2,LOW);
    digitalWrite(t3,LOW);
    delay(10);
  }

  if(tecla_pressionada=='2')
  {
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
    digitalWrite(t1, LOW);
    digitalWrite(t2,HIGH);
    digitalWrite(t3,LOW);
    delay(10);
  }

    if(tecla_pressionada=='3')
  {
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
    digitalWrite(t1, LOW);
    digitalWrite(t2,LOW);
    digitalWrite(t3,HIGH);
    delay(10);
  }

    if(tecla_pressionada=='4')
  {
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
    digitalWrite(t1, HIGH);
    digitalWrite(t2,HIGH);
    digitalWrite(t3,LOW);
    delay(10);
  }

    if(tecla_pressionada=='5')
  {
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
    digitalWrite(t1, HIGH);
    digitalWrite(t2,LOW);
    digitalWrite(t3,HIGH);
    delay(10);
  }

    if(tecla_pressionada=='6')
  {
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
    digitalWrite(t1, LOW);
    digitalWrite(t2,HIGH);
    digitalWrite(t3,HIGH);
    delay(10);
  }

    if(tecla_pressionada=='7')
  {
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
    digitalWrite(t1, HIGH);
    digitalWrite(t2,HIGH);
    digitalWrite(t3,HIGH);
    delay(10);
  }

    if(tecla_pressionada=='8')
  {
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
    digitalWrite(t1, LOW);
    digitalWrite(t2,LOW);
    digitalWrite(t3,LOW);
    delay(10);
  }

    if(tecla_pressionada=='0')
  {
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
    digitalWrite(t1, HIGH);
    digitalWrite(t2,LOW);
    digitalWrite(t3,LOW);
    delay(1000);

    digitalWrite(t1, HIGH);
    digitalWrite(t2,HIGH);
    digitalWrite(t3,LOW);
    delay(1000);

    digitalWrite(t1, HIGH);
    digitalWrite(t2,HIGH);
    digitalWrite(t3,HIGH);
    delay(1000);

    digitalWrite(t1, LOW);
    digitalWrite(t2,HIGH);
    digitalWrite(t3,HIGH);
    delay(1000);

    digitalWrite(t1, LOW);
    digitalWrite(t2,LOW);
    digitalWrite(t3,HIGH);
    delay(1000);

    digitalWrite(t1, LOW);
    digitalWrite(t2,LOW);
    digitalWrite(t3,LOW);
    delay(1000);
  }
}
