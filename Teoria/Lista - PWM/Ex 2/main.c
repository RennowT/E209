#include <avr/io.h>
#include <avr/interrupt.h>

#define PWM_OUTPUT (1 << PD2);
#define PWM_FREQUENCY 1000
#define DUTY_CYCLE 128

volatile unsigned char counter = 0;

ISR(TIMER0_COMPA_vect) {
    counter++;
    if (counter >= 255) {
        counter = 0;
    }

    if (counter < DUTY_CYCLE) {
        PORTD |= PWM_OUTPUT;
    } else {
        PORTD &= ~PWM_OUTPUT;
    }
}

int main() {
    DDRD |= PWM_OUTPUT;
    
    TCCR0A |= (1 << WGM01);
    TCCR0B |= (1 << CS01) | (1 << CS00);
    OCR0A = (16000000 / (2 * 64 * PWM_FREQUENCY)) - 1;
    TIMSK0 |= (1 << OCIE0A);

    sei();

    while (1) {
        
    }
    
}