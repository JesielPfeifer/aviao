#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
//variaveis globais de controle

int m[6][29];

//-------------------------------
/*int libera(char letra, int num, int parseIndex, int parseIndex2)
{
   if(m[parseIndex(letra)][parseIndex2(num)] > 0 )
   {
       printf("VAGA LIBERADA");
       m[parseIndex(letra)][parseIndex2(num)] = -1;
   }
   else 
   {
      printf("VAGA JA ESTA LIVRE"); 
   }
   system ("pause");
}
*/
int parseIndex2(int n)
{
    return n - 1;
}
int parseIndex(char l)
{
    int n;
    if (l == 65 || l == 97)
    {
        n = 5;
    }
    else if (l == 66 || l == 98)
    {
        n = 4;
    }
    else if (l == 67 || l == 99)
    {
        n = 3;
    }
    else if (l == 68 || l == 100)
    {
        n = 2;
    }
    else if (l == 69 || l == 101)
    {
        n = 1;
    }
    else
    {
        n = 0;
    }
    return n;
}
int tabela(int vuser)
{
    int desc10, desc20, desc30, desc50, desc70, fat1, fat2, fat3, fat4;
    fat1 = vuser * 2.5;
    fat2 = vuser * 0.9;
    fat3 = vuser * 1.1;
    fat4 = vuser * 0.8;
    desc10 = vuser * 0.9;
    desc20 = vuser * 0.8;
    desc30 = vuser * 0.7;
    desc50 = vuser * 0.5;
    desc70 = vuser * 0.3;

    printf("/:::::::::::::::::::::::::::::::::::TABELA DE VALORES ::::::::::::::::::::::::::::::\\\n\n");
    printf("|=====CATEGORIA=====|\t |====FILEIRAS=====|\t |FATOR|\t|DESCONTO 0<2 ANOS|\t |DESCONTO 2 A 12 ANOS|\n");
    printf("|-------------------|\t |-----------------|\t |-----|\t|-----------------|\t |--------------------|\n");
    printf("|----EXECUTIVA------|\t |-----01-A-06-----|\t |-%d - 2.5-|\t|---%d - 20%%off---|\t |----%d - 10%%off-----|\n", fat1, desc20, desc10);
    printf("|----ECONOMICA------|\t |07-A-10 e 14-A-28|\t |-%d - 0.9-|\t|---%d - 50%%off---|\t |----%d - 30%%off-----|\n", fat2, desc50, desc30);
    printf("|SAIDA-DE-EMERGENCIA|\t |-----12-A-13-----|\t |-%d - 1.1-|\t|---%d - 30%%off---|\t |----%d - 20%%off-----|\n", fat3, desc30, desc20);
    printf("|--SEM-RECLINAGEM---|\t |-----11-A-29-----|\t |-%d - 0.8-|\t|---%d - 70%%off---|\t |----%d - 50%%off-----|\n\n", fat4, desc70, desc50);
    system("pause");
}
void inicializa()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            m[i][j] = -1;
        }
    }
}

void mapa()
{
    printf("                                /::::::::::::::::::::| \n");
    printf("                               /:::::::::::::::::::::| \n");
    printf("                              /::::::::::::::::::::::| \n");
    printf("01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 \n");
    printf("-------------------------------------------------------------------------------------------- \n");

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            if (m[i][j] < 0)
            {
                printf("-- ");
            }
            else
            {
                printf("%d ", m[i][j]);
            }
        }
        printf("\n");
    }
    printf("-------------------------------------------------------------------------------------------- \n");
    printf("01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 \n");
    printf("                              \\::::::::::::::::::::::::| \n");
    printf("                               \\:::::::::::::::::::::::| \n");
    printf("                                \\::::::::::::::::::::::| \n");
}

int main()
{

    inicializa();
    setlocale(LC_ALL, "portuguese");
    int opcao, num, vuser, idade;
    char confirm, letra;

    //garantindo valor positivo inserido pelo user
    do
    {
        printf("Para iniciar o programa digite o valor base da sua passagem,\nlembrando que o valor deve ser acima de zero (0): ");
        scanf("%d", &vuser);
    } while (vuser <= 0);

    while (1)
    {
        system("cls");
        mapa();
        printf("O valor base da sua passagem eh: %d", vuser);
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

        switch (opcao)
        {
        case 1:
            tabela(vuser);
            break;
        case 2:
            printf("Digite o assento: (A ate F 1 ate 29)\n"); //PEDE O ASSENTO PARA O USUARIO
            fflush(stdin);
            do
            {
                scanf("%c", &letra);
                scanf("%d", &num);

            } while (((letra < 65 || letra > 70) && (letra < 97 || letra > 102)) || num < 1 || num > 29); //VERIFICA VALORES INSERIDOS PELO USUARIO

            //VERIFICA SE O ASSENTO JA ESTA SENDO USADO
            if (m[parseIndex(letra)][parseIndex2(num)] > 0)
            {
                system("cls");
                printf("VAGA JA OCUPADA\n");
                Sleep(1000); //VALOR MILISEGUNDOS TEMPO DE ESPERA
                break;
            }

            printf("Digite sua idade: ");
            scanf("%d", &idade);
            printf("Voc� escolheu o assento %c%d com valor de %d, deseja confirmar a reserva?[S][N]", letra, num);
            do
            {
                scanf("%c", &confirm);
            } while ((confirm != 'S') && (confirm != 's') && (confirm != 'n') && (confirm != 'N')); //VERIFICA SE A OPCAO COLOCADA EH IGUAL AOS PADROES ACEITOS
            if ((confirm == 's') || (confirm == 'S'))
            {
                m[parseIndex(letra)][parseIndex2(num)] = idade;
            }
            else
            {
                system("cls");
                printf("RESERVA NAO CONFIRMADA");
                Sleep(1000);
            }
            break;
        case 3:
            printf("Digite o assento: (A ate F 1 ate 29): ");
            fflush(stdin);
            do
            {
                scanf("%c", &letra);
                scanf("%d", &num);
            } while (((letra < 65 || letra > 70) && (letra < 97 || letra > 102)) || num < 1 || num > 29);
            printf("DESEJA CONFIRMAR A LIBERACAO DO ASSENTO?[S][N]: ");
            fflush(stdin);
            do
            {
                scanf("%c", &confirm);
            } while ((confirm != 'S') && (confirm != 's') && (confirm != 'n') && (confirm != 'N'));
            if((confirm == 's')||(confirm=='S'))
        {
            if (m[parseIndex(letra)][parseIndex2(num)] > 0)
            {
                printf("\nVAGA LIBERADA");
                m[parseIndex(letra)][parseIndex2(num)] = -1;
                Sleep(3000);
            }
            else
            {
                printf("\nVAGA JA ESTA LIVRE");
                Sleep(3000);
            }
        }
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
