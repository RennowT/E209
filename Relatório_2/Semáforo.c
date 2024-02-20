#include <avr/io.h>
#include <util/delay.h>

#define LED_GREEN 0b00000100
#define LED_YELLOW 0b00001000
#define LED_RED 0b00010000

int main() {
  
  DDRD |= 0b00011100;
  uint8_t estado = 0;
  
  while (1) {
    switch (estado)
    {
    case 0:
      PORTD |= LED_GREEN;
      PORTD &= ~(LED_RED | LED_YELLOW);
      _delay_ms(12000);
      estado++;
      break;

    case 1:
      PORTD |= LED_YELLOW;
      PORTD &= ~(LED_RED | LED_GREEN);
      _delay_ms(3000);
      estado++;
      break;

    case 2:
      PORTD |= LED_RED;
      PORTD &= ~(LED_GREEN | LED_YELLOW);
      _delay_ms(15000);
      estado = 0;
      break;
    
    default:
      break;
    }
  }
  return 0;
}
