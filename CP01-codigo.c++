int pinoLDR = A0;
int tempSensor = A1;
int umidSensor = A2;
int pinoBuzzer = 11;
int pinoLedVerde = 10;
int pinoLedAmarelo = 9;
int pinoLedVermelho = 8;
int temp;
int tempMap;
int umidMap;

void setup() {
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
 
  Serial.begin(9600);
}

void loop() {
  // LDR - Tá funcionando! (Eu acho)
  int valorLDR = analogRead(pinoLDR);
  char buffer[40];
  sprintf(buffer, "LDR: %d", valorLDR);
  Serial.println(buffer);

  // Temperatura 
  // Leitura do sensor:
  temp = analogRead(tempSensor);
  
  // Cálculo e ajuste da temperatura:
  tempMap = map(((temp - 20) * 3.04), 0, 1023, -40, 125);
  
  char buffer2[40];
  sprintf(buffer2, "Temperatura: %d\xB0""C", tempMap);
  Serial.println(buffer2);

  // Umidade 
  int umid = analogRead(umidSensor);
  umidMap = map(umid, 0, 1023, 0, 100);
  char buffer3[40];
  sprintf(buffer3, "Umidade: %d", umidMap);
  Serial.print(buffer3);
  Serial.println("%");

  // Verificando as condições:
  if (valorLDR >= 1 && valorLDR <= 103 && umidMap >= 60 && umidMap <= 80 && tempMap == 13) {
    // CASO 1 - ÓTIMO
    digitalWrite(pinoLedVerde, HIGH);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, LOW);
    noTone(pinoBuzzer);
  } else if (abs(valorLDR - 52) <= 5 || abs(umidMap - 70) <= 5 || abs(tempMap - 13) <= 3) {
    // CASO 2 - ALERTA
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, HIGH);
    digitalWrite(pinoLedVermelho, LOW);
    tone(pinoBuzzer, 100);
  } else {
    // CASO 3 - CRÍTICO
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, HIGH);
    tone(pinoBuzzer, 200);
  }

  delay(1000); 
}