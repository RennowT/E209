#include <avr/io.h>
#include <avr/delay.h>

// Estados
#define FASE0 0
#define FASE1 1
#define FASE2 2
#define FASE3 3
#define LIBERADO 4

// Definições das máscaras de bits para os botões e para o LED
#define BUTTON1 (1 << PB1)
#define BUTTON2 (1 << PB2)
#define BUTTON3 (1 << PB3)
#define BUTTON4 (1 << PB4)

#define BUTTON1_PRESS !(PINB & (1 << PB1)) // Verifica se o botão 1 está pressionado
#define BUTTON2_PRESS !(PINB & (1 << PB2)) // Verifica se o botão 2 está pressionado
#define BUTTON3_PRESS !(PINB & (1 << PB3)) // Verifica se o botão 3 está pressionado
#define BUTTON4_PRESS !(PINB & (1 << PB4)) // Verifica se o botão 4 está pressionado

#define LED (1 << PD3) // Máscara de bit para o LED

int main() {

    // Configura o pino do LED como saída
    DDRD |= LED;

    // Configura os pinos dos botões como entrada e os habilita com pull-up
    DDRB &= ~(BUTTON1 | BUTTON2 | BUTTON3 | BUTTON4);
    PORTB |= BUTTON1 | BUTTON2 | BUTTON3 | BUTTON4;

    unsigned char estado = FASE0;
   
    while (1) {
        switch (estado) {
            case FASE0:
                PORTD &= ~LED;
                if (!BUTTON1_PRESS && BUTTON2_PRESS && !BUTTON3_PRESS && !BUTTON4_PRESS) {
                    estado = FASE1;
                }
                break;

            case FASE1:
                if (!BUTTON1_PRESS && BUTTON2_PRESS && BUTTON3_PRESS && !BUTTON4_PRESS) {
                    estado = FASE2;
                } else if (!BUTTON1_PRESS && !BUTTON2_PRESS && !BUTTON3_PRESS && !BUTTON4_PRESS) {
                    estado = FASE0;
                }
                break;

            case FASE2:
                if (!BUTTON1_PRESS && BUTTON2_PRESS && BUTTON3_PRESS && BUTTON4_PRESS) {
                    estado = FASE3;
                } else if (!BUTTON1_PRESS && !BUTTON2_PRESS && !BUTTON3_PRESS && !BUTTON4_PRESS) {
                    estado = FASE0;
                }
                break;

            case FASE3:
                if (BUTTON1_PRESS && BUTTON2_PRESS && BUTTON3_PRESS && BUTTON4_PRESS) {
                    estado = LIBERADO;
                } else if (!BUTTON1_PRESS && !BUTTON2_PRESS && !BUTTON3_PRESS && !BUTTON4_PRESS) {
                    estado = FASE0;
                }
                break;

            case LIBERADO:
                PORTD |= LED;
                if (!BUTTON1_PRESS && !BUTTON2_PRESS && !BUTTON3_PRESS && !BUTTON4_PRESS) {
                    estado = FASE0;
                }
                break;
            
            default:
                break;
        }
    }
    return 0;
}
