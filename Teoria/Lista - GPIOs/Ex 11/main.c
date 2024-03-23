#include <avr/io.h>
#include <avr/delay.h>

#define LED (1 << PD2) \\ Define o pino PD2 como LED
#define BUTTON (1 << PD7) \\ Define o pino PD7 como BUTTON

#define BUTTON_PRESS !(PIND & (1 << PD7)) \\ Define a verificação do bit correspondente ao PD7

int main() {

    DDRD |= LED; \\ Configura o LED como saída
    DDRD &= ~BUTTON; \\ Configura o BUTTON como entrada

    PORTD |= BUTTON; \\ Ativa o resistor de pull-up interno do BUTTON

    while (1) {
        if (BUTTON_PRESS) {
            PORTD ^= LED;
            while (BUTTON_PRESS) {
                _delay_ms(10)
            }
        }
    }
    return 0;
}