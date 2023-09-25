int pinoLDR = A0;
int tempSensor = A1;
int umidSensor = A2;
int pinoBuzzer = 13;
int pinoLedVerde = 10;
int pinoLedAmarelo = 9;
int pinoLedVermelho = 8;
int temp;
int tempMap;
int umid;
int umidMap;
int valorLDR;
int buzzerPitch;
long tempoAlerta = 0;
long tempoBuzzer = 0;
bool buzzerAtivo = false;

void setup() {
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  valorLDR = analogRead(pinoLDR);
  char buffer[40];
  sprintf(buffer, "Resis. do LDR: %d ohm(s)", valorLDR);
  Serial.println(buffer);

  buzzerPitch = map(valorLDR, 1, 310, 100, 400);

  temp = analogRead(tempSensor);
  tempMap = map(((temp - 20) * 3.04), 0, 1023, -40, 125);
  char buffer2[40];
  sprintf(buffer2, "Temperatura: %d\xB0""C", tempMap);
  Serial.println(buffer2);

  buzzerPitch = map(tempMap, 1, 310, 100, 400);

  umid = analogRead(umidSensor);
  umidMap = map(umid, 0, 1023, 0, 100);
  char buffer3[40];
  sprintf(buffer3, "Umidade do ar: %d%%", umidMap);
  Serial.println(buffer3);

  buzzerPitch = map(umidMap, 1, 310, 100, 400);

  int condicoesInadequadas = 0;

  if (valorLDR < 1 || valorLDR > 103) {
    condicoesInadequadas++;
  }

  if (umidMap < 60 || umidMap > 80) {
    condicoesInadequadas++;
  }

  if (tempMap < 10 || tempMap > 15) {
    condicoesInadequadas++;
  }

  if (condicoesInadequadas == 1) {
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, HIGH);
    digitalWrite(pinoLedVermelho, LOW);
    
    if (!buzzerAtivo) {
      tone(pinoBuzzer, buzzerPitch);
      buzzerAtivo = true;
      tempoBuzzer = millis() + 3000;
    }
    
  } else if (condicoesInadequadas >= 2) {
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, HIGH);
    
    if (!buzzerAtivo) {
      tone(pinoBuzzer, buzzerPitch);
      buzzerAtivo = true;
      tempoBuzzer = 0;
    }
    
} else {
    digitalWrite(pinoLedVerde, HIGH);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, LOW);
    if (buzzerAtivo) {
      if (tempoBuzzer == 0) {
        tempoBuzzer = millis() + 3000; 
      } else if (millis() >= tempoBuzzer) {
        noTone(pinoBuzzer); 
        buzzerAtivo = false;
      }
    }
}
  
  if (tempoBuzzer > 0 && millis() >= tempoBuzzer) {
    noTone(pinoBuzzer);
    buzzerAtivo = false;
  }

  delay(1000);
}
