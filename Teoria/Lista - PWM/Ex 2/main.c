#include <avr/io.h>
#include <avr/interrupt.h>

#define PWM_OUTPUT (1 << PD2); // Define o pino de saída PWM como PD2
#define PWM_FREQUENCY 1000     // Frequência do sinal PWM em Hz
#define DUTY_CYCLE 128         // Ciclo de trabalho do sinal PWM (0 a 255)

volatile unsigned char counter = 0; // Variável para contar os pulsos do PWM

ISR(TIMER0_COMPA_vect) { // Rotina de interrupção do Timer/Counter 0
    counter++; // Incrementa o contador de pulsos

    if (counter >= 255) { // Se o contador atingir seu limite
        counter = 0;      // Reinicia o contador
    }

    if (counter < DUTY_CYCLE) {   // Se o contador for menor que o ciclo de trabalho
        PORTD |= PWM_OUTPUT;      // Liga o pino de saída PWM
    } else {
        PORTD &= ~PWM_OUTPUT;     // Desliga o pino de saída PWM
    }
}

int main() {
    DDRD |= PWM_OUTPUT; // Configura o pino de saída PWM como saída

    TCCR0A |= (1 << WGM01); // Ativa o modo de comparação do Timer/Counter 0
    TCCR0B |= (1 << CS01) | (1 << CS00); // Define o prescaler do Timer/Counter 0 como 64
    OCR0A = (16000000 / (2 * 64 * PWM_FREQUENCY)) - 1; // Define o valor de comparação para obter a frequência desejada
    TIMSK0 |= (1 << OCIE0A); // Ativa a interrupção por comparação A do Timer/Counter 0

    sei(); // Ativa as interrupções globais

    while (1) {
        // Loop infinito
    }
}
