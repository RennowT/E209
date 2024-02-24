#define DESLIGADO 0
#define DESLIGANDO 1
#define M1_LIGADO 2
#define M1_DESLIGADO 3
#define M2_LIGADO 4
#define M2_DESLIGADO 5
#define ME_LIGADO 6
#define ME_DESLIGADO 7
#define L_LIGADO 8
#define L_DESLIGADO 9

int main() {
    unsigned char estado;
    unsigned char sensor1, sensor2, sensor3, sensor4, tempoDeLuzAtiva;
    unsigned char motor1Ativo, motor2Ativo, motorEAtivo, luzAtiva;
    unsigned char comandoLigar, comandoDesligar;

    while (1) {

        switch (estado)
        {
        case DESLIGADO:
            motor1Ativo = 0;
            motor2Ativo = 0;
            motorEAtivo = 0;
            luzAtiva = 0;
            if (comandoLigar) {
                estado = M1_LIGADO;
            } else if (comandoDesligar) {
                estado = DESLIGADO;
            }
            break;

        case M1_LIGADO:
            motor1Ativo = 1;
            motor2Ativo = 0;
            motorEAtivo = 0;
            luzAtiva = 0;
            if (sensor1) {
                estado = M1_DESLIGADO;
            } else if (comandoDesligar) {
                estado = DESLIGADO;
            }
            break;

        case M1_DESLIGADO:
            motor1Ativo = 0;
            motor2Ativo = 0;
            motorEAtivo = 0;
            luzAtiva = 0;
            if (sensor1) {
                estado = ME_LIGADO;
            } else if (comandoDesligar) {
                estado = DESLIGADO;
            }
            break;

        case ME_LIGADO:
            motor1Ativo = 0;
            motor2Ativo = 0;
            motorEAtivo = 1;
            luzAtiva = 0;
            if (sensor2) {
                estado = ME_DESLIGADO;
            } else if (comandoDesligar) {
                estado = DESLIGADO;
            }
            break;

        case ME_DESLIGADO:
            motor1Ativo = 0;
            motor2Ativo = 0;
            motorEAtivo = 0;
            luzAtiva = 0;
            if (sensor2) {
                estado = M2_LIGADO;
            } else if (comandoDesligar) {
                estado = DESLIGADO;
            }
            break;

        case M2_LIGADO:
            motor1Ativo = 0;
            motor2Ativo = 1;
            motorEAtivo = 0;
            luzAtiva = 0;
            if (sensor3) {
                estado = M2_DESLIGADO;
            } else if (tempoDeLuzAtiva == 3) {
                estado = DESLIGADO;
            } else if (comandoDesligar) {
                estado = DESLIGADO;
            }
            break;

        case M2_DESLIGADO:
            motor1Ativo = 0;
            motor2Ativo = 0;
            motorEAtivo = 0;
            luzAtiva = 0;
            if (sensor3) {
                estado = L_LIGADO;
            } else if (comandoDesligar) {
                estado = DESLIGADO;
            }
            break;

        case L_LIGADO:
            motor1Ativo = 0;
            motor2Ativo = 0;
            motorEAtivo = 0;
            luzAtiva = 1;
            if (sensor3 && tempoDeLuzAtiva == 3){
                estado = L_DESLIGADO;
            } else if (comandoDesligar) {
                estado = DESLIGADO;
            }
            break;

        case L_DESLIGADO:
            motor1Ativo = 0;
            motor2Ativo = 0;
            motorEAtivo = 0;
            luzAtiva = 0;
            if (sensor3) {
                estado = M2_LIGADO;
            } else if (comandoDesligar) {
                estado = DESLIGADO;
            }
            break;
        
        default:
            break;
        }
    }

    return 0;
}