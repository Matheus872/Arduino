#include <LiquidCrystal.h>  
#include <Keypad.h>

void suita(char key, int pos);
void suitaquatro(char key, int pos, bool flag, String st, String nd, String rd, String th);
void suitacinco(char key, int pos, bool flag, String st, String nd, String rd, String th, String th2);

const byte rows = 4; 
const byte cols = 3; 
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[rows] = {46, 42, 44, 40}; 
byte colPins[cols] = {52, 50, 48}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

String vet[15];
int i=0, j=0, pos=0;
int flag = 0;
String st, nd, rd, th, th2;
char copia;

 
LiquidCrystal lcd(2,3,4,5,6,7);
int x;


void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);   
  lcd.home();                 
}
 
void loop(){

  flag = false;
  char key = keypad.getKey();
  if (key != NO_KEY){
    Serial.println(key);
    suita(key,0);
  }
}



void suitaquatro(char key, int pos, int flag, String st, String nd, String rd, String th){

  char k;  //guarda qual key foi pressionada
  int timer;  //guarda tempo decorrido para medir o 0.5s
  int timer2;
  
  switch(key){

    case '1': flag = 1;
    case '2': i=0;
      if(i==0){ 
        timer = millis(); //é pra começar a contar aqui;
        if(flag == 1){
            st.toUpperCase();
            nd.toUpperCase();
            rd.toUpperCase();
            th.toUpperCase();
            flag = 0;
        }
        if(pos==0){
          lcd.clear();
          lcd.print(st);
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print(st);
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){  //se foi precionada a mesma tecla em menos de 0.5s
            i++;  //muda para próxima letra da tecla
          }else{
          vet[pos] = st[0];; //grava no vetor
            pos++;
            suita(k, pos); //vai para próxima posição do vetor
          }
        }else{
          vet[pos] = st[0];;
          suita(k, pos+1);
        }
       }
      
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
        if(pos==0){
          lcd.clear();
          lcd.print(nd);
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print(nd);
        }
       k = keypad.waitForKey();
       timer2 = millis();
       if(k=='2'){
         if(timer2<1500+timer){
           i++;
         }else{
          vet[pos] = nd[0];;
           suita(k, pos+1);
         }
       }else{
          vet[pos] = nd[0];;
         suita(k, pos+1);
       }
      }
        
     
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
        if(pos==0){
          lcd.clear();
          lcd.print(rd);
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print(rd);
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
          vet[pos] = rd[0];;
            suita(k, pos+1);
          }
        }else{
          vet[pos] = rd[0];;
          suita(k, pos+1);
        }
       }
      
      
      if(i==3){
        timer = millis(); //é pra começar a contar aqui;
        if(pos==0){
          lcd.clear();
          lcd.print(th);
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print(th);
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
          vet[pos] = th[0];
            suita(k, pos+1);
          }
        }else{
          vet[pos] = th[0];;
          suita(k, pos+1);
        }
       }
      break;
  }
}

void suitacinco(char key, int pos, int flag, String st, String nd, String rd, String th, String th2){

  char k;  //guarda qual key foi pressionada
  int timer;  //guarda tempo decorrido para medir o 0.5s
  int timer2;
  
  switch(key){

    case '1': flag = 1;
    case '2': i=0;
      if(i==0){ 
        timer = millis(); //é pra começar a contar aqui;
        if(flag = true){
            st.toUpperCase();
            nd.toUpperCase();
            rd.toUpperCase();
            th.toUpperCase();
            flag = false;
        }
        if(pos==0){
          lcd.clear();
          lcd.print(st);
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print(st);
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){  //se foi precionada a mesma tecla em menos de 0.5s
            i++;  //muda para próxima letra da tecla
          }else{
          vet[pos] = st[0]; //grava no vetor
            pos++;
            suita(k, pos); //vai para próxima posição do vetor
          }
        }else{
          vet[pos] = st[0];
          suita(k, pos+1);
        }
       }
      
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
        if(pos==0){
          lcd.clear();
          lcd.print(nd);
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print(nd);
        }
       k = keypad.waitForKey();
       timer2 = millis();
       if(k=='2'){
         if(timer2<1500+timer){
           i++;
         }else{
          vet[pos] = nd[0];
           suita(k, pos+1);
         }
       }else{
          vet[pos] = nd[0];
         suita(k, pos+1);
       }
      }
        
     
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
        if(pos==0){
          lcd.clear();
          lcd.print(rd);
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print(rd);
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
          vet[pos] = rd[0];
            suita(k, pos+1);
          }
        }else{
          vet[pos] = rd[0];
          suita(k, pos+1);
        }
       }
      
      
      if(i==3){
        timer = millis(); //é pra começar a contar aqui;
        if(pos==0){
          lcd.clear();
          lcd.print(th);
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print(th);
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
          vet[pos] = th[0];
            suita(k, pos+1);
          }
        }else{
          vet[pos] = th[0];
          suita(k, pos+1);
        }
       }
      break;
      
       if(i==4){
        timer = millis(); //é pra começar a contar aqui;
        if(pos==0){
          lcd.clear();
          lcd.print(th);
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print(th);
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
          vet[pos] = th[0];
            suita(k, pos+1);
          }
        }else{
          vet[pos] = th[0];
          suita(k, pos+1);
        }
       }
      break;
  }
}

void suita(char key, int pos){
  Serial.println("Entrou na função suita");
  Serial.print("Variável key = ");
  Serial.println(key);
  Serial.print("Variável pos = ");
  Serial.println(pos); 
  Serial.print("Estado da flag:"); 
  Serial.println(flag);
  
      switch(key){
        Serial.println("Entrou no switch");
      case '1':flag = 1; break;
      case '2':suitaquatro(key, pos, flag, "2", "a", "b", "c"); break;
      case '3':suitaquatro(key, pos, flag, "3", "d", "e", "f"); break;
      case '4':suitaquatro(key, pos, flag, "4", "g", "h", "i"); break;
      case '5':suitaquatro(key, pos, flag, "5", "k", "k", "l"); break;
      case '6':suitaquatro(key, pos, flag, "6", "m", "n", "o"); break;
      case '7':suitacinco(key, pos, flag, "7", "p", "q", "r", "s"); break;
      case '8':suitaquatro(key, pos, flag, "8", "t", "u", "v"); break;
      case '9':suitacinco(key, pos, flag, "9", "w", "x", "y", "z"); break;
      case '*':break;
      case '0':break;
      case '#':asm volatile ("jmp 0"); break;
    }
}
