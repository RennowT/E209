# E209 - Temporizadores

Esta lista é referente ao conteúdo de temporizadores (timers) para ATMega328. Para os exercícios a seguir, elabore as linhas de configuração do Timer para cada caso e programe os vetores de interrupção que satisfação os problemas propostos.

---

### Configuração Básica do Timer:
- Configure o Timer/Counter do ATMega328 no modo de comparação (CTC - CLear Timer on Compare Match).
- Defina um valor de comparação adequado para gerar uma interrupção em intervalos de 35ms.
- Escreva uma ISR para lidar com a tinterrupção gerada pelo timer.

**Encontre o código desenvolvido na pasta [Configuração Básica do Timer](./Configuração%20Básica%20do%20Timer)**

---

### Piscar um LED com Timer:
- Conect um LED a um pino digital do ATMega328.
- Utilize o timer configurado para gerar uma interrupção e tratá-la de 5 em 5 segundos.
- Na ISR, inverta o estado do LED para criar um efeito de piscar.

**Encontre o código desenvolvido na pasta [Piscar um LED com Timer](./Piscar%20um%20LED%20com%20Timer)**

---

### Contagem de Tempo Precisa:
- Configure o timer para gerar uma interrupção em um intervalo específico de tempo, por exemplo, a cada 1 segundo.
- Utilizando 8 saídas digitais, crie um relógio binário que vai de 0 a 255.

**Encontre o código desenvolvido na pasta [Contagem de Tempo Precisa](./Contagem%20de%20Tempo%20Precisa)**

---

### Controle de Velocidade de Piscar do LED:
- Modifique o exercício [Piscar um LED com Timer] para permitir que o intervalo entre os piscar do LED seja ajustado dinamicamente.
- Utilize duas entradas digitais que serão os botões de "mais" e "menos".
- Sempre que pressionado o botão de "mais", o LED deve piscar mais rápido, com o limite de 10Hz.

**Encontre o código desenvolvido na pasta [Controle de Velocidade de Piscar do LED](./Controle%20de%20Velocidade%20de%20Piscar%20do%20LED)**

---

### Temporizador de Contagem Regressiva:
- Configure o timer para funcionar como um temporizador de contagem regressiva.
- Utilize 5 saídas digitais (LEDs) para representar a quantificação da contagem de 100% a 0%.
- Quando atingir 0%, todos os LEDs devem permanecer piscando em intervalos de 2Hz, até que o programa seja reiniciado.

**Encontre o código desenvolvido na pasta [Temporizador de Contagem Regressiva](./Temporizador%20de%20Contagem%20Regressiva)**