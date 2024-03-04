# Controle de LED com Botão - AVR

Este é um código em linguagem C para controlar um LED utilizando um botão em um microcontrolador AVR. O código alterna entre quatro estados diferentes do LED (OFF, VERDE, VERMELHO e LIGADO) cada vez que o botão é pressionado.

## Hardware necessário

- Microcontrolador AVR
- LED verde
- LED vermelho
- Botão

## Como usar

1. Carregue o código para o microcontrolador AVR.
2. Conecte os LEDs e o botão aos pinos do microcontrolador conforme definido no código.
3. Pressione o botão para alternar entre os estados do LED.

## Detalhes do código

O código utiliza a biblioteca avr/io.h para acessar os registradores do microcontrolador AVR e a biblioteca avr/delay.h para gerar atrasos. Os LEDs e o botão são conectados aos pinos do microcontrolador, e os estados do LED são controlados por uma variável de estado.

## Pinagem

- LED verde: Pino PD1
- LED vermelho: Pino PD2
- Botão: Pino PD5

Certifique-se de ajustar a pinagem de acordo com a sua configuração de hardware, se necessário.
