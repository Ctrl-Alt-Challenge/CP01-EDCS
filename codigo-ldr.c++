int pinoLDR = A0;
int pinoBuzzer = 11;
int pinoLedVerde = 10;
int pinoLedAmarelo = 9;
int pinoLedVermelho = 8;
bool buzzerAtivo = false; 

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
  Serial.println(valorLDR);
  
  int BuzzerPitch = map(valorLDR, 1, 310, 100, 400);

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
      tone(pinoBuzzer, BuzzerPitch, 3000); 
      buzzerAtivo = true;
    }
    
    delay(500);
  } else if (valorLDR >= 221) { 
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, HIGH);
    
    if (!buzzerAtivo) {
      tone(pinoBuzzer, BuzzerPitch, 200); 
      buzzerAtivo = true;
    }
    
    delay(100);
  }
}
