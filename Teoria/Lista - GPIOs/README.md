# E209 - Lista de Exercícios GPIO

**Realizar os exercícios abaixo considerando o microcontrolador ATMega328, e alinguagem C para microcontroladores. Deve ser utilizado o conceito de máscara de bits para preservar os estados lógicos dos pinos durante as operações.**

1. Escreva um programa que configure o pino PD2 como saída e, em seguida, use a operação de OR (|) para acender apenas o bit correspondente a esse pino no registro PORTD, mantendo os outros bits inalterados.

**R:**
```C
DDRD |= (1 << PD2); // Configura o pino PD2 como saída
PORTD |= (1 << PD2); // Acende o bit correspondente ao pino PD2
```
---

2. Modifique o programa anterior para apagar o bit correspondente ao pino PD2 usando a operação de AND (&) com o complemento de 1 (~) no bit desejado.

**R:**
```C
DDRD |= (1 << PD2); // Configura o pino PD2 como saída
PORTD |= (1 << PD2); // Acende o bit correspondente ao pino PD2
PORTD &= ~(1 << PD2); // Apaga o bit correspondente ao pino PD2
```
---

3. Crie um programa que configure os pinos PD3 e PB4 como saídas. Em seguida, use a operação de XOR (^) para alternar o estado dos dois pinos simultaneamente.

**R:**
```C
DDRD |= (1 << PD3); // Configura o pino PD3 como saída
DDRB |= (1 << PB4); // Configura o pino PB4 como saída

PORTD ^= (1 << PD3); // Alterna o estado do pino PD3
PORTB ^= (1 << PB4); // Alterna o estado do pino PB4
```
---

4. Escreva um programa que configure o pino PD5 como entrada e ative o resistor de pull-up interno. Use a operação de AND (&) no registro PIN para verificar o estado do pino.

**R:**
```C
DDRD &= ~(1 << PD5); // Configura o pino PD5 como entrada
PORTD |= (1 << PD5); // Ativa o resistor de pull-up interno do pono PD5

if (PIND & (1 << PD5)) {} // Verifica o estado do pino PD5
```
---

5. Modifique o programa anterior para usar a operação de AND (&) com o complemento de 1 no bit correspondente ao pino desejado no registro PORT para inverter o estado do pino.

**R:**
```C
DDRD &= ~(1 << PD5); // Configura o pino PD5 como entrada
PORTD |= (1 << PD5); // Ativa o resistor de pull-up interno do pono PD5

if (PIND & (1 << PD5)) {} // Verifica o estado do pino PD5

PORTD &= ~(1 << PD5); // Inverte o estado do pino PD5, desativando o pull-up
```
---

6. Crie um programa que configure os pinos PD6 e PD7 como saídas. Em seguida, use a operação de AND (&) com NÃO (&~) para apagar apenas o bit correspondente ao pino D¨no registro DDRD.

**R:**
```C
DDRD |= (1 << PD6) | (1 << PD7); // Configura os pinos PD6 e PD7 como saída
DDRD &= ~(1 << PD6); // Apaga o bit correspondente ao pino PD6 no registro DDRD
```
---

7. Escreva um programa que configure o pino PD2 como entrada. Use a operação de AND (&) para verificar se o bit correspondente a esse pino esetá setado no registro PIN e, caso positivo, acenda o LED no pino PD3 usando a operação de OR (|).

**R:**
```C
DDRD &= ~(1 << PD2); // Configura o pino PD2 como entrada
DDRD |= (1 << PD3); Configura o pino PD3 como saída

if (PIND & (1 << PD2)) { // Verifica se o bit do pino PD2 está setado no registro PIN
    PORTD |= (1 << PD3); // Acende o LED no pino PD3
}
```
---

8. Modifique o programa anterior para apagar ao LED no pino PD3 usando a operação de AND com NÃO (&~) se o pino PD2 estiver setado.

**R:**
```C
DDRD &= ~(1 << PD2); // Configura o pino PD2 como entrada
DDRD |= (1 << PD3); Configura o pino PD3 como saída

if (PIND & (1 << PD2)) { // Verifica se o bit do pino PD2 está setado no registro PIN
    PORTD &= ~(1 << PD3); // Apaga o LED no pino PD3
}
```
---

9. Crie um programa que configure os pinos PD4, PD5 e PD6 como saídas. Use a operação de OR (|) para definir esses pinos como saídas de forma simultânea.

**R:**
```C
DDRD |= (1 << PD4) | (1 << PD5) | (1 << PD6); // Configura os pinos PD4, PD5 e PD6 como saída
```
---

10. Escreva um programa que configure os pinos PD0, PD1 e PD2 como entradas. Use a operação de AND (&) para verificar se todos esses pinos estão definidos como entradas no registro DDRD.

**R:**
```C
DDRD &= ~((1 << PD0) | (1 << PD1) | (1 << PD2)); // Configura os pinos PD0, PD1 e PD2 como entrada

if (!(DDRD & ((1 << PD0) | (1 << PD1) | (1 << PD2)))) {} // Verifica se os pinos PD0, PD1 e PD2 estão configurados como entrada
```
---

11. Utilizando a estrutura dos programas para ATMega328, crie um programa que alterne o estado de um pino de saída (de sua escolha) sempre que um botão em um pino de entrada (de sua escolha) for pressioanado.

**Encontre o código desenvolvido na pasta [Ex 11](./Ex%2011)**

---

12. Modifique o programa anterior para que sejam utilizados 2 LEDs em 2 pinos de saída, e os mesmos devem alternar a cada clique do botão no pino de entrada.

**Encontre o código desenvolvido na pasta [Ex 12](./Ex%2012)**

---

13. Crie um programa que possua 5 pinos de entrada no Portal B, 1 LED 1 como saída no Portal D, e um LED2 como saída no Portal C. O programa deve funcionar como um identificador do padrões, onde o LED1 deve permanecer aceso e o LED2 apagado, enquanto as entradas possuírem bits intercalados. Se todos as entradas estiverem com nível lógico alto ou baixo, LED2 deve permanecer aceso, e o LED1 apagado.

Exemplo:
**ENTRADAS** = 10101, LED1 ACESO
**ENTRADAS** = 10010, NENHUM LED ACESO
**ENTRADAS** = 01010, LED1 ACESO
**ENTRADAS** = 00000, LED2 ACESO
**ENTRADAS** = 11111, LED2 ACESO

**Encontre o código desenvolvido na pasta [Ex 13](./Ex%2013)**

---

14. Crie um programa em C que funcione como uma fechadura eletrônica. O programa deve possuir 4 botões de entrada, com resistor de pull-up interno. Os 4 botões devem ser conectados aos pinos PB1, PB2, PB3 e PB4. O comando que libera a trava do sistema deve ser conectado ao pino PD3.

O sistema só será liberado se os botões forem pressionados em uma determinada ordem **PB2** -> **PB3** -> **PB4** -> **PB1**. Sabendo que, nenhum pino pode ser pressionado e solto, ou seja, ao final da sequência todos pinos devem estar pressionados para validar o acionamento, que será indicado pelo nível lógico alto no pino PD3.

**Encontre o código desenvolvido na pasta [Ex 14](./Ex%2014)**

---