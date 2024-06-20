#include <avr/io.h>
#include <util/delay.h>

void adc_init() {
    // Configurar ADMUX: Ref AVcc, Canal ADC0
    ADMUX = (1 << REFS0); // Referência AVcc com capacitor em AREF, entrada ADC0 (A0)
    
    // Configurar ADCSRA: Habilitar ADC, Prescaler 128 (16 MHz / 128 = 125 KHz)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t adc_read(uint8_t channel) {
    // Selecionar o canal de leitura
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    
    // Iniciar a conversão
    ADCSRA |= (1 << ADSC);
    
    // Esperar a conversão completar
    while (ADCSRA & (1 << ADSC));
    
    // Retornar o valor lido
    return ADC;
}

int main(void) {
    // Inicializar ADC
    adc_init();
    
    // Configurar os pinos dos LEDs como saída
    DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2); // Pinos 8, 9, 10
    
    while (1) {
        // Ler o valor do ADC (0 a 1023)
        uint16_t adc_value = adc_read(0);
        
        // Converter o valor AD para umidade percentual
        float humidity = (adc_value / 1023.0) * 100;
        
        // Controlar os LEDs com base na umidade
        if (humidity > 80) {
            // Acender LED Verde, Apagar outros
            PORTB |= (1 << PORTB2);  // LED Verde (Pino 10)
            PORTB &= ~((1 << PORTB0) | (1 << PORTB1)); // Apagar LEDs Vermelho e Amarelo
        } else if (humidity >= 50) {
            // Acender LED Amarelo, Apagar outros
            PORTB |= (1 << PORTB1);  // LED Amarelo (Pino 9)
            PORTB &= ~((1 << PORTB0) | (1 << PORTB2)); // Apagar LEDs Vermelho e Verde
        } else {
            // Acender LED Vermelho, Apagar outros
            PORTB |= (1 << PORTB0);  // LED Vermelho (Pino 8)
            PORTB &= ~((1 << PORTB1) | (1 << PORTB2)); // Apagar LEDs Amarelo e Verde
        }
        
        // Pequena espera para estabilizar a leitura
        _delay_ms(500);
    }
}
