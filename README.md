# CP01-EDCS

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
        Checkpoint 01 - Edge Computing & Computer Systems
        <br>
        Objetivo → Medir a luz do ambiente da Vinheria Agnello
      </div>
    </td>
  </tr>
</table>


<br>

<img height="200em" src="https://github.com/Ctrl-Alt-Challenge/CP01-EDCS/assets/110347145/380dc885-c458-4837-be2e-220c2b4f8a35" alt="Circuito" align="right">

<div align="left" width="600px">
  
```c++
// C++ code
void setup()
{
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  if (analogRead(A0) < 50) {
    delay(3000); // Wait for 3000 millisecond(s)
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
  } else {
    if (analogRead(A0) < 150) {
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
    } else {
      digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      delay(3000); // Wait for 3000 millisecond(s)
      digitalWrite(5, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    }
  }
}
```
  </div>
