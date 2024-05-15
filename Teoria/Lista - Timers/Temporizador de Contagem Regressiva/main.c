#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LED_1 PB0
#define LED_2 PB1
#define LED_3 PB2
#define LED_4 PB3
#define LED_5 PB4

volatile uint8_t percentagem = 100;
volatile uint8_t piscando = 0;

void timer_config() {
    TCCR0A |= (1 << WGM01);
    TCCR0B |= (1 << CS02) | (1 << CS00);
    OCR0A = 156;
    TIMSK0 |= (1 << OCIE0A); 
}

// Função de configuração dos LEDs
void leds_config() {
    DDRB |= 0b00011111;
}

void atualizar_leds() {
    uint8_t led_percentagem = percentagem / 20;
    PORTB &= ~0b00011111;
    for (uint8_t i = 0; i < led_percentagem; i++) {
        PORTB |= (1 << (LED_1 + i));
    }
}

ISR(TIMER0_COMPA_vect) {
    if (percentagem > 0) {
        percentagem--;
        atualizar_leds();
    } else {
        piscando = 1;
        PORTB &= ~0b00011111;
    }
}

int main(void) {
    sei();
    
    timer_config();
    leds_config();

    while (1) {
        if (piscando) {
            PORTB ^= 0b00011111;
            _delay_ms(250);
        }
    }

    return 0;
}
