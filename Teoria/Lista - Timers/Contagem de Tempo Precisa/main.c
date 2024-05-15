#include <avr/io.h>
#include <avr/interrupt.h>

// Variável contadora de casos de interrupção do timer
volatile int cont = 0;

int main() {

    DDRB |= 0b11111111;

    TCCR0A |= (1 << WGM10); // Configura modo de operação para CTC -> TCCR0A = 0b00000010
    TCCR0B |= (1 << CS02); // Base de divisão, clk / 1024 -> TCCR0B = 0b00000011

    // Valor a ser constantemente comparado ao registro TCNT0
    // TOP = ((t_est * f_osc) / prescaler - 1) / interrupções = ((1 * 16000000) / 256 - 1) / 255
    OCR0A |= 245; 

    TIMSK0 |= (1 << OCIE0A); // Liga a interrupção do comparador A do timer 0 -> TIMSK0 = 0b00000010
    sei();

    while (1) {
        PORTB = (cont & 0b11111111); // Exibe o contador nos pinos de saída
    }
    
    
    return 0;
}

// Função de tratamento da interrupção do Timer 0
ISR(TIMER0_COMPA_vect) {

    cont++;

    if (cont >= 255) {
        
        cont = 0;
    }
}