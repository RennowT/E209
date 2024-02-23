#include <avr/io.h>
#include <util/delay.h>

#define ACENDE_LED_GREEN 0
#define ACENDE_LED_YELLOW 1
#define ACENDE_LED_RED 2

#define LED_GREEN PD2
#define LED_YELLOW PD3
#define LED_RED PD4

int main() {
  
  DDRD |= LED_GREEN | LED_YELLOW | LED_RED;
  uint8_t estado = 0;
  
  while (1) {
    switch (estado)
    {
    case ACENDE_LED_GREEN:
      PORTD |= LED_GREEN;
      PORTD &= ~(LED_RED | LED_YELLOW);
      _delay_ms(12000);
      estado = ACENDE_LED_YELLOW;
      break;

    case ACENDE_LED_YELLOW:
      PORTD |= LED_YELLOW;
      PORTD &= ~(LED_RED | LED_GREEN);
      _delay_ms(3000);
      estado = ACENDE_LED_RED;
      break;

    case ACENDE_LED_RED:
      PORTD |= LED_RED;
      PORTD &= ~(LED_GREEN | LED_YELLOW);
      _delay_ms(15000);
      estado = ACENDE_LED_GREEN;
      break;
    
    default:
      break;
    }
  }
  return 0;
}
