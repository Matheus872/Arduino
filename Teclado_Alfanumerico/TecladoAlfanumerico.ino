#include <LiquidCrystal.h>  
#include <Keypad.h>


void suita(char key, int pos);


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

char vet[15];
int i=0, j=0;

 
LiquidCrystal lcd(2,3,4,5,6,7);
int x;

 
byte inter[8] = {
  B11111,
  B00000,
  B11111,
  B00000,
  B11111,
  B00000,
  B11111,
  B00000,
};
 
byte ex[8] = {
  B00000,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000,
  B00100,
};

/*byte cifra[8] = {
  B00100,
  B11111,
  B10100,
  B11111,
  B00101
  B00101,
  B11111,
  B00100,
};*/
 
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);   
          
  lcd.createChar(0, inter);  
  lcd.createChar(1, ex);
//  lcd.createChar(2, cifra);  
  
  lcd.home();                 
}
 
void loop(){
char key;
x = digitalRead(8);
Serial.println(x);

do{
 key = keypad.getKey();
 lcd.noCursor();
  delay(500);
  // Turn on the cursor:
  lcd.cursor();
  delay(500);
}while(key = NO_KEY);


    Serial.println(key);
    suita(key, 0);  

}

void suita(char key, int pos){

  char k;  //guarda qual key foi pressionada
  int timer;  //guarda tempo decorrido para medir o 0.5s
  int timer2;
  
  switch(key){
    case '2': i=0;
      if(i==0){ 
        timer = millis(); //é pra começar a contar aqui;
        if(pos==0){
          lcd.clear();
          lcd.print("a");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("a");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){  //se foi precionada a mesma tecla em menos de 0.5s
            i++;  //muda para próxima letra da tecla
          }else{
            vet[pos] = 'a'; //grava no vetor
            suita(k, pos+1); //vai para próxima posição do vetor
          }
        }else{
          vet[pos] = 'a';
          suita(k, pos+1);
        }
       }
      
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("b");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("b");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'b';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'b';
          suita(k, pos+1);
        }
       }
        
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("c");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("c");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='2'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
            vet[pos] = 'c';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'c';
          suita(k, pos+1);
        }
       }
      break;
//**************************************************************************************************************
      case '3': i=0;
      if(i==0){
        timer = millis(); //é pra começar a contar aqui;
       if(pos==0){
          lcd.clear();
          lcd.print("d");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("d");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='3'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'd';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'd';
          suita(k, pos+1);
        }
       }
//-----------------------------------------------------------------     
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("e");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("e");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='3'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'e';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'e';
          suita(k, pos+1);
        }
       }
//------------------------------------------------------------------      
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("f");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("f");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='3'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
            vet[pos] = 'f';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'f';
          suita(k, pos);
        }
       }
      break;
//************************************************************************************************************

      case '4': i=0;
      if(i==0){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("g");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("g");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='4'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'g';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'g';
          suita(k, pos+1);
        }
       }
//-----------------------------------------------------------------     
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("h");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("h");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='4'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'h';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'h';
          suita(k, pos+1);
        }
       }
//------------------------------------------------------------------      
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("i");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("i");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='4'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
            vet[pos] = 'i';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'i';
          suita(k, pos+1);
        }
       }
      break;
//************************************************************************************************************   
      case '5': i=0;
      if(i==0){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("j");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("j");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='5'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'j';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'j';
          suita(k, pos+1);
        }
       }
//-----------------------------------------------------------------     
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("k");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("k");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='5'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'k';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'k';
          suita(k, pos+1);
        }
       }
//------------------------------------------------------------------      
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("l");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("l");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='5'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
            vet[pos] = 'l';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'l';
          suita(k, pos+1);
        }
       }
      break;
//************************************************************************************************************
      case '6': i=0;
      if(i==0){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("m");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("m");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='6'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'm';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'm';
          suita(k, pos+1);
        }
       }
//-----------------------------------------------------------------     
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
         if(pos==0){
          lcd.clear();
          lcd.print("n");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("n");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='6'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'n';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'n';
          suita(k, pos+1);
        }
       }
//------------------------------------------------------------------      
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
       if(pos==0){
          lcd.clear();
          lcd.print("o");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("o");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='6'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
            vet[pos] = 'o';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'o';
          suita(k, pos+1);
        }
       }
      break;
//************************************************************************************************************   
      case '7': i=0;
      if(i==0){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("p");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("p");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='7'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'p';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'p';
          suita(k, pos+1);
        }
       }
//-----------------------------------------------------------------     
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("q");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("q");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='7'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'q';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'q';
          suita(k, pos+1);
        }
       }
//------------------------------------------------------------------      
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
       if(pos==0){
          lcd.clear();
          lcd.print("r");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("r");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='7'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'r';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'r';
          suita(k, pos+1);
        }
       }

       if(i==3){
        timer = millis(); //é pra começar a contar aqui;
        if(pos==0){
          lcd.clear();
          lcd.print("s");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("s");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='7'){
         if(timer2<1500+timer){
           i=0;
           suita(k, pos);
         }else{
           vet[pos] = 's';
           suita(k, pos+1);
         }
         }else{
          vet[pos] = 's';
          suita(k, pos+1);
         }
       }
      break;
//************************************************************************************************************
      case '8': i=0;
      if(i==0){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("t");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("t");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='8'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 't';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 't';
          suita(k, pos+1);
        }
       }
//-----------------------------------------------------------------     
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("u");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("u");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='8'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'u';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'u';
          suita(k, pos+1);
        }
       }
//------------------------------------------------------------------      
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("v");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("v");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='8'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
            vet[pos] = 'v';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'v';
          suita(k, pos+1);
        }
       }
      break;
//*************************************************************************************************************
      case '9': i=0;
      if(i==0){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("w");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("w");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='9'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'w';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'w';
          suita(k, pos+1);
        }
       }
//-----------------------------------------------------------------     
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("x");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("x");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='9'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'x';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'x';
          suita(k, pos+1);
        }
       }
//------------------------------------------------------------------      
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("y");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("y");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='9'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = 'y';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = 'y';
          suita(k, pos+1);
        }
       }

       if(i==3){
        timer = millis(); //é pra começar a contar aqui;
       if(pos==0){
          lcd.clear();
          lcd.print("z");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("z");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='9'){
         if(timer2<1500+timer){
           i=0;
           suita(k, pos);
         }else{
           vet[pos] = 'z';
           suita(k, pos+1);
         }
         }else{
          vet[pos] = 'z';
          suita(k, pos+1);
         }
       }
      break;
//************************************************************************************************************
    case '*': i=0;
      if(i==0){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("/");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("/");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='*'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = '/';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = '/';
          suita(k, pos+1);
        }
       }
      
      if(i==1){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.print("!");
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.print("!");
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='*'){
          if(timer2<1500+timer){
            i++;
          }else{
            vet[pos] = '!';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = '!';
          suita(k, pos+1);
        }
       }
        
      if(i==2){
        timer = millis(); //é pra começar a contar aqui;
      if(pos==0){
          lcd.clear();
          lcd.write(byte(0));
          lcd.blink();
        }else{
          lcd.clear();
          for(j=0;j<pos+1;j++){
            lcd.print(vet[j]);
          }
          lcd.write(byte(0));
          lcd.blink();
        }
        k = keypad.waitForKey();
        timer2 = millis();
        if(k=='*'){
          if(timer2<1500+timer){
            i=0;
            suita(k, pos);
          }else{
            vet[pos] = '?';
            suita(k, pos+1);
          }
        }else{
          vet[pos] = '?';
          suita(k, pos+1);
        }
       }
      break;
//**************************************************************************************************************
    case '0':
    int aux;
    lcd.clear();
    for(j=0;j<pos;j++){
      lcd.print(vet[j]);
    }
    lcd.print(" ");
    vet[pos] = "_";
    k = keypad.waitForKey();
    suita(k, pos+1);
    break;

    case '#':

    asm volatile ("jmp 0");
    break;

    
    
   default:Serial.println("Default");
   }
   
}


void ligaled(void){

  if(digitalRead(9)== LOW){
    digitalWrite(9, HIGH);
    lcd.clear();
    lcd.write(byte(1));
  }else{
    digitalWrite(9, LOW);
    lcd.clear();
    lcd.write(byte(0));
  
  }
  delay(1000);
}
