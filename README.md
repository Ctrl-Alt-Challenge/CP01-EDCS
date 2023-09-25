# Uso do sensor LDR, TMP36 e DHT11 no Arduino

<table>
  <tr>
    <td>
      <div>
        <table>
          <tr>
            <th>Alunos:</th>
          </tr>
          <tr>
            <th>Giovanna Franco Gaudino Rodrigues</th>
          </tr>
          <tr>
            <th>André Luiz Viana Ribeiro</th>
          </tr>
          <tr>
            <th>Beatriz Dantas Sampaio</th>
          </tr>
          <tr>
            <th>Isabela Barcellos Freire</th>
          </tr>
        </table>
      </div>
    </td>
    <td>
      <div>
        <b>Checkpoint 01 - Edge Computing & Computer Systems</b>
      <td> <b>Objetivo → Medir a luz do ambiente da Vinheria Agnello</b> </td>
      </div>
    </td>
  </tr>
</table>

<br>


<img height="290em" src="https://github.com/Ctrl-Alt-Challenge/CP01-EDCS/assets/110347145/7f341af6-93d9-418b-94c4-7403772e867c" alt="Circuito" align="right">

<div align="left" width="600px">
  
```c++
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
  sprintf(buffer, "LDR: %d ohm(s)", valorLDR);
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
  sprintf(buffer3, "Umidade: %d%%", umidMap);
  Serial.println(buffer3);

  buzzerPitch = map(umidMap, 1, 310, 100, 400);

  int grandezasForaConformes = 0;

  if (valorLDR < 1 || valorLDR > 103) {
    grandezasForaConformes++;
  }

  if (umidMap < 60 || umidMap > 80) {
    grandezasForaConformes++;
  }

  if (tempMap < 10 || tempMap > 15) {
    grandezasForaConformes++;
  }

  if (grandezasForaConformes == 1) {
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, HIGH);
    digitalWrite(pinoLedVermelho, LOW);
    if (!buzzerAtivo) {
      tone(pinoBuzzer, buzzerPitch);
      buzzerAtivo = true;
      tempoBuzzer = millis() + 3000;
    }
  } else if (grandezasForaConformes >= 2) {
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


```
  </div>
