# Exercício 3

##### Utilizando os conceitos de ADC e Timer, crie um código que faça o chaveamento da leitura entre 2 canais analógicos (1 sensor de luz e 1 sensor de gás) do ATMega328p em uma frequência de 3Hz. O resiltado das conversões dos sensores devem ser armazenados em um vetor de números inteiros, onde a posição armazena a leitura do sensor de luz e a posição 1 armazena a leitura do sensor de gás: int sensores [2];
- Considere a resposta dos sensores como:
**Gás:** 0 a 5V - Linear para a concentração de gás de 0% a 100%.
**Luz:** 0 a 5V - Linear para a quantidade de luz de 10% a 90%. (90% = 5V | 10% = 0V).

O código desenvolvido se encontra no arquivo [main.c](./main.c)