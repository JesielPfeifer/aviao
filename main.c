#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
//variaveis globais de controle

int m[6][29];
typedef struct valor {
    float desc10, desc20Ex, desc20SE, desc30E, desc30SE, desc50SR, desc50E, desc70;
    float fat1, fat2, fat3, fat4;
} sVa;

//-------------------------------
int libera(char l, int n) {
    int k = 0;
    if (m[l][n] > 0) {
        k = 1;
    }
    return k;
    system("pause");
}

int parseIndex2(int n) {
    return n - 1;
}

int parseIndex(char l) {
    int n;
    n = (l - 'F') * -1;
    return n;
}

void tabela(float vuser) {
    sVa v; //

    v.fat1 = vuser * 2.5; //EXECUTIVA
    v.fat2 = vuser * 0.9; //ECONOMICA
    v.fat3 = vuser * 1.1; //SAIDA DE EMERGENCIA
    v.fat4 = vuser * 0.8; //SEM RECLINAGEM

    v.desc10 = v.fat1 * 0.9; //10% DESCONTO EXECUTIVA 2<12
    v.desc20Ex = v.fat1 * 0.8; //20% DESCONTO EXECUTIVA 0<2
    v.desc20SE = v.fat3 * 0.8; //20% SAIDA DE EMERGENCIA 2<12
    v.desc30SE = v.fat3 * 0.7; //30% SAIDA DE EMERGENCIA 2<12
    v.desc30E = v.fat2 * 0.7; //30% DESCONTO ECONOMICA 2<12
    v.desc50SR = v.fat4 * 0.5; //50% DESCONTO SEM RECLINAGEM 2<12
    v.desc50E = v.fat2 * 0.5; //50% DESCONTO ECONOMICA 0<2
    v.desc70 = v.fat4 * 0.3; //70% DESCONTO SEM RECLINAGEM 0<2

    printf("/:::::::::::::::::::::::::::::::::::TABELA DE VALORES ::::::::::::::::::::::::::::::\\\n\n");
    printf("|=====CATEGORIA=====|\t |====FILEIRAS=====|\t |  FATOR  |\t|DESCONTO 0<2 ANOS|\t |DESCONTO 2 A 12 ANOS|\n");
    printf("|-------------------|\t |-----------------|\t |---------|\t|-----------------|\t |--------------------|\n");
    printf("|----EXECUTIVA------|\t |-----01-A-06-----|\t |-%.2f - 2.5-|\t|----%.2f - 20%%off---|\t |-----%.2f - 10%%off-----|\n",
           v.fat1, v.desc20Ex, v.desc10);
    printf("|----ECONOMICA------|\t |07-A-10 e 14-A-28|\t |-%.2f - 0.9-|\t|----%.2f - 50%%off---|\t |-----%.2f - 30%%off-----|\n",
           v.fat2, v.desc50E, v.desc30E);
    printf("|SAIDA-DE-EMERGENCIA|\t |-----12-A-13-----|\t |-%.2f - 1.1-|\t|----%.2f - 30%%off---|\t |-----%.2f - 20%%off-----|\n",
           v.fat3, v.desc30SE, v.desc20SE);
    printf("|--SEM-RECLINAGEM---|\t |-----11-A-29-----|\t |-%.2f - 0.8-|\t|----%.2f - 70%%off---|\t |-----%.2f - 50%%off-----|\n\n",
           v.fat4, v.desc70, v.desc50SR);
    system("pause");

}

void inicializa() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 29; j++) {
            m[i][j] = -1;
        }
    }
}

void mapa() {
    char letra;
    //char linha1[88];

    printf("                                /::::::::::::::::::::| \n");
    printf("                               /:::::::::::::::::::::| \n");
    printf("                              /::::::::::::::::::::::| \n");
    printf("  01 02 03 04 05 06 | 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29  \n");
    printf("-------------------------------------------------------------------------------------------- \n");

    for (int i = 0; i < 6; i++) {
        letra = i / -1 + 'F';
        if (i == 3) {
            printf("\n");
        }
        printf("%c|", letra);

        for (int j = 0; j < 29; j++) {

            if (m[i][j] < 0) {
                printf("-- ");
            } else {
                printf("%02d ", m[i][j]);
            }

            if (j == 5) {
                printf("| ");
            }
        }
        printf("|%c", letra);
        printf("\n");
    }
    printf("-------------------------------------------------------------------------------------------- \n");
    printf("  01 02 03 04 05 06 | 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 \n");
    printf("                              \\::::::::::::::::::::::::| \n");
    printf("                               \\:::::::::::::::::::::::| \n");
    printf("                                \\::::::::::::::::::::::| \n");
}

void catAssento(int num) {
    if (num <= 6 && num >= 1) {
        printf("EXECUTIVA");
    } else if ((num <= 10 && num >= 7) || (num <= 28 && num >= 14)) {
        printf("ECONOMICA");
    } else if (num == 12 || num == 13) {
        printf("SAIDA DE EMERGENCIA");
    } else {
        printf("SEM RECLINAGEM");
    }
}

void AssentoOcup(char letra, int num) {
    if (m[letra][num] > 0) {
        printf("OCUPADO\n");
        printf("Idade: %d\n", m[letra][num]);
    } else {
        printf("VAGA LIVRE");
    }
}

void valorPassStatus(char l, int n, float vuser) {
    sVa v;
    printf("%d\n", l);
    printf("%d\n", n);
    printf("%d\n", m[l][n]);
    if (m[l][n] < 0) {
        if (n <= 6 && n >= 1) { //executiva
            v.fat1 = vuser * 2.5;
            v.desc20Ex = v.fat1 * 0.8;
            v.desc10 = v.fat1 * 0.9;
            printf("Adulto: %.2f\n", v.fat1);
            printf("Criancas de 0 a < 2: %.2f\n", v.desc20Ex);
            printf("Criancas de 2 a < 12: %.2f\n", v.desc10);
        } else if ((n <= 10 && n >= 7) || (n <= 28 && n >= 14)) { // economica
            v.fat2 = vuser * 0.9;
            v.desc30E = v.fat2 * 0.7;
            v.desc50E = v.fat2 * 0.5;
            printf("Adulto: %.2f\n", v.fat2);
            printf("Criancas de 0 a < 2: %.2f\n", v.desc50E);
            printf("Criancas de 2 a < 12: %.2f\n", v.desc30E);
        } else if (n == 12 || n == 13) { //saida de emergencia
            v.fat3 = vuser * 1.1;
            v.desc30SE = v.fat3 * 0.7;
            v.desc20SE = v.fat3 * 0.8;
            printf("Adulto: %.2f\n", v.fat3);
            printf("Criancas de 0 a < 2: %.2f\n", v.desc30SE);
            printf("Criancas de 2 a < 12: %.2f\n", v.desc20SE);
        } else { //SEM RECLINAGEM
            v.fat4 = vuser * 0.8;
            v.desc70 = v.fat4 * 0.3;
            v.desc50SR = v.fat4 * 0.5;
            printf("Adulto: %.2f\n", v.fat4);
            printf("Criancas de 0 a < 2: %.2f\n", v.desc70);
            printf("Criancas de 2 a < 12: %.2f\n", v.desc50SR);
        }
    } else {
        printf("%d", m[l][n]);
    }


}

int main() {
    inicializa();
    setlocale(LC_ALL, "portuguese");
    int opcao, num, idade;
    char confirm, letra;
    float vuser;

    //garantindo valor positivo inserido pelo user
    do {
        printf("Para iniciar o programa digite o valor base da sua passagem,\nlembrando que o valor deve ser acima de zero (0): ");
        scanf("%f", &vuser);
    } while (vuser <= 0);

    while (1) {
        system("cls");
        mapa();
        printf("O valor base da sua passagem eh: %f", vuser);
        printf("\n----------------------------------------------------------------");
        printf("\n1 - LISTA DE VALORES");
        printf("\n2 - RESERVA DE ASSENTO");
        printf("\n3 - LIBERACAO DE ASSENTO");
        printf("\n4 - CONSULTAR SITUACAO DE UM ASSENTO");
        printf("\n5 - CONSULTAR DISPONIBILIDADES DE ASSENTOS CONSECUTIVOS");
        printf("\n6 - RELATORIOS");
        printf("\n7 - FECHAR PROGRAMA");
        printf("\n----------------------------------------------------------------");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                tabela(vuser);
                break;
            case 2:
                printf("Digite o assento: (A ate F 1 ate 29)\n"); //PEDE O ASSENTO PARA O USUARIO
                fflush(stdin);
                do {
                    scanf("%c%d", &letra, &num);
                    if (letra > 70) {
                        letra -= 32;
                    }

                } while ((letra < 65 || letra > 70) &&
                         (num < 1 || num > 29));   //VERIFICA VALORES INSERIDOS PELO USUARIO

                //VERIFICA SE O ASSENTO JA ESTA SENDO USADO
                if (m[parseIndex(letra)][parseIndex2(num)] > 0) {
                    system("cls");
                    printf("VAGA JA OCUPADA\n");
                    Sleep(1000); //VALOR MILISEGUNDOS TEMPO DE ESPERA
                    break;
                }

                printf("Digite sua idade: ");
                scanf("%d", &idade);
                printf("Voce escolheu o assento %c%d com valor de %d, deseja confirmar a reserva?[S][N]", letra, num);
                do {
                    scanf("%c", &confirm);
                } while ((confirm != 'S') && (confirm != 's') && (confirm != 'n') &&
                         (confirm != 'N'));   //VERIFICA SE A OPCAO COLOCADA EH IGUAL AOS PADROES ACEITOS
                if ((confirm == 's') || (confirm == 'S')) {
                    m[parseIndex(letra)][parseIndex2(num)] = idade;
                } else {
                    system("cls");
                    printf("RESERVA NAO CONFIRMADA");
                    Sleep(1000);
                }
                break;
            case 3:
                printf("Digite o assento (A ate F 1 ate 29): ");
                fflush(stdin);
                do {
                    scanf("%c%d", &letra, &num);
                } while ((letra < 65 || letra > 70) &&
                         (num < 1 || num > 29));
                printf("\nDESEJA CONFIRMAR A LIBERACAO DO ASSENTO %c%d?[S][N]: ", letra, num);
                fflush(stdin);
                do {
                    scanf("%c", &confirm);
                } while ((confirm != 'S') && (confirm != 's') && (confirm != 'n') && (confirm != 'N'));
                int result = libera(parseIndex(letra), parseIndex2(num));
                if (result == 1) {
                    printf("\nLIBERANDO VAGA");
                    m[parseIndex(letra)][parseIndex2(num)] = -1;
                } else {
                    printf("VAGA JA ESTA LIBERADA");
                }
                break;
            case 4:
                printf("Digite o assento (A ate F 1 ate 29): ");
                fflush(stdin);
                do {
                    scanf("%c%d", &letra, &num);
                } while ((letra < 65 || letra > 70) &&
                         (num < 1 || num > 29));
                //catAssento(num); //printa categoria
                printf("\n");
                AssentoOcup(parseIndex(letra), parseIndex2(num));
                printf("\n");
                valorPassStatus(parseIndex(letra), parseIndex2(num), vuser);
                printf("\n");
                system("pause");
                break;

            case 5:
                printf("Insira a quantidade de assento: ");
                fflush(stdin);
                scanf("%d", &num);
                int ant1 = -1, ant2 = -1, bNum = num, f = 0, fin1 = 0, fin2 = 0;
                for (int j = 0; j < 29; j++) {
                    f = 0;
                    for (int i = 0; i < 6; i++) {
                        if ((f == 0 && m[i][j] < 0) || (m[i][j] < 0 && m[ant1][ant2] < 0)) {
                            f++;
                        } else {
                            f = 0;
                        }
                        if (f >= num) {
                            fin1 = i;
                            fin2 = j;
                            printf("Assentos: ");
                            for (int k = fin1 - num + 1; k <= fin1; k++) {
                                letra = k / -1 + 'F';
                                if (k == fin1 - num + 1 || k == fin1) {
                                    printf("%c", letra);
                                    printf("%d ", fin2);
                                }
                            }
                            printf("\n");
                        }
                        ant1 = i;
                        ant2 = j;
                    }
                }
                printf("\n");
                system("pause");
                break;
            case 7:
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
