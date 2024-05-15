#include <avr/io.h>
#include <avr/interrupt.h>

// Variável contadora de casos de interrupção do timer
volatile int cont = 0;

int main() {

    // Configura modo de operação para CTC -> TCCR0A = 0b00000010
    TCCR0A |= (1 << WGM10);

    // Base de divisão, clk / 64 -> TCCR0B = 0b00000011
    TCCR0B |= (1 << CS01) | (1 << CS00);

    // Valor a ser constantemente comparado ao registro TCNT0
    // TOP = ((t_est * f_osc) / prescaler - 1) / interrupções = ((0.035 * 16000000) / 64 - 1) / 673
    OCR0A |= 13; 

    // Liga a interrupção do comparador A do timer 0 -> TIMSK0 = 0b00000010
    TIMSK0 |= (1 << OCIE0A);
    
    return 0;
}

// Função de tratamento da interrupção do Timer 0
ISR(TIMER0_COMPA_vect) {
    cont++;
    if (cont >= 673) {
        /* EXECUTA LÓGICA DO TIMER */
        cont = 0;
    }
}