#include <DHT.h> 
#define DHTPIN 7     // Define o pino ao qual o sensor DHT11 está conectado 
#define DHTTYPE DHT11   // Define o tipo de sensor DHT (DHT11 neste caso) 
  
DHT dht(DHTPIN, DHTTYPE); 
const int pinoLDR = A0;
const int pinoBuzzer = 13;
const int pinoLedVerde = 10;
const int pinoLedAmarelo = 9;
const int pinoLedVermelho = 8;
int buzzerPitch;
bool buzzerAtivo = false;
int tempoBuzzer = 0;

void setup() {
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoLDR, INPUT);
  dht.begin(); 
  Serial.begin(9600);
}

void loop() {
  int valorLDR = analogRead(pinoLDR);
    valorLDR = analogRead(pinoLDR);
    char buffer[40];
    sprintf(buffer, "Resis. do LDR: %d ohm(s)", valorLDR);
    Serial.println(buffer);
 float umidade = dht.readHumidity(); 
 float temperatura = dht.readTemperature(); 

   buzzerPitch = map(valorLDR, 1, 310, 100, 400);
   if (isnan(umidade) || isnan(temperatura)) { 

    Serial.println("Erro ao ler o sensor DHT!"); 

  } else { 

    Serial.print("Umidade: "); 

    Serial.print(umidade); 

    Serial.print(" %\t"); 

    Serial.print("Temperatura: "); 

    Serial.print(temperatura); 

    Serial.println(" °C");  

  if (valorLDR >= 1 && valorLDR <= 80) {
    digitalWrite(pinoLedVerde, HIGH);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, LOW);
    
    if (buzzerAtivo) {
      noTone(pinoBuzzer);
      buzzerAtivo = true;
    }
  } else if (valorLDR >= 81 && valorLDR <= 220) {
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, HIGH);
    digitalWrite(pinoLedVermelho, LOW);

        if (!buzzerAtivo) {
      tone(pinoBuzzer, buzzerPitch);
      buzzerAtivo = true;
      tempoBuzzer = millis();
    }
    
      digitalWrite(pinoLedVerde, LOW);
    
     if (millis() - tempoBuzzer >= 3000) {
      noTone(pinoBuzzer); 
      buzzerAtivo = true;
    }

    
  } else if (valorLDR >= 221) {
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, HIGH);

    if (!buzzerAtivo) {
      tone(pinoBuzzer, buzzerPitch);
      buzzerAtivo = false;
    }
    
      digitalWrite(pinoLedVerde, LOW);

  } else {
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, LOW);
    noTone(pinoBuzzer);
    buzzerAtivo = false;
  }
    delay(1000);
  }
}
