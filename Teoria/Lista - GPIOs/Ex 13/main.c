#include <avr/io.h>
#include <avr/delay.h>

// Definição das constantes para os estados
#define OFF 0
#define LED1_ON 1
#define LED2_ON 2

// Definição das máscaras de bits para os pinos dos LEDs
#define LED1 (1 << PD2)
#define LED2 (1 << PC0)

// Definição das máscaras de bits para os pinos dos BUTTONs
#define BUTTON1 (1 << PB0)
#define BUTTON2 (1 << PB1)
#define BUTTON3 (1 << PB2)
#define BUTTON4 (1 << PB3)
#define BUTTON5 (1 << PB4)

#define BUTTON1_PRESS !(PINB & (1 << PB0)) // Verifica se o botão 1 está pressionado
#define BUTTON2_PRESS !(PINB & (1 << PB1)) // Verifica se o botão 2 está pressionado
#define BUTTON3_PRESS !(PINB & (1 << PB2)) // Verifica se o botão 3 está pressionado
#define BUTTON4_PRESS !(PINB & (1 << PB3)) // Verifica se o botão 4 está pressionado
#define BUTTON5_PRESS !(PINB & (1 << PB4)) // Verifica se o botão 5 está pressionado

int verificaEstadoLED1ON () {
    if (BUTTON1_PRESS && !BUTTON2_PRESS && BUTTON3_PRESS && !BUTTON4_PRESS && BUTTON5_PRESS) {
        return 1;
    } else if (!BUTTON1_PRESS && BUTTON2_PRESS && !BUTTON3_PRESS && BUTTON4_PRESS && !BUTTON5_PRESS) {
        return 1;
    }

    return 0;
}

int verificaEstadoLED2ON () {
    if (BUTTON1_PRESS && BUTTON2_PRESS && BUTTON3_PRESS && BUTTON4_PRESS && BUTTON5_PRESS) {
        return 1;
    } else if (!BUTTON1_PRESS && !BUTTON2_PRESS && !BUTTON3_PRESS && !BUTTON4_PRESS && !BUTTON5_PRESS) {
        return 1;
    }

    return 0;
}

int main() {
    // Configuração dos pinos como entrada ou saída
    DDRB &= ~(BUTTON1 | BUTTON2 | BUTTON3 | BUTTON4 | BUTTON5);  // Configura os pinos PB0, PB1, PB2, PB3 e PB4 como entrada
    DDRD |= LED1; // Configura o pino PD2 como saída para o LED1
    DDRC |= LED2; // Configura o pino PC0 como saída para o LED2

    PORTB |= BUTTON1 | BUTTON2 | BUTTON3 | BUTTON4 | BUTTON5; // Habilita o pull-up dos pinos dos botões

    // Variável para armazenar o estado atual
    unsigned char estado = OFF;

    // Loop principal do programa
    while (1) {
        // Switch-case para controlar o comportamento com base no estado atual
        switch (estado) {
        case OFF:
            // Desliga ambos os LEDs
            PORTD &= ~LED1;
            PORTC &= ~LED2;
            // Verifica as condições para mudança de estado
            if (verificaEstadoLED1ON()) {
                estado = LED1_ON;  // Se algum botão estiver pressionado, muda para LED1_ON
            } else if (verificaEstadoLED2ON()) {
                estado = LED2_ON;  // Se todos os botões estiverem pressionados, muda para LED2_ON
            } else {
                estado = OFF;      // Caso contrário, mantém o estado OFF
            }
            break;

        case LED1_ON:
            // Liga o LED1 e desliga o LED2
            PORTD |= LED1;
            PORTC &= ~LED2;
            // Verifica as condições para mudança de estado
            if (verificaEstadoLED1ON()) {
                estado = LED1_ON;  // Se algum botão estiver pressionado, muda para LED1_ON
            } else if (verificaEstadoLED2ON()) {
                estado = LED2_ON;  // Se todos os botões estiverem pressionados, muda para LED2_ON
            } else {
                estado = OFF;      // Caso contrário, mantém o estado OFF
            }
            break;

        case LED2_ON:
            // Desliga o LED1 e liga o LED2
            PORTD &= ~LED1;
            PORTC |= LED2;
            // Verifica as condições para mudança de estado
            if (verificaEstadoLED1ON()) {
                estado = LED1_ON;  // Se algum botão estiver pressionado, muda para LED1_ON
            } else if (verificaEstadoLED2ON()) {
                estado = LED2_ON;  // Se todos os botões estiverem pressionados, muda para LED2_ON
            } else {
                estado = OFF;      // Caso contrário, mantém o estado OFF
            }
            break;
        
        default:
            break;
        }
    }
    return 0;
}
