#include <avr/io.h>
#include <avr/delay.h>

#define OFF 0
#define GREEN_ON 1
#define RED_ON 2
#define ON 3

#define BUTTON_PRESS !(PIND & 0b00100000)

int main() {
  DDRD |= 0b00000110;
  DDRD &= ~(0b00100000);
  PORTD |= 0b00100000;
  
  unsigned char state = OFF;

  while (1) {
    
    switch (state) {
    case OFF:
      PORTD |= 0b00100000;
      PORTD &= ~(0b00000110);
      if (BUTTON_PRESS) {
        state = GREEN_ON;
      }
      break;

    case GREEN_ON:
      PORTD |= 0b00100100;
      PORTD &= ~(0b00000010);
      if (BUTTON_PRESS) {
        state = RED_ON;
      }
      break;

    case RED_ON:
      PORTD |= 0b00100010;
      PORTD &= ~(0b00000100);
      if (BUTTON_PRESS) {
        state = ON;
      }
      break;

    case ON:
      PORTD |= 0b00100110;
      PORTD &= ~(0b00000000);
      if (BUTTON_PRESS) {
        state = OFF;
      }
      break;

    default:
      break;
    }

    while (BUTTON_PRESS){
      _delay_ms(1);
    }
    
  }
  
  return 0;
}