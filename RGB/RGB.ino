int leitura_Vm=A0;         // Definindo os pinos de Entrada Analógica
int leitura_Vd=A1;
int leitura_A=A2;

int LedVm=11;               // Definindo os pinos de Saída PWM
int LedVd=10;
int LedA=9;

int valorLedVm=0;         // Definindo os valores das Saídas em 0.
int valorLedA=0;
int valorLedVd=0;


void setup() {
  pinMode(LedVm,OUTPUT);     // Estabelecendo os pinos do Led RGB como Saídas
  pinMode(LedA,OUTPUT);
  pinMode(LedVd,OUTPUT);    
  pinMode(leitura_Vm,INPUT);   // Estabelecendo os pinos A0, A1 eA2 como Entradas
  pinMode(leitura_A,INPUT);   
  pinMode(leitura_Vd,INPUT);
}

void loop() {
  valorLedVm = analogRead(leitura_Vm);  //Lendo as entradas
  valorLedVm=valorLedVm/4;                     // Dividindo o valor de 1024 posições para um valor no range de 256 posições
  delay(1000);
    
  valorLedA = analogRead(leitura_A);  
  valorLedA=valorLedA/4;
  delay(1000);
    
  valorLedVd = analogRead(leitura_Vd);
  valorLedVd=valorLedVd/4;
  delay(1500);
  
  analogWrite(LedVm,valorLedVm);       // Coloca no pino  LedVm uma saída de tensão proporcional ao valor lido.
  analogWrite(LedA,valorLedA);
  analogWrite(LedVd,valorLedVd);
  delay(1000);
}
