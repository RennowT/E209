#include <avr/io.h>
#include <avr/interrupt.h>

#define PWM_MAX 255
#define PWM_STEP (PWM_MAX / 20)

#define INCREASE_BUTTON (1 << PD2)
#define DECREASE_BUTTON (1 << PD3)
#define PWM_OUTPUT (1 << PD6)

volatile unsigned char pwm_value = 0;

// Acelerar o motor
ISR(INT0_vect) {
    if (pwm_value <= PWM_MAX - PWM_STEP) {
        pwm_value += PWM_STEP;
    } else {
        pwm_value = PWM_MAX;
    }
    OCR0A = pwm_value;
}

// Frear o motor
ISR(INT1_vect) {
    if (pwm_value >= PWM_STEP) {
        pwm_value -= PWM_STEP;
    } else {
        pwm_value = 0;
    }
    OCR0A = pwm_value;
}

int main() {
    // Configura os botões
    DDRD &= ~(INCREASE_BUTTON | DECREASE_BUTTON);
    PORTD |= INCREASE_BUTTON | DECREASE_BUTTON;

    // Habilita as interrupções externas para descida
    EICRA |= (1 << ISC01) | (1 << ISC11)
    EIMSK |= (1 << INT0) | (1 << INT1)

    // Configura o PWM
    DDRD |= PWM_OUTPUT;
    TCCR0A |= (1 << COM0A1); // Non-inverting mode
    TCCR0A |= (1 << WGM01) | (1 << WGM00); // Fast PWM
    TCCR0B |= (1 << CS01) | (1 << CS00); // Prescaler de 64
    OCR0A = pwm_value;

    // Habilita as interrupções
    sei();

    while (1) {
        
    }
}