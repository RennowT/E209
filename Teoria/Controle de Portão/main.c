#define ABERTO 0
#define ABRINDO 1
#define FECHADO 2
#define FECHANDO 4

int main() {
    unsigned char estadoPortao = FECHADO;
    unsigned char MotorFechando, MotorAbrindo, SensorFechado, SensorAberto, ComandoFechar, ComandoAbrir;

    while (1) {
        switch (estadoPortao) {
            case ABERTO:
                MotorAbrindo = 0;
                MotorFechando = 0;
                if (ComandoFechar == 1) {
                    estadoPortao = FECHANDO;
                }
                break;

            case ABRINDO:
                MotorAbrindo = 1;
                MotorFechando = 0;
                if (SensorAberto == 1) {
                    estadoPortao = ABERTO;
                } else if (ComandoFechar == 1) {
                    estadoPortao = FECHANDO;
                }
                break;

            case FECHADO:
                MotorAbrindo = 0;
                MotorFechando = 0;
                if (ComandoAbrir == 1) {
                    estadoPortao = ABRINDO;
                }
                break;

            case FECHANDO:
                MotorAbrindo = 0;
                MotorFechando = 1;
                if (SensorFechado == 1) {
                    estadoPortao = FECHADO;
                } else if (ComandoAbrir == 1) {
                    estadoPortao = ABRINDO;
                }
                break;
            
            default:
                break;
        }
    }
    
    return 0;
}