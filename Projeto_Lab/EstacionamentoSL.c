#include "EstacionamentoSL.h"

void clrscr()
{
#if defined _WIN32 || defined _WIN64
    system("cls");
#else
    system ("clear");
#endif
}
void limpaBuffer(void)
{
    char c;
    while((c = getchar()) !='\n' && c != EOF);
}

int minutototal(int hora, int minuto)
{
    int T = (hora*60) + minuto;

    return T;
}

int Estacionamento(char nomesR, int lugar, int mesas, int estac)
{

    setlocale(LC_ALL, "Portuguese");
    memset(&carro, 0, sizeof(carro));
    memset(&listagem, 0, sizeof(listagem));


    menuP();
}

int menuP(){

    do
    {
        clrscr();

        printf("------------ Bem vindo ao Controle de Estacionamento. ------------\n\n"
               "\tSelecione uma Op��o:\n\n"
               "\t1 - Entrada de Ve�culo.\n\n"
               "\t2 - Listagem de Ve�culos e Vagas.\n\n"
               "\t3 - Sa�da de Ve�culo.\n\n"
               "\t4 - Voltar para a tela do restaurente.\n\n"
               "\tDISPON�VEIS: %02d VAGA(S).\n"
               "\tOCUPADAS: %02d VAGA(S).\n\n", totalVagas, NUM_VAGAS-totalVagas);

        printf(" Digite o n�mero escolhido: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            entradadecarro();
            break;

        case 2:
            mostrarlista();
            break;

        case 3:
            saidadecarro();
            break;

        case 4:
            vagasEstac(LETRAS, numero, horas, NUM_VAGAS-totalVagas);
            break;

        default:
            printf("N�o encontrada");
            //Restaurante(nomeR, lugar, mesas, estac);
            break;
        }
    }
    while(opcao != 4);

}

void entradadecarro(){
    limpaBuffer();
    for (i = 0; i < NUM_VAGAS; i++)
    {

        if(carro[i].posicao == 0)
        {
            registro++;
            carro[i].regcar = registro;
            clrscr();
            printf("A vaga ocupada N�'%02d'.\n\n", i+1);
            printf("Digite as letras do ve�culo no formato \"AAA\": ");
            scanf("%s", &carro[i].placa);
            LETRAS[4] = carro[i].placa;
            printf("Digite os numeros do ve�culo no formato \"1111\": ");
            scanf("%d", &carro[i].placa_NUM);
            numero = carro[i].placa_NUM;
            limpaBuffer();
            strupr(carro[i].placa);
            printf("Digite a hora (00 a 23)");
            scanf("%d", &carro[i].h1);
            horas = carro[i].h1;
            limpaBuffer();
            printf("Digite os minutos (00 a 59)");
            scanf("%d", &carro[i].m1);
            limpaBuffer();


            carro[i].posicao = 1;
            carro[i].valorT = 0;
            totalVagas--;
            printf("Deseja imprimir o RECIBO? S/N: ");
            scanf("%s", &escolha[2]);
            limpaBuffer();
            if((escolha[2] == 's') || (escolha[2] == 'S'))
            {
                clrscr();
                printf("\t*********************"
                        "\n\t|                    TICKET N�%03d\t\t\t|"
                        "\n\t*********************"
                        "\n\t|                  CUPOM DE ENTRADA\t\t\t|"
                        "\n\t| ESTACIONAMENTO EXLUSIVO PARA CLIENTES"
                        "\n\t| PLACA: %s%d\t\t\t\t\t|"
                        "\n\t| ENTRADA:\t\t\t\t\t\t|"
                        "\n\t| DIA %02d/%02d/%4d AS %02d:%02d.\t\t\t\t|"
                        "\n\t|\t\t\t\t\t\t\t|"
                        "\n\t*********************\n\n",
                        carro[i].regcar,
                        carro[i].placa, carro[i].placa_NUM,
                        dataDia, dataMes, dataAno, carro[i].h1, carro[i].m1);
            }
            system("pause");

        }
        if(totalVagas == 0)
        {
            printf("Estacionamento CHEIO. Favor aguardar.");
            system("pause");
        }
        menuP();
    }
}

void mostrarlista(){

    clrscr();
            limpaBuffer();
            printf("------------Listagem de Ve�culos e Vagas------------\n\n");

            for(listar = 0; listar < NUM_VAGAS; listar++)
            {
                printf("Vaga N� %02d: ", listar+1);

                if(carro[listar].posicao == 0)
                {
                    printf("Vaga LIVRE.\n");
                }
                else
                {
                    printf("%s %d.\tEntrou as %02d:%02d.\n", carro[listar].placa, carro[listar].placa_NUM, carro[listar].h1,carro[listar].m1);
                }
            }
            printf("\nFim da listagem.\n");
            system("pause");
    menuP();

}

void saidadecarro(){

    clrscr();
            limpaBuffer();
            printf("------------------------ Sa�da de Ve�culo ------------------------\n");
            for(listar = 0; listar < NUM_VAGAS; listar++)
            {
                if(listar % 2 == 0)
                {
                    printf("\tVaga N� %02d: ", listar+1);

                    if(carro[listar].posicao == 0)
                    {
                        printf("Vaga LIVRE.\t|\t");
                    }
                    else
                    {
                        printf("%s %d.\t|\t", carro[listar].placa, carro[listar].placa_NUM);
                    }
                }

                if(listar % 2 != 0)
                {
                    printf("Vaga N� %02d: ", listar+1);

                    if(carro[listar].posicao == NULL)
                    {
                        printf("Vaga LIVRE.\t\n");
                    }
                    else
                    {
                        printf("%s %d.\t\n", carro[listar].placa, carro[listar].placa_NUM);
                    }
                }
            }

            int n = 0;

            printf ("\n\nDigite as letras da placa: ");
            scanf("%s", &loc);
            printf ("\n\nDigite os numeros da placa: ");
            scanf("%d", &n);
            for(sair=0; sair<NUM_VAGAS; sair++)
            {
                int c = strlen(carro[sair].placa);
                if(strlen(loc) == c && n == carro[sair].placa_NUM)
                {
                    printf("Registro N�%03d.\n", carro[sair].regcar);
                    printf("Placa CONFIRMADA: %s %d.\n", carro[sair].placa, carro[sair].placa_NUM);

                    if(carro[sair].posicao == 1)
                    {
                        listagem[regAux] = carro[sair];
                        carro[sair].posicao = 0;
                        totalVagas++;
                        regAux++;
                        registro--;
                        break;
                    }

                }

            }
            system("pause");
            menuP();

}
