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

<img height="350em" src="https://github.com/Ctrl-Alt-Challenge/CP01-EDCS/assets/110347145/3361d683-9307-4e68-aca7-28a4a10be94f" alt="Circuito" align="right">

<div align="left" width="600px">
  
```c++
int pinoLDR = A0;
int pinoBuzzer = 11;
int pinoLedVerde = 10;
int pinoLedAmarelo = 9;
int pinoLedVermelho = 8;

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
    noTone(pinoBuzzer); 
  } else if (valorLDR >= 104 && valorLDR <= 220) { 
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, HIGH);
    digitalWrite(pinoLedVermelho, LOW);
    tone(pinoBuzzer, BuzzerPitch, 100);
    delay(500);
  } else if (valorLDR >= 221) { 
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVermelho, HIGH);
    tone(pinoBuzzer, BuzzerPitch, 200); 
    delay(100);
  }
}

```
  </div>
