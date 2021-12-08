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
/**< Função que limpa o buffer de teclado. */
void limpaBuffer(void)
{
    char c;
    while((c = getchar()) !='\n' && c != EOF);
}
/**< Função responsável por converter hora em minutos e
retornar o total de minutos. */
int minutototal(int hora, int minuto)
{
    int T = (hora*60) + minuto;

    return T;
}

/**< -------------------------------------------------------------------------------------------- */
/**< Início do programa. */
int principalE()
{

    arquivo = fopen("estacionamento_lab.txt", "r+");
    if(arquivo == NULL){
        printf("\nArquivo nao existe e sera criado agora como relatório...\n\n");
        arquivo = fopen("estacionamento_lab.txt", "r+");
    }

    setlocale(LC_ALL, "Portuguese"); //seta codificação para teclados baseados em português.
    struct Vaga carro[NUM_VAGAS]; //define o vetor "carro" com 20 posições alinhado ao struct.
    int opcao, i, listar, sair, box; //variáveis para índice.
    int registro = 0, regAux = 0; //variáveis de registro.
    int totalVagas=NUM_VAGAS, dataDia, dataMes, dataAno; //variaveis para data e total de vagas.
    char loc[8], escolha[2] = "n"; //String para entrada em procura de uma placa específica.
    memset(&carro, 0, sizeof(carro)); //Limpa o lixo para exibição do vetor "carro".
    struct Vaga listagem[NUM_VAGAS];//define as exibições de entradas para o vetor "listagem".
    memset(&listagem, 0, sizeof(listagem)); //Limpa o lixo para exibição do vetor "listagem".

    carro[i].posicao == 0;


//------------------------------------------------------------------------------------------
    clrscr(); //Chama a função que limpa a tela.
    printf("--------- Controle de estacionamento para os hóspedes do hotel ou para os clientes do restaurante---------\n\n");
    printf("Digite a data de hoje:\n");
    printf("Dia \"DD\": ");
    scanf("%d", &dataDia);
    printf("\nMês corrente \"MM\": ");
    scanf("%d", &dataMes);
    printf("\nAno corrente \"AAAA\": ");
    scanf("%d", &dataAno);
    printf("\t %02d/%02d/%4d."
           "\n\n", dataDia, dataMes, dataAno);
    system("pause");//Espera que o usuário entre com um comando.
    /**< O laço do{}while() será responsável por retornar para as opções sempre depois que
    uma das opções, a não ser que seja digitado o número correspondente a finalização do programa.*/
    do
    {
        clrscr(); //Chama a função que limpa a tela.

        /**< Apresenta as opções. */
        printf("------------ Bem vindo ao Controle de Estacionamento. ------------\n\n"
               "\tSelecione uma Opção:\n\n"
               "\t1 - Entrada de Veículo.\n\n"
               "\t2 - Listagem de Veículos e Vagas.\n\n"
               "\t3 - Saída de Veículo.\n\n"
               "\t4 - Finalizar o programa.\n\n"
               "\tDISPONÍVEIS: %02d VAGA(S).\n"
               "\tOCUPADAS: %02d VAGA(S).\n\n", totalVagas, NUM_VAGAS-totalVagas);


        /**< Pede a entrada de um comando com base na lista acima, numeros de 1 a 5. */
        printf(" Digite o número escolhido: ");
        scanf("%d", &opcao); //Guarda a opção escolhida para ser lançada no "switch".

        /**< De acordo com a opção escolhida, chama o switch e faz a exibição conforme o
        "case" numerado. Não temos um case "default" pela falta de necessidade.*/
        switch(opcao)
        {
/**< -------------------------------------------------------------------------------------------- */
        case 1: //Responsavel pela entrada de dados no vetor "carro".
            limpaBuffer();
            for (i = 0; i < NUM_VAGAS; i++)  //laço que percorre o vetor "carro".
            {

                /**< se a variavel "posicao" dentro struct "temp" contida no vetor "carro"
                for igual a nulo (0) apresentam-se as opções para entrada de placa e horas. */
                if(carro[i].posicao == 0)
                {
                    registro++;//Incrementa o contador de registros a cada registro.
                    carro[i].regcar = registro;//Atribui o valor de registro incrementado ao "regcar" no struc.
                    clrscr(); //Chama a função que limpa a tela.
                    printf("A vaga ocupada Nº'%02d'.\n\n", i+1);//Exibe a vaga onde o veículo será guardado.
                    printf("Digite as letras do veículo no formato \"AAA\": ");
                    scanf("%s", &carro[i].placa);//Entrada da placa.
                    printf("Digite os numeros do veículo no formato \"1111\": ");
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
                    fprintf(arquivo, "\n\nCadastro realizado: Placa: %s%d | Entrada ás %02d:%02d horas\n", carro[i].placa, carro[i].placa_NUM, carro[i].h1, carro[i].m1);

                    fclose(arquivo);

                    /**< Seta a vaga como ocupada ao final do processo. O campo "posicao"
                    da struct é setado com "1" para que durante o processo de busca não
                    seja sobrescrito e possa exibir "Vaga LIVRE na opção 2 do switch. */
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
                               "\n\t|                    TICKET Nº%03d\t\t\t|"
                               "\n\t*********************"
                               "\n\t|                  CUPOM DE ENTRADA\t\t\t|"
                               "\n\t| ESTACIONAMENTO EXLUSIVO PARA HÓSPEDES"
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
                    break;//Quebra o laço "for" finalizando a ENTRADA com sucesso.
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
            clrscr(); //Chama a função que limpa a tela.
            limpaBuffer();
            printf("------------Listagem de Veículos e Vagas------------\n\n");

            for(listar = 0; listar < NUM_VAGAS; listar++) //Laço que irá percorrer o vetor.
            {
                printf("Vaga Nº %02d: ", listar+1);//Imprime na tela o número da vaga.

                /**< Se "posicao" for NULL, exibe "Vaga LiVRE". Senão, mostra a placa do carro
                que está lá. */
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
        case 3://Responsável pela saída de veículos.
            clrscr(); //Chama a função que limpa a tela.
            limpaBuffer();
            printf("------------------------ Saída de Veículo ------------------------\n");
            for(listar = 0; listar < NUM_VAGAS; listar++) //Laço que irá percorrer o vetor.
            {
                if(listar % 2 == 0)
                {
                    printf("\tVaga Nº %02d: ", listar+1);//Imprime na tela o número da vaga.

                    /**< Se "posicao" for NULL, exibe "Vaga LiVRE". Senão, mostra a placa do carro
                    que está lá. */
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
                    printf("Vaga Nº %02d: ", listar+1);//Imprime na tela o número da vaga.

                    /**< Se "posicao" for NULL, exibe "Vaga LiVRE". Senão, mostra a placa do carro
                    que está lá. */
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
            scanf("%s", &loc);//Joga o valor digitado na variável string "loc".
            printf ("\n\nDigite os numeros da placa: ");
            scanf("%d", &n);//Joga o valor digitado na variável string "loc".
            for(sair=0; sair<NUM_VAGAS; sair++)//Laço que irá percorrer o vetor.
            {
                int c = strlen(carro[sair].placa);
                /**< Se "loc" for igual a placa do veículo, inicia-se o processo de retirada
                do veículo. */
                if(strlen(loc) == c && n == carro[sair].placa_NUM)
                {
                    printf("Registro Nº%03d.\n", carro[sair].regcar);//imprime o número de registro único.
                    printf("Placa CONFIRMADA: %s %d.\n", carro[sair].placa, carro[sair].placa_NUM);//Confirma a placa.

                    /**< Condicional responsável por colocar a vaga em posição LIVRE. Se a
                    posição estiver setada como ocupada (1), coloque-a como vazia (0).*/
                    if(carro[sair].posicao == 1)
                    {

                        /**< Copia os dados da struct "Vaga" dentro do vetor "carro"
                        e os transfere para o struct "Vaga" dentro do vetor "listagem. */

                        listagem[regAux] = carro[sair];
                        carro[sair].posicao = 0;//Seta a vaga como vazia.
                        totalVagas++;// Controla a quantidade de vagas exibidas OCUPADAS.
                        regAux++;//Incrementa o auxiliar de registro a cada saída.
                        registro--;
                        break;//Quebra o laço "for" finalizando a RETIRADA com sucesso.
                    }

                }

            }
            system("pause");
            break;
/**< -------------------------------------------------------------------------------------------- */
        case 4:
            clrscr(); //Chama a função que limpa a tela.
            printf("\nO programa foi finalizado.\n\n");

/**< -------------------------------------------------------------------------------------------- */

        }
    }
    while(opcao != 4);


    return 0;
}
