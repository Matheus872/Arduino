#include <Servo.h>.
 
  // Definindo as entradas do gatilho e receptor do sensor 
  const int trig_Pino = 11;
  const int echo_Pino = 12;
 
  // Variáveis para calcular a distância
  long tempo;
  int distancia;
 
  // Declarando o servo que gira o radar
  Servo Radar_Servo;
 
void setup() {
  
  // Definindo gatilho como saída
  //Echo como entrada, além de iniciar a serial e o servo
  pinMode(trig_Pino, OUTPUT);
  pinMode(echo_Pino, INPUT);
 
  Serial.begin(9600);
  Radar_Servo.attach(9); // Pino de conexão do servo motor
}
 
void loop() {
  
  //Girar de 15° até 165°
    for(int i = 0; i <= 180; i++){
    Radar_Servo.write(i);
    delay(30);
    
    // Verificação do sensor enquanto o servo gira
    // objeto e qual a distancia
    // Chamando a função 'CalculandoDistancia()'
    distancia = calculandoDistancia();
   
    Serial.print(i);        // Mostra na serial qual o angulo de giro o servo está no momento
    Serial.print(",");      // Formatação
    Serial.print(distancia); // Mostra a distancia que o sensor está calculando
    Serial.print(".");      // Coloca um '.' depois da distancia para indexar no processing a distancia
    }
 
    //Mesmos passos para voltar de 165° --> 15°
    for(int i = 180; i > 0 ; i--){
    Radar_Servo.write(i);
    delay(30);
    
  
    distancia = calculandoDistancia();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }
}

     //Criando a função para calcular a distância
    int calculandoDistancia(){
 
    digitalWrite(trig_Pino, LOW);  // Desligar o gatilho para poder realizar os pulsos
    delayMicroseconds(2);
 
    // Aqui é onde um ligo o gatilho por 10 ms (tempo para calcular a distância)
    digitalWrite(trig_Pino, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_Pino, LOW);
    
    tempo = pulseIn(echo_Pino, HIGH);  // Set receptor para capitar o pulso ultrassonico e voltar o tempo que ele demorou
    
    distancia = tempo*0.034/2;  // Fórmula para converter o tempo na distancia do objeto até o sensor
    return distancia;
}
