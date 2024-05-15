#include <avr/io.h>
#include <avr/interrupt.h>

#define B_MENOS (1 << PD2)
#define B_MAIS (1 << PD3)
#define LED (1 << PD4)

#define MAX_CONT 19531

// Variável contadora de casos de interrupção do timer
volatile int cont = 0;
volatile int maxCont = 19531;

int main() {

    DDRD |= LED;
    DDRD &= ~(B_MAIS | B_MENOS);

    PORTB |= B_MAIS | B_MENOS;
    
    TCCR0A |= (1 << WGM10); // Configura modo de operação para CTC -> TCCR0A = 0b00000010
    TCCR0B |= (1 << CS02) | (1 << CS00); // Base de divisão, clk / 1024 -> TCCR0B = 0b00000011

    // Valor a ser constantemente comparado ao registro TCNT0
    // TOP = ((t_est * f_osc) / prescaler - 1) / interrupções = ((5 * 16000000) / 1024 - 1) / 19531
    OCR0A |= 4; 

    TIMSK0 |= (1 << OCIE0A); // Liga a interrupção do comparador A do timer 0 -> TIMSK0 = 0b00000010

    EICRA |= (1 << ISC01) | (1 << ISC11);
    EIMSK |= (1 << INT0) | (1 << INT1);
    sei();

    while (1) {
        
    }
    
    return 0;
}

// Função de tratamento da interrupção do Timer 0
ISR(TIMER0_COMPA_vect) {

    cont++;

    if (cont >= maxCont) {
        PORTD ^= LED;
        cont = 0;
    }
}

ISR(INT0_vect) {
    if ((int) (MAX_CONT * 0.1) <= 0) {
        maxCont = 0;
    } else {
        maxCont -= (int) (MAX_CONT * 0.1);
    }
}

ISR(INT1_vect) {
    if ((int) (MAX_CONT * 0.1) >= MAX_CONT) {
        maxCont = MAX_CONT;
    } else {
        maxCont += (int) (MAX_CONT * 0.1);
    }
}