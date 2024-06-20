# Exercício 4

##### Utilizando os conceitos de ADC e Timer, crie um código que controle a frequência de um buzzer por meio de um sensor analógico de pressão. A frequência de saída no buzzer deve representar uma escala musical básica:

| Notas | Frequência (Hz) |
|-------|-----------------|
| Dó    | 264             |
| Ré    | 300             |
| Mí    | 330             |
| Fá    | 352             |
| Sol   | 396             |
| Lá    | 440             |
| Si    | 495             |

Considere a resposta do sensor de pressão como sendo:
0 a 1.1V - Linear para a relação de pressão de 0% (solto) a 100% (pressionado com a força máxima)

- 10%: Dó
- 20%: Ré
- 30%: Mi
- 40%: Fá
- 50%: Sol
- 60%: Lá
- Maior ou igual a 70%: Si

O código desenvolvido se encontra no arquivo [main.c](./main.c)