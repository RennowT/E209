#include <avr/io.h>
#include <avr/interrupt.h>

// Definir as frequências das notas em Hz
#define DO  264
#define RE  300
#define MI  330
#define FA  352
#define SOL 396
#define LA  440
#define SI  495

// Função para inicializar o ADC
void adc_init() {
    // Configurar ADMUX: Referência AVcc, Canal ADC0 inicialmente
    ADMUX = (1 << REFS0);
    
    // Configurar ADCSRA: Habilitar ADC, Prescaler 128 (16 MHz / 128 = 125 KHz)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// Função para ler o valor do ADC
uint16_t adc_read() {
    // Iniciar a conversão AD
    ADCSRA |= (1 << ADSC);
    
    // Esperar até que a conversão esteja completa
    while (ADCSRA & (1 << ADSC));
    
    // Retornar o valor lido
    return ADC;
}

// Função para configurar o Timer1 para gerar a frequência PWM para o buzzer
void timer1_set_frequency(uint16_t frequency) {
    // Calcular o valor do comparador para a frequência desejada
    uint16_t ocr_value = (16000000 / (2 * 8 * frequency)) - 1;
    
    // Configurar o registrador OCR1A com o valor calculado
    OCR1A = ocr_value;
    
    // Configurar o Timer1 no modo CTC com prescaler de 8
    TCCR1A = (1 << COM1A0); // Toggle OC1A (pino digital 9 no Arduino Uno)
    TCCR1B = (1 << WGM12) | (1 << CS11); // CTC mode, Prescaler 8
}

// Função para mapear o valor do ADC para a frequência da nota
uint16_t map_pressure_to_frequency(uint16_t adc_value) {
    // Converter o valor ADC (0-1023) para tensão (0-1.1V)
    float voltage = (adc_value / 1023.0) * 1.1;
    
    // Mapear a tensão para a nota musical
    if (voltage < 0.11) return DO;   // 0% - 10%: Dó
    else if (voltage < 0.22) return RE;   // 10% - 20%: Ré
    else if (voltage < 0.33) return MI;   // 20% - 30%: Mi
    else if (voltage < 0.44) return FA;   // 30% - 40%: Fá
    else if (voltage < 0.55) return SOL;  // 40% - 50%: Sol
    else if (voltage < 0.66) return LA;   // 50% - 60%: Lá
    else return SI;                       // >= 60%: Si
}

int main(void) {
    // Inicializar o ADC
    adc_init();
    
    // Configurar o pino do buzzer como saída
    DDRB |= (1 << DDB1); // PB1 (pino digital 9 no Arduino Uno)
    
    while (1) {
        // Ler o valor do ADC do sensor de pressão
        uint16_t adc_value = adc_read();
        
        // Mapear o valor do ADC para a frequência da nota
        uint16_t frequency = map_pressure_to_frequency(adc_value);
        
        // Configurar o Timer1 para gerar a frequência PWM correspondente
        timer1_set_frequency(frequency);
        
        // Pequena espera para estabilização
        _delay_ms(100);
    }
}
