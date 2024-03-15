#include <avr/io.h>
#include <avr/delay.h>

#define ABERTO 0
#define ABRINDO 1
#define FECHADO 2
#define FECHANDO 4

#define BT_FECHAR !(PIND & 0b00100000)
#define BT_ABRIR !(PIND & 0b00010000)
#define S_FECHADO !(PIND & 0b00001000)
#define S_ABERTO !(PIND & 0b00000100)

int main() {

  DDRD |= 0b11000000;
  DDRD &= ~(0b00111100);

  PORTD |= 0b00111100;

  unsigned char estadoPortao = FECHADO;

  while (1) {
    switch (estadoPortao) {
      case ABERTO:
        PORTD &= ~(0b11000000);
        if (BT_FECHAR) {
            estadoPortao = FECHANDO;
        }
        break;

      case ABRINDO:
        PORTD &= ~(0b10000000);
        PORTD |= 0b01000000;
        if (S_ABERTO) {
            estadoPortao = ABERTO;
        } else if (BT_FECHAR) {
            estadoPortao = FECHANDO;
        }
        break;

      case FECHADO:
        PORTD &= ~(0b00000000);
        if (BT_ABRIR) {
            estadoPortao = ABRINDO;
        }
        break;

      case FECHANDO:
        PORTD &= ~(0b01000000);
        PORTD |= 0b10000000;
        if (S_FECHADO) {
            estadoPortao = FECHADO;
        } else if (BT_ABRIR) {
            estadoPortao = ABRINDO;
        }
        break;
    
      default:
        break;
    }
  }
  
  return 0;
}
