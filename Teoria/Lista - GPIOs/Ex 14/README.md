# Exemplo 14

Crie um programa em C que funcione como uma fechadura eletrônica. O programa deve possuir 4 botões de entrada, com resistor de pull-up interno. Os 4 botões devem ser conectados aos pinos PB1, PB2, PB3 e PB4. O comando que libera a trava do sistema deve ser conectado ao pino PD3.

O sistema só será liberado se os botões forem pressionados em uma determinada ordem **PB2** -> **PB3** -> **PB4** -> **PB1**. Sabendo que, nenhum pino pode ser pressionado e solto, ou seja, ao final da sequência todos pinos devem estar pressionados para validar o acionamento, que será indicado pelo nível lógico alto no pino PD3.

O código desenvolvido se encontra no arquivo [main.c](./main.c)

#### Vídeo

[Bradboard](./gif-ex14.mp4)