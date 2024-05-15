# Configuração Básica do Timer:
- Configure o Timer/Counter do ATMega328 no modo de comparação (CTC - CLear Timer on Compare Match).
- Defina um valor de comparação adequado para gerar uma interrupção em intervalos de 35ms.
- Escreva uma ISR para lidar com a tinterrupção gerada pelo timer.

O código desenvolvido se encontra no arquivo [main.c](./main.c).