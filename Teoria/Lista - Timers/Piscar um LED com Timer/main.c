#include <avr/io.h>
#include <avr/interrupt.h>

// Definição de pinos
#define LED_PIN (1 << PD2)

// Variável contadora de casos de interrupção do timer
volatile int cont = 0;

int main() {

    // Configurando o LED como saída -> 0b00000100
    DDRD |= LED_PIN;

    // Configura modo de operação para CTC -> TCCR0A = 0b00000010
    TCCR0A |= (1 << WGM10);

    // Base de divisão, clk / 1024 -> TCCR0B = 0b00000011
    TCCR0B |= (1 << CS02) | (1 << CS00);

    // Valor a ser constantemente comparado ao registro TCNT0
    // TOP = ((t_est * f_osc) / prescaler - 1) / interrupções = ((5 * 16000000) / 1024 - 1) / 19531
    OCR0A |= 4; 

    // Liga a interrupção do comparador A do timer 0 -> TIMSK0 = 0b00000010
    TIMSK0 |= (1 << OCIE0A);
    
    return 0;
}

// Função de tratamento da interrupção do Timer 0
ISR(TIMER0_COMPA_vect) {

    cont++;

    if (cont >= 19531) {
        PORTD ^= LED_PIN;
        cont = 0;
    }
}