# E209 - ADC

Esta lista é referente ao conteúdo de ADC para o ATMega328. Para os exercícios a seguir, elabore as linhas de configuração do ADC para cada caso e programe os vetores de interrupção que satisfaçam os problemas propostos.

---

##### 1)  Explique passo a passo como é realizado o processo de conversão AD em microcontroladores. Considere o início da conversão como sendo a resposta de um sensor analógico de temperatura.

**R:**
1. **Aquisição do Sinal**: O sensor analógico, como um sensor de temperatura, gera uma tensão proporcional à temperatura.
2. **Configuração do ADC**: Configura-se o ADC do microcontrolador para o canal de entrada do sensor, determinando a resolução e as condições de amostragem.
3. **Iniciar a Conversão**: O ADC captura a tensão analógica e mantém esse valor estável.
4. **Conversão para Digital**: O ADC converte a tensão amostrada em um valor digital correspondente.
5. **Processamento do Valor Digital**: O valor digital é lido e, se necessário, convertido em unidades de medida utilizáveis (por exemplo, graus Celsius).

---

##### 2) Configure o conversor AD do ATMega328 para realizar a leitura de um sensor de umidade que  fornece uma resposta de 0 a 5V correspondentes aos valores de umidade relativo, sendo:
- LED Verde: Acima de 80%
- LED Amarelo: Entre 50% e 80%
- LED Vermelho: Abaixo 50%

O código desenvolvido se encontra na pasta [Ex 2](./Ex%202/main.c)

---

##### 3) Utilizando os conceitos de ADC e Timer, crie um código que faça o chaveamento da leitura entre 2 canais analógicos (1 sensor de luz e 1 sensor de gás) do ATMega328p em uma frequência de 3Hz. O resiltado das conversões dos sensores devem ser armazenados em um vetor de números inteiros, onde a posição armazena a leitura do sensor de luz e a posição 1 armazena a leitura do sensor de gás: int sensores [2];
- Considere a resposta dos sensores como:
**Gás:** 0 a 5V - Linear para a concentração de gás de 0% a 100%.
**Luz:** 0 a 5V - Linear para a quantidade de luz de 10% a 90%. (90% = 5V | 10% = 0V).

O código desenvolvido se encontra na pasta [Ex 3](./Ex%203/main.c)

---

##### 4) Utilizando os conceitos de ADC e Timer, crie um código que controle a frequência de um buzzer por meio de um sensor analógico de pressão. A frequência de saída no buzzer deve representar uma escala musical básica:

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

O código desenvolvido se encontra na pasta [Ex 4](./Ex%204/main.c)

---

##### 5) Utilize o conversor AD do ATMega328 para criar um decodificador de bits a partir de uma sequência de quadros brancos e pretos, onde branco=1 e preto=0.

O sistema possui um sensor de luz que é direcionado à tela de um dispositivo. No dispositivo, uma informação é passada por meio de quadros brancos e pretos, sequencialmente, e uma janela fixa de leitura de 1Hz/Quadro.

Para a sequência, o ATMega328p deve fazer a leitura e retornar a sequência de bitis 1010110. Considere que a resposta calibrada do sensor de luz é:

0 a 5V - Linear sendo:

- Acima de 4V:  Quadro branco
- Abaixo de 3.5V: Quadro preto
- Entre as faixas: Leitura deve ser indeterminada, todo quadro deve ser descartado e o processo reiniciado.

O código desenvolvido se encontra na pasta [Ex 4](./Ex%204/main.c)