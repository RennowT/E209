#include <avr/io.h>
#include <avr/interrupt.h>

volatile int sensores[2];  // Vetor para armazenar as leituras dos sensores
volatile uint8_t canal_atual = 0;  // Variável para alternar entre os canais

void adc_init() {
    // Configurar ADMUX: Referência AVcc, Canal ADC0 inicialmente
    ADMUX = (1 << REFS0);
    
    // Configurar ADCSRA: Habilitar ADC, Prescaler 128 (16 MHz / 128 = 125 KHz)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

void adc_start_conversion(uint8_t canal) {
    // Selecionar o canal de entrada no ADMUX
    ADMUX = (ADMUX & 0xF0) | (canal & 0x0F);
    
    // Iniciar a conversão AD
    ADCSRA |= (1 << ADSC);
}

void timer_init() {
    // Configurar Timer1 para gerar uma interrupção a cada 333 ms
    TCCR1A = 0; // Modo Normal
    TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10); // Prescaler 1024, Modo CTC
    OCR1A = 4999; // Freq. de interrupção = (16 MHz / (1024 * (4999 + 1))) ≈ 3 Hz
    TIMSK1 = (1 << OCIE1A); // Habilitar a interrupção de comparador A
}

ISR(TIMER1_COMPA_vect) {
    // Alternar entre os canais dos sensores
    if (canal_atual == 0) {
        adc_start_conversion(0); // Iniciar conversão para o canal 0 (Sensor de Luz)
    } else {
        adc_start_conversion(1); // Iniciar conversão para o canal 1 (Sensor de Gás)
    }
}

ISR(ADC_vect) {
    // Ler o valor convertido do ADC
    uint16_t adc_value = ADC;
    
    // Armazenar o valor no vetor sensores
    sensores[canal_atual] = adc_value;
    
    // Alternar o canal atual
    canal_atual = !canal_atual;
}

int main(void) {
    // Inicializar o ADC
    adc_init();
    
    // Habilitar interrupção de ADC
    ADCSRA |= (1 << ADIE);
    
    // Inicializar o Timer1
    timer_init();
    
    // Habilitar interrupções globais
    sei();
    
    while (1) {
        // O loop principal pode executar outras tarefas
        // As leituras dos sensores são feitas automaticamente pela interrupção
    }
}
