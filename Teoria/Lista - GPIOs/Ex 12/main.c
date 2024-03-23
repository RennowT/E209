#include <avr/io.h>
#include <avr/delay.h>

#define LED1_ON 0
#define LED2_ON 1

#define LED1 (1 << PD2) // Define o pino PD2 como LED1
#define LED2 (1 << PD3) // Define o pino PD3 como LED2

#define BUTTON (1 << PD7) // Define o pino PD7 como BUTTON

#define BUTTON_PRESS !(PIND & (1 << PD7)) // Define a verificação do bit correspondente ao PD7

int main() {

    DDRD |= LED1 | LED2; // Configura o LED1 e LED2 como saída
    DDRD &= ~BUTTON; // Configura o BUTTON como entrada

    PORTD |= BUTTON; // Ativa o resistor de pull-up interno do BUTTON

    unsigned char estado = LED1_ON;

    while (1) {
        switch (estado) {
        case LED1_ON:
            PORTD |= LED1; // Ativa o LED1
            PORTD &= ~LED2; // Desativa o LED2
            if (BUTTON_PRESS) {
                estado = LED2_ON; 
                while (BUTTON_PRESS) {
                    _delay_ms(10);
                }
            }
            break;

        case LED2_ON:
            PORTD |= LED2; // Ativa o LED2
            PORTD &= ~LED1; // Desativa o LED1
            if (BUTTON_PRESS) {
                estado = LED1_ON;
                while (BUTTON_PRESS) {
                    _delay_ms(10);
                }
            }
            break;
        
        default:
            break;
        }
        
    }
    return 0;
}