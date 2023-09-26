int pinoLDR = A0;
int pinoBuzzer = 5;
int pinoLedVerde = 6;
int pinoLedAmarelo = 7;
int pinoLedVermelho = 8;
bool buzzerAtivo = false; 
int tempoBuzzer = 0;

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
  
  if (valorLDR <= 50 ) {  
    digitalWrite(pinoLedVerde, HIGH);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, LOW);

         if (buzzerAtivo) {
      noTone(pinoBuzzer); 
      buzzerAtivo = false;
         }
    
 
  } if (valorLDR > 80 && valorLDR < 150 ) { 
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, HIGH);
    digitalWrite(pinoLedVermelho, LOW);
 
 
   if (!buzzerAtivo) {
      tone(pinoBuzzer, 1000, 200); 
      buzzerAtivo = true;
      tempoBuzzer = millis();
    }

    if(millis() - tempoBuzzer >= 3000) {
      noTone(pinoBuzzer);
      buzzerAtivo = false;
    }
    
  }
  
  if (valorLDR >= 200) { 
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, HIGH);

       if (!buzzerAtivo) {
      tone(pinoBuzzer, 1000, 1000); 
      buzzerAtivo = true;

    }
    
   
  }
  }
