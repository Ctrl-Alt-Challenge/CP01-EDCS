<div align="center">
  <br>
  <h1>Sensor de Monitoramento de Condições Ambientais & Sensor LDR</h1>
</div>

<br>

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
        <b>Checkpoint 01 <br> Edge Computing & Computer Systems</b>
      <td> <b>Objetivo → <br> Medir a luz, temperatura e umidade do ambiente da Vinheria Agnello</b> </td>
      </div>
    </td>
  </tr>
</table>

<h2> Hardware </h2>
<img height="390em" src="https://github.com/Ctrl-Alt-Challenge/CP01-EDCS/assets/110347145/7e29fb77-afb5-4c96-ae84-576aa0cb1025" alt="Circuito" align="right">

<div align="left">

<b> - Tabela com o hardware do circuito completo </b>

| Quantidade | Descrição                   |
| ---------- | ----------------------------- |
| 1          | Arduino Uno R3                |
| 1          | Vermelho LED                  |
| 1          | Sensor de temperatura [TMP36] |
| 4          | 220 Ω Resistor                |
| 1          | Amarelo LED                   |
| 1          | Verde LED                     |
| 1          | Fotorresistor                 |
| 1          | Speaker                       |
| 1          | 250 kΩ Potenciômetro          |

</div>

---

<img height="385em" src="https://github.com/Ctrl-Alt-Challenge/CP01-EDCS/assets/110347145/e4274581-4f64-477f-996e-24cc1f8d228c" alt="Circuito" align="right">


<div align="left">

<b> - Tabela com o hardware do circuito só com o LDR </b>

| Quantidade | Descrição                     |
| ---------- | ----------------------------- |
| 1          | Arduino Uno R3                |
| 1          | Vermelho LED                  |
| 4          | 220 Ω Resistor                |
| 1          | Amarelo LED                   |
| 1          | Verde LED                     |
| 1          | Fotorresistor                 |
| 1          | Speaker                       |


</div>

<h2> Configuração </h2>

Conecte os componentes elétricos de forma adequada, caso tenha dúvidas, consulte as imagens abaixo:
- <a href="Circuito-LDR/circuito-ldr.png"> Circuito completo </a>
- <a href="Circuito-Completo/circuito-completo.png"> Circuito só com o LDR </a>


<h2> Software </h2>

<p> Para o desenvolvimento do projeto, foi usado a IDE: </p>

<a href="https://www.arduino.cc/en/software"> Arduino IDE </a>

<h2> Funcionamento  </h2>
1. Conecte os sensores e LEDs conforme o esquema. <br>
2. Conecte o Arduino. <br>
3. Carregue o código no Arduino usando a IDE. <br>
4. Observe as luzes dos LEDs e o som do buzzer de acordo com as condições. <br>

<br>

⚠️ <b> Caso você use outras entradas para os componentes, favor lembrar de atualizar seu código com as entradas corretas. </b>
