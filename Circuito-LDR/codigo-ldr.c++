const int pinoLDR = A0;
const int pinoBuzzer = 11;
const int pinoLedVerde = 10;
const int pinoLedAmarelo = 9;
const int pinoLedVermelho = 8;
int buzzerPitch;
bool buzzerAtivo = false;
unsigned long tempoBuzzer = 0;

void setup() {
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoLDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int valorLDR = analogRead(pinoLDR);
    valorLDR = analogRead(pinoLDR);
    char buffer[40];
    sprintf(buffer, "Resis. do LDR: %d ohm(s)", valorLDR);
    Serial.println(buffer);

   buzzerPitch = map(valorLDR, 1, 310, 100, 400);

  if (valorLDR >= 1 && valorLDR <= 103) {
    digitalWrite(pinoLedVerde, HIGH);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, LOW);
    
    if (buzzerAtivo) {
      noTone(pinoBuzzer);
      buzzerAtivo = false;
    }
  } else if (valorLDR >= 104 && valorLDR <= 220) {
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
      buzzerAtivo = false;
    }

    
  } else if (valorLDR >= 221) {
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, HIGH);

    if (!buzzerAtivo) {
      tone(pinoBuzzer, buzzerPitch);
      buzzerAtivo = true;
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
