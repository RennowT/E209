# Exercício 5

Utilize o conversor AD do ATMega328 para criar um decodificador de bits a partir de uma sequência de quadros brancos e pretos, onde branco=1 e preto=0.

O sistema possui um sensor de luz que é direcionado à tela de um dispositivo. No dispositivo, uma informação é passada por meio de quadros brancos e pretos, sequencialmente, e uma janela fixa de leitura de 1Hz/Quadro.

Para a sequência, o ATMega328p deve fazer a leitura e retornar a sequência de bitis 1010110. Considere que a resposta calibrada do sensor de luz é:

0 a 5V - Linear sendo:

- Acima de 4V:  Quadro branco
- Abaixo de 3.5V: Quadro preto
- Entre as faixas: Leitura deve ser indeterminada, todo quadro deve ser descartado e o processo reiniciado.

O código desenvolvido se encontra no arquivo [main.c](./main.c)