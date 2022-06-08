// C++ code
// Programador: Jose Carlos
// 30/04/2022

int led1 = 8;           // Pino led 1
int led2 = 9;           // Pino led 2
int led3 = 10;          // Pino led 3
int som = 11;           // Pino Buzzer
int sensorGas = A0;     // Pino leitor analógico
int valorSensorGas = 0; // Pino do valor do leitor analógico

void setup() {

  Serial.begin(9600);         // Frequência de funcionamento do Serial
  pinMode (sensorGas, INPUT); // Pino de leitura analógica setado como entrada
  pinMode (led1, OUTPUT);     // Pino led setado como saída
  pinMode (led2, OUTPUT);     // Pino led setado como saída
  pinMode (led3, OUTPUT);     // Pino led setado como saída

}
void loop() {
  // O analogRead lê o valor de um pino analógico especificado
  valorSensorGas = analogRead(sensorGas); 
  
  if (valorSensorGas > 100 && valorSensorGas < 200) {
    
    digitalWrite(led1, HIGH); //Aciona led1
    tone(som, 100);           // Aciona Buzzer(som) com frequência de 100 Hz
    delay(2000);              // Buzzer ligado durante 2 segundos 
    noTone (som);             // Desliga Buzzer
    delay(2000);              // Buzzer desligado durante 2 segundos 

  }else if(valorSensorGas > 200 && valorSensorGas < 300){
    
    digitalWrite(led1, HIGH); //Aciona led1
    digitalWrite(led2, HIGH); //Aciona led2
    tone(som, 100);           // Aciona Buzzer(som) com frequência de 100 Hz
    delay(1000);              // Buzzer ligado durante 1 segundos 
    noTone (som);             // Desliga Buzzer
    delay(1000);              // Buzzer desligado durante 1 segundos 

  }else if(valorSensorGas > 300){
    
    digitalWrite(led1, HIGH); //Aciona led1
    digitalWrite(led2, HIGH); //Aciona led2
    digitalWrite(led3, HIGH); //Aciona led3
    tone(som, 100);           // Aciona Buzzer(som) com frequência de 100 Hz
    delay(500);               // Buzzer ligado durante meio segundos 
    noTone (som);             // Desliga Buzzer
    delay(500);               // Buzzer desligado durante 1 segundos 

  }else {
    
    digitalWrite(led1, LOW);  // Desliga led1
    digitalWrite(led2, LOW);  // Desliga led2
    digitalWrite(led3, LOW);  // Desliga led3
  }
  
  Serial.println(valorSensorGas); // Imprime valorSensorGas
}
