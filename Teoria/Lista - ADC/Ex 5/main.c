#include <avr/io.h>
#include <avr/interrupt.h>

#define BRANCO 1
#define PRETO 0
#define INDETERMINADO 2

volatile uint8_t leitura_atual = INDETERMINADO;
volatile uint8_t bit_index = 0;
volatile uint8_t sequencia[7]; // Armazenar a sequência de bits lidos

// Inicializa o ADC
void adc_init() {
    // Configurar ADMUX: Referência AVcc, Canal ADC0 inicialmente
    ADMUX = (1 << REFS0);
    
    // Configurar ADCSRA: Habilitar ADC, Prescaler 128 (16 MHz / 128 = 125 KHz)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// Ler o valor do ADC
uint16_t adc_read() {
    // Iniciar a conversão AD
    ADCSRA |= (1 << ADSC);
    
    // Esperar até que a conversão esteja completa
    while (ADCSRA & (1 << ADSC));
    
    // Retornar o valor lido
    return ADC;
}

// Configurar o Timer1 para interrupções de 1 Hz
void timer1_init() {
    // Configurar Timer1 para Modo CTC com Prescaler 1024
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
    OCR1A = 15624; // Configurar o comparador A para 1 Hz (16MHz / (1024 * (15624 + 1)))
    TIMSK1 = (1 << OCIE1A); // Habilitar interrupção de comparador A
}

// Interrupção do Timer1 a cada 1 segundo
ISR(TIMER1_COMPA_vect) {
    // Ler o valor do ADC
    uint16_t adc_value = adc_read();
    
    // Converter o valor do ADC para tensão
    float voltage = (adc_value / 1023.0) * 5.0;
    
    // Determinar o estado do quadro (Branco, Preto ou Indeterminado)
    if (voltage >= 4.0) {
        leitura_atual = BRANCO;
    } else if (voltage <= 3.5) {
        leitura_atual = PRETO;
    } else {
        leitura_atual = INDETERMINADO;
    }
    
    // Se a leitura for válida (Branco ou Preto), armazenar o bit na sequência
    if (leitura_atual != INDETERMINADO) {
        sequencia[bit_index] = leitura_atual;
        bit_index++;
        
        // Verificar se a sequência está completa (7 bits)
        if (bit_index == 7) {
            // Sequência completa, processar a sequência
            // Comparar a sequência com a sequência alvo 1010110
            uint8_t sequencia_correta[7] = {1, 0, 1, 0, 1, 1, 0};
            uint8_t igual = 1;
            for (uint8_t i = 0; i < 7; i++) {
                if (sequencia[i] != sequencia_correta[i]) {
                    igual = 0;
                    break;
                }
            }
            
            // Se a sequência lida for igual à sequência alvo, acender um LED ou realizar uma ação
            if (igual) {
                PORTB |= (1 << PORTB0); // Acender LED no pino digital 8
            } else {
                PORTB &= ~(1 << PORTB0); // Apagar LED
            }
            
            // Reiniciar a leitura para a próxima sequência
            bit_index = 0;
        }
    } else {
        // Se a leitura for indeterminada, reiniciar o processo
        bit_index = 0;
    }
}

int main(void) {
    // Inicializar o ADC
    adc_init();
    
    // Configurar o pino digital 8 como saída (LED de indicação)
    DDRB |= (1 << DDB0);
    
    // Inicializar o Timer1
    timer1_init();
    
    // Habilitar interrupções globais
    sei();
    
    while (1) {
        // O loop principal está vazio, todo o trabalho é feito nas interrupções
    }
}
