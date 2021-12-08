#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "estacionamento1.h"

FILE *arquivo;

void clrscr()
{
#if defined _WIN32 || defined _WIN64
    system("cls");
#else
// linux, mac os
    system ("clear");
#endif
}
/**< Fun��o que limpa o buffer de teclado. */
void limpaBuffer(void)
{
    char c;
    while((c = getchar()) !='\n' && c != EOF);
}
/**< Fun��o respons�vel por converter hora em minutos e
retornar o total de minutos. */
int minutototal(int hora, int minuto)
{
    int T = (hora*60) + minuto;

    return T;
}

/**< -------------------------------------------------------------------------------------------- */
/**< In�cio do programa. */
int principalE()
{

    arquivo = fopen("estacionamento_lab.txt", "r+");
    if(arquivo == NULL){
        printf("\nArquivo nao existe e sera criado agora como relat�rio...\n\n");
        arquivo = fopen("estacionamento_lab.txt", "r+");
    }

    setlocale(LC_ALL, "Portuguese"); //seta codifica��o para teclados baseados em portugu�s.
    struct Vaga carro[NUM_VAGAS]; //define o vetor "carro" com 20 posi��es alinhado ao struct.
    int opcao, i, listar, sair, box; //vari�veis para �ndice.
    int registro = 0, regAux = 0; //vari�veis de registro.
    int totalVagas=NUM_VAGAS, dataDia, dataMes, dataAno; //variaveis para data e total de vagas.
    char loc[8], escolha[2] = "n"; //String para entrada em procura de uma placa espec�fica.
    memset(&carro, 0, sizeof(carro)); //Limpa o lixo para exibi��o do vetor "carro".
    struct Vaga listagem[NUM_VAGAS];//define as exibi��es de entradas para o vetor "listagem".
    memset(&listagem, 0, sizeof(listagem)); //Limpa o lixo para exibi��o do vetor "listagem".

    carro[i].posicao == 0;


//------------------------------------------------------------------------------------------
    clrscr(); //Chama a fun��o que limpa a tela.
    printf("--------- Controle de estacionamento para os h�spedes do hotel ou para os clientes do restaurante---------\n\n");
    printf("Digite a data de hoje:\n");
    printf("Dia \"DD\": ");
    scanf("%d", &dataDia);
    printf("\nM�s corrente \"MM\": ");
    scanf("%d", &dataMes);
    printf("\nAno corrente \"AAAA\": ");
    scanf("%d", &dataAno);
    printf("\t %02d/%02d/%4d."
           "\n\n", dataDia, dataMes, dataAno);
    system("pause");//Espera que o usu�rio entre com um comando.
    /**< O la�o do{}while() ser� respons�vel por retornar para as op��es sempre depois que
    uma das op��es, a n�o ser que seja digitado o n�mero correspondente a finaliza��o do programa.*/
    do
    {
        clrscr(); //Chama a fun��o que limpa a tela.

        /**< Apresenta as op��es. */
        printf("------------ Bem vindo ao Controle de Estacionamento. ------------\n\n"
               "\tSelecione uma Op��o:\n\n"
               "\t1 - Entrada de Ve�culo.\n\n"
               "\t2 - Listagem de Ve�culos e Vagas.\n\n"
               "\t3 - Sa�da de Ve�culo.\n\n"
               "\t4 - Finalizar o programa.\n\n"
               "\tDISPON�VEIS: %02d VAGA(S).\n"
               "\tOCUPADAS: %02d VAGA(S).\n\n", totalVagas, NUM_VAGAS-totalVagas);


        /**< Pede a entrada de um comando com base na lista acima, numeros de 1 a 5. */
        printf(" Digite o n�mero escolhido: ");
        scanf("%d", &opcao); //Guarda a op��o escolhida para ser lan�ada no "switch".

        /**< De acordo com a op��o escolhida, chama o switch e faz a exibi��o conforme o
        "case" numerado. N�o temos um case "default" pela falta de necessidade.*/
        switch(opcao)
        {
/**< -------------------------------------------------------------------------------------------- */
        case 1: //Responsavel pela entrada de dados no vetor "carro".
            limpaBuffer();
            for (i = 0; i < NUM_VAGAS; i++)  //la�o que percorre o vetor "carro".
            {

                /**< se a variavel "posicao" dentro struct "temp" contida no vetor "carro"
                for igual a nulo (0) apresentam-se as op��es para entrada de placa e horas. */
                if(carro[i].posicao == 0)
                {
                    registro++;//Incrementa o contador de registros a cada registro.
                    carro[i].regcar = registro;//Atribui o valor de registro incrementado ao "regcar" no struc.
                    clrscr(); //Chama a fun��o que limpa a tela.
                    printf("A vaga ocupada N�'%02d'.\n\n", i+1);//Exibe a vaga onde o ve�culo ser� guardado.
                    printf("Digite as letras do ve�culo no formato \"AAA\": ");
                    scanf("%s", &carro[i].placa);//Entrada da placa.
                    printf("Digite os numeros do ve�culo no formato \"1111\": ");
                    scanf("%d", &carro[i].placa_NUM);//Entrada da placa.
                    limpaBuffer();
                    strupr(carro[i].placa);
                    printf("Digite a hora (00 a 23)");
                    scanf("%d", &carro[i].h1);//Entrada da hora inicial.
                    limpaBuffer();
                    printf("Digite os minutos (00 a 59)");
                    scanf("%d", &carro[i].m1);//Entrada do minuto inicial.
                    limpaBuffer();

                    printf("\nGravando o registro no arquivo...\n\n");
                    fseek(arquivo, 0, SEEK_END);
                    fprintf(arquivo, "\n\nCadastro realizado: Placa: %s%d | Entrada �s %02d:%02d horas\n", carro[i].placa, carro[i].placa_NUM, carro[i].h1, carro[i].m1);

                    fclose(arquivo);

                    /**< Seta a vaga como ocupada ao final do processo. O campo "posicao"
                    da struct � setado com "1" para que durante o processo de busca n�o
                    seja sobrescrito e possa exibir "Vaga LIVRE na op��o 2 do switch. */
                    carro[i].posicao = 1;
                    carro[i].valorT = 0;
                    totalVagas--;// Controla a quantidade de vagas exibidas DESOCUPADAS.
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
                               "\n\t| ESTACIONAMENTO EXLUSIVO PARA H�SPEDES"
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
                    break;//Quebra o la�o "for" finalizando a ENTRADA com sucesso.
                }
                if(totalVagas == 0)
                {
                    printf("Estacionamento CHEIO. Favor aguardar.");
                    break;
                    system("pause");
                }
            }

            break;
/**< -------------------------------------------------------------------------------------------- */
        case 2: //Responsavel pela listagem das vagas.
            clrscr(); //Chama a fun��o que limpa a tela.
            limpaBuffer();
            printf("------------Listagem de Ve�culos e Vagas------------\n\n");

            for(listar = 0; listar < NUM_VAGAS; listar++) //La�o que ir� percorrer o vetor.
            {
                printf("Vaga N� %02d: ", listar+1);//Imprime na tela o n�mero da vaga.

                /**< Se "posicao" for NULL, exibe "Vaga LiVRE". Sen�o, mostra a placa do carro
                que est� l�. */
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
            break;
/**< -------------------------------------------------------------------------------------------- */
        case 3://Respons�vel pela sa�da de ve�culos.
            clrscr(); //Chama a fun��o que limpa a tela.
            limpaBuffer();
            printf("------------------------ Sa�da de Ve�culo ------------------------\n");
            for(listar = 0; listar < NUM_VAGAS; listar++) //La�o que ir� percorrer o vetor.
            {
                if(listar % 2 == 0)
                {
                    printf("\tVaga N� %02d: ", listar+1);//Imprime na tela o n�mero da vaga.

                    /**< Se "posicao" for NULL, exibe "Vaga LiVRE". Sen�o, mostra a placa do carro
                    que est� l�. */
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
                    printf("Vaga N� %02d: ", listar+1);//Imprime na tela o n�mero da vaga.

                    /**< Se "posicao" for NULL, exibe "Vaga LiVRE". Sen�o, mostra a placa do carro
                    que est� l�. */
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
            scanf("%s", &loc);//Joga o valor digitado na vari�vel string "loc".
            printf ("\n\nDigite os numeros da placa: ");
            scanf("%d", &n);//Joga o valor digitado na vari�vel string "loc".
            for(sair=0; sair<NUM_VAGAS; sair++)//La�o que ir� percorrer o vetor.
            {
                int c = strlen(carro[sair].placa);
                /**< Se "loc" for igual a placa do ve�culo, inicia-se o processo de retirada
                do ve�culo. */
                if(strlen(loc) == c && n == carro[sair].placa_NUM)
                {
                    printf("Registro N�%03d.\n", carro[sair].regcar);//imprime o n�mero de registro �nico.
                    printf("Placa CONFIRMADA: %s %d.\n", carro[sair].placa, carro[sair].placa_NUM);//Confirma a placa.

                    /**< Condicional respons�vel por colocar a vaga em posi��o LIVRE. Se a
                    posi��o estiver setada como ocupada (1), coloque-a como vazia (0).*/
                    if(carro[sair].posicao == 1)
                    {

                        /**< Copia os dados da struct "Vaga" dentro do vetor "carro"
                        e os transfere para o struct "Vaga" dentro do vetor "listagem. */

                        listagem[regAux] = carro[sair];
                        carro[sair].posicao = 0;//Seta a vaga como vazia.
                        totalVagas++;// Controla a quantidade de vagas exibidas OCUPADAS.
                        regAux++;//Incrementa o auxiliar de registro a cada sa�da.
                        registro--;
                        break;//Quebra o la�o "for" finalizando a RETIRADA com sucesso.
                    }

                }

            }
            system("pause");
            break;
/**< -------------------------------------------------------------------------------------------- */
        case 4:
            clrscr(); //Chama a fun��o que limpa a tela.
            printf("\nO programa foi finalizado.\n\n");

/**< -------------------------------------------------------------------------------------------- */

        }
    }
    while(opcao != 4);


    return 0;
}
