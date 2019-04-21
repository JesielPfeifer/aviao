#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
//variaveis globais de controle

int m[6][29];
char letra;
int num;
float vuser=0;

float vToTEx = 0;
float vToTEc = 0;
float vToTSE = 0;
float vToTSR = 0;

typedef struct valor {
    float desc10, desc20Ex, desc20SE, desc30E, desc30SE, desc50SR, desc50E, desc70;
    float fat1, fat2, fat3, fat4;

} sVa;

void libera(char l, int n) {
    m[l][n] = -1;
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
    printf("|--SEM-RECLINAGEM---|\t |-----11-E-29-----|\t |-%.2f - 0.8-|\t|----%.2f - 70%%off---|\t |-----%.2f - 50%%off-----|\n\n",
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
        printf("\nCATEGORIA: ");
        printf("EXECUTIVA");
    } else if ((num <= 10 && num >= 7) || (num <= 28 && num >= 14)) {
        printf("\nCATEGORIA: ");
        printf("ECONOMICA");
    } else if (num == 12 || num == 13) {
        printf("\nCATEGORIA: ");
        printf("SAIDA DE EMERGENCIA");
    } else {
        printf("\nCATEGORIA: ");
        printf("SEM RECLINAGEM");
    }
}

void AssentoOcup(char letra, int num) {
    if (m[letra][num] >= 0) {
        printf("STATUS: ");
        printf("OCUPADO\n");
        printf("Idade: %d", m[letra][num]);
    } else {
        printf("STATUS: ");
        printf("VAGA LIVRE");
    }
}

int valorPassStatus(char l, int n, float vuser) {
    sVa v;
    v.fat1 = vuser * 2.5;
    v.desc20Ex = v.fat1 * 0.8;
    v.desc10 = v.fat1 * 0.9;
    v.fat2 = vuser * 0.9;
    v.desc30E = v.fat2 * 0.7;
    v.desc50E = v.fat2 * 0.5;
    v.fat4 = vuser * 0.8;
    v.desc70 = v.fat4 * 0.3;
    v.desc50SR = v.fat4 * 0.5;
    if (m[l][n] < 0) { //SE TIVER VAZIO
        if (n <= 6 && n >= 0) { //executiva
            printf("Valor adulto: %.2f\n", v.fat1);
            printf("Valor criancas de 0 a < 2: %.2f\n", v.desc20Ex);
            printf("Valor criancas de 2 a < 12: %.2f\n", v.desc10);
        } else if ((n <= 10 && n >= 7) || (n <= 28 && n >= 14)) { // economica

            printf("Adulto: %.2f\n", v.fat2);
            printf("Criancas de 0 a < 2: %.2f\n", v.desc50E);
            printf("Criancas de 2 a < 12: %.2f\n", v.desc30E);
        } else if (n == 12 || n == 13) { //saida de emergencia
            v.fat3 = vuser * 1.1;
            v.desc30SE = v.fat3 * 0.7;
            v.desc20SE = v.fat3 * 0.8;
            printf("Adulto: %.2f\n", v.fat3);
            printf("Valor criancas de 0 a < 2: %.2f\n", v.desc30SE);
            printf("Valor criancas de 2 a < 12: %.2f\n", v.desc20SE);
        } else { //SEM RECLINAGEM

            printf("Adulto: %.2f\n", v.fat4);
            printf("Valor criancas de 0 a < 2: %.2f\n", v.desc70);
            printf("Valor criancas de 2 a < 12: %.2f\n", v.desc50SR);
        }

    } else {
        if(n <= 6 && n >= 0) {
            if(m[l][n]>=0 && m[l][n]<2) { //executiva
                printf("Valor da passagem eh: %.2f", v.desc20Ex);
            } else if(m[l][n]>=2 && m[l][n]<=12) {
                printf("Valor da passagem eh: %.2f", v.desc10);
                printf("21");
            } else {
                printf("Valor da passagem eh: %.2f", v.fat1);
            }
        } else if((n <= 10 && n >= 7) || (n <= 28 && n >= 14)) { //economica
            if(m[l][n]>=0 && m[l][n]<2) {
                printf("Valor da passagem eh: %.2f", v.desc50E);
            } else if(m[l][n]>=2 && m[l][n]<=12) {
                printf("Valor da passagem eh: %.2f", v.desc30E);
            } else {
                printf("Valor da passagem eh: %.2f",v.fat2);
            }
        } else if(n == 12 || n == 13) {
            if(m[l][n]>=0 && m[l][n]<2) {
                printf("Valor da passagem eh: %.2f", v.desc30SE);
            } else if(m[l][n]>=2 && m[l][n]<=12) {
                printf("Valor da passagem eh: %.2f",v.desc20SE);
            } else {
                printf("Valor da passagem eh: %.2f", v.fat3);
            }
        } else {
            if(m[l][n]>=0 && m[l][n]<2) {
                printf("Valor da passagem eh: %.2f",v.desc70);
            } else if(m[l][n]>=2 && m[l][n]<=12) {
                printf("Valor da passagem eh: %.2f", v.desc50SR);
            } else {
                printf("Valor da passagem eh: %.2f", v.fat4);
            }
        }
    }
}

float vPass2(int l,int n, float vuser, int idade) {
    sVa v;
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
    float k=0;
    if(n <= 6 && n >= 0) {
        if(idade >=0 && idade<2) { //executiva
            k=v.desc20Ex;
        } else if(idade>=2 && idade<=12) {
            k=v.desc10;
        } else {
            k=v.fat1;
        }
    } else if((n <= 10 && n >= 7) || (n <= 28 && n >= 14)) { //economica
        if(idade>=0 && idade<2) {
            k = v.desc50E;
        } else if(idade>=2 && idade<=12) {
            k = v.desc30E;
        } else {
            k = v.fat2;
        }
    } else if(n == 12 || n == 13) {
        if(idade>=0 && idade<2) {
            k = v.desc30SE;
        } else if(idade>=2 && idade<=12) {
            k = v.desc20SE;
        } else {
            k = v.fat3;
        }
    } else {
        if(idade>=0 && m[l][n]<2) {
            k = v.desc70;
        } else if(idade>=2 && idade<=12) {
            k = v.desc50SR;
        } else {
            k = v.fat4;
        }
    }
    return k;
}

void leAssento() {
    do {
        printf("Digite o assento: (A ate F e 1 ate 29)\n"); //PEDE O ASSENTO PARA O USUARIO
        fflush(stdin);
        scanf("%c%d", &letra, &num);
        if (letra > 70) {
            letra -= 32;
        }
        if(letra < 65 || letra > 70 || num < 1 || num > 29) {
            printf("\nOpcao invalida digite novamente.\n"); //PEDE O ASSENTO PARA O USUARIO
        }

    } while (letra < 65 || letra > 70 || num < 1 || num > 29);   //VERIFICA VALORES INSERIDOS PELO USUARIO
}

int reservados() {
    int reservados=0;
    for(int i=0; i<6; i++) {
        for(int j=0; j<29; j++) {
            if(m[i][j]>=0) {
                reservados++;
            }
        }
    }
    return reservados;
}

int liberados() {
    int liberados=0;
    for(int i=0; i<6; i++) {
        for(int j=0; j<29; j++) {
            if(m[i][j]<0) {
                liberados++;
            }
        }
    }
    return liberados;
}

int total() {
    int linha = sizeof(m) / sizeof(m[0]);
    int col = sizeof(m[0]) / sizeof(m[0][0]);

    return linha*col;
}

int toPorcentagem(float p) {
    int porCent = 0;
    for(int i=0; i<=100; i+=5) {
        if(p<(i+2.5)) {
            porCent = i/5;
            break;
        }
    }
    return porCent;
}

void graficoA() {
    int rev = reservados();
    int lib = liberados();
    int tot = total();

    float porcentagemRev = (100.0*rev)/tot;
    int pRev = toPorcentagem(porcentagemRev);

    float porcentagemLib = (100.0*lib)/tot;
    int pLib = toPorcentagem(porcentagemLib);

    printf("Reservados:\t%3d - \t%5.1f%% [", rev, porcentagemRev);
    toGrafico(pRev);
    printf("]\n");
    printf("Liberados: \t%3d - \t%5.1f%% [", lib, porcentagemLib);
    toGrafico(pLib);
    printf("]\n");
    printf("Total:     \t%3d - \t%5.1f%% [", tot, 100.0);
    toGrafico(20);
    printf("]\n");
}

void graficoB() {
    int rev = reservados();
    int tamLinha= total()/6;

    int ocupado=0;
    char linha;
    for(int i=0; i<6; i++) {
        ocupado=0;
        linha = i / -1 + 'F';
        for(int j=0; j<29; j++) {
            if(m[i][j]>=0) {
                ocupado++;
            }
        }
        float porcentagem = (100.0*ocupado)/tamLinha;
        int porCent = toPorcentagem(porcentagem);

        printf("%c: \t\t%3d - \t%5.1f%% [", linha, ocupado, porcentagem);
        toGrafico(porCent);
        printf("]\n");
    }
    printf("Total:     \t%3d - \t%5.1f%% [", rev, 100.0);
    toGrafico(20);
    printf("]\n");
}

void graficoC() {
    int rev = reservados();
    int tamLinha = total()/6;
    int idadeZeroDois = 0;
    int idadeDoisDoze = 0;
    int idadeDozeVinte = 0;
    int idadeVinteSessenta = 0;
    int idadeSessentaNoventa = 0;
    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++) {
            if(m[i][j]>=0 && m[i][j]<=2) {
                idadeZeroDois++;
            } else if(m[i][j]>2 && m[i][j]<=12) {
                idadeDoisDoze++;
            } else if(m[i][j]>12 && m[i][j]<=20) {
                idadeDozeVinte++;
            } else if(m[i][j]>20 && m[i][j]<=60) {
                idadeVinteSessenta++;
            } else if(m[i][j]>60) {
                idadeSessentaNoventa++;
            }
        }
    }

    float porcentagemZeroDois = 0;
    if(rev!=0) {
        porcentagemZeroDois = (100.0*idadeZeroDois)/rev;
        //printf("aaaaaaaaaaaaaaaaaaa: %f\n", porcentagemZeroDois)
    }
    int porCentZeroDois = toPorcentagem(porcentagemZeroDois);
    printf("00-02: \t\t%3d - \t%5.1f%% [", idadeZeroDois, porcentagemZeroDois);
    toGrafico(porCentZeroDois);
    printf("]\n");

    float porcentagemDoisDoze = 0;
    if(rev!=0) {
        porcentagemDoisDoze = (100.0*idadeDoisDoze)/rev;
    }
    int porCentDoisDoze = toPorcentagem(porcentagemDoisDoze);
    printf("02-12: \t\t%3d - \t%5.1f%% [", idadeDoisDoze, porcentagemDoisDoze);
    toGrafico(porCentDoisDoze);
    printf("]\n");

    float porcentagemDozeVinte = 0;
    if(rev!=0) {
        porcentagemDozeVinte = (100.0*idadeDozeVinte)/rev;
    }
    int porCentDozeVinte = toPorcentagem(porcentagemDozeVinte);
    printf("12-20: \t\t%3d - \t%5.1f%% [", idadeDozeVinte, porcentagemDozeVinte);
    toGrafico(porCentDozeVinte);
    printf("]\n");

    float porcentagemVinteSessenta = 0;
    if(rev!=0) {
        porcentagemVinteSessenta = (100.0*idadeVinteSessenta)/rev;
    }
    int porCentVinteSessenta = toPorcentagem(porcentagemVinteSessenta);
    printf("12-20: \t\t%3d - \t%5.1f%% [", idadeVinteSessenta, porcentagemVinteSessenta);
    toGrafico(porCentVinteSessenta);
    printf("]\n");

    float porcentagemSessentaNoventa = 0;
    if(rev!=0) {
        porcentagemSessentaNoventa = (100.0*idadeSessentaNoventa)/rev;
    }
    int porCentSessentaNoventa = toPorcentagem(porcentagemSessentaNoventa);
    printf("12-20: \t\t%3d - \t%5.1f%% [", idadeSessentaNoventa, porcentagemSessentaNoventa);
    toGrafico(porCentSessentaNoventa);
    printf("]\n");


    printf("Total:     \t%3d - \t%5.1f%% [", rev, 100.0);
    toGrafico(20);
    printf("]\n");
}

void toGrafico(int multi5) {
    for(int i=0; i<20; i++) {
        if(multi5>i) {
            printf("=");
        } else {
            printf(".");
        }
    }
}

int main() {
    inicializa();
    setlocale(LC_ALL, "portuguese");
    int opcao, idade;
    char confirm;
    //garantindo valor positivo inserido pelo user
    do {
        printf("Para iniciar o programa digite o valor base da sua passagem,\nlembrando que o valor deve ser acima de zero (0): ");
        scanf("%f", &vuser);
    } while (vuser <= 0);

    while (1) {
        system("cls");
        mapa();
        printf("O valor base da sua passagem eh: %.2f", vuser);
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

            mapa();
            leAssento();
            if (m[parseIndex(letra)][parseIndex2(num)] >= 0) {//VERIFICA SE O ASSENTO JA ESTA SENDO USADO
                printf("Vaga ja ocupada!\n");
                Sleep(1500); //VALOR MILISEGUNDOS TEMPO DE ESPERA
                break;
            }
            do {
                printf("Digite sua idade (0 ate 99): ");
                scanf("%d", &idade);
                if(idade>99 || idade<0) {
                    printf("\nIdade invalida, digite novamente\n");
                }
            } while(idade>99 || idade<0);
            printf("Voce escolheu o assento %c%d com valor de R$%.2f. Deseja confirmar a reserva?\n[S][N]: ", letra, num, vPass2(parseIndex(letra),num, vuser, idade));
            do {
                scanf("%c", &confirm);
            } while ((confirm != 'S') && (confirm != 's') && (confirm != 'n') &&
                     (confirm != 'N'));   //VERIFICA SE A OPCAO COLOCADA EH IGUAL AOS PADROES ACEITOS
            if ((confirm == 's') || (confirm == 'S')) {

                m[parseIndex(letra)][parseIndex2(num)] = idade;

            } else {
                printf("Reserva nao confirmada!");
                Sleep(1500);
            }
            break;
        case 3:
            mapa();
            leAssento();

            if (m[parseIndex(letra)][parseIndex2(num)] < 0) {
                printf("Vaga ja desocupada!\n");
                Sleep(1500); //VALOR MILISEGUNDOS TEMPO DE ESPERA
                break;
            }
            printf("\nDeseja confirmar a liberacao do assento %c%d?[S][N]: ", letra, num);
            fflush(stdin);
            do {
                scanf("%c", &confirm);
            } while ((confirm != 'S') && (confirm != 's') && (confirm != 'n') && (confirm != 'N'));
            if ((confirm == 'n') || (confirm == 'N')) {
                printf("Liberacao nao confirmada!");
                Sleep(1500);
                break;
            }
            libera(parseIndex(letra), parseIndex2(num));
            printf("\nLiberando vaga!");
        Sleep(1500);
        break;
    case 4:
        mapa();
        leAssento();
        catAssento(num);
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
    case 6:
        graficoA();
        printf("\n");
        graficoB();
        printf("\n");
        graficoC();
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

