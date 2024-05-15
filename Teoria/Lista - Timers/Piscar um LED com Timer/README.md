### Piscar um LED com Timer:
- Conect um LED a um pino digital do ATMega328.
- Utilize o timer configurado para gerar uma interrupção e tratá-la de 5 em 5 segundos.
- Na ISR, inverta o estado do LED para criar um efeito de piscar.

O código desenvolvido se encontra no arquivo [main.c](./main.c).