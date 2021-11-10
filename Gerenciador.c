#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no
{
    struct no *ant;
    char nome[30];
    int quantidade;
    int hora;
    int quarto;
    struct no *prox;
};

typedef struct
{
    struct no *inicio;
    struct no *fim;
} cadastro;

void Restaurante();
void Estacionamento();
void Hotel();
void MenuInicial();
void cria(cadastro *q);

char restaurante[20], hotel[20], estacionamento[20];
int lugares = 0, mesa = 0, aux = 0;
cadastro reserva;
FILE *file;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    system("color 80");

    file = fopen("arquivo.txt", "r+");

    MenuInicial();

}

void cria(cadastro *q)
{
    q->inicio = NULL;
    q->fim = NULL;
}

void MenuInicial(){

    int tipo;

    printf("Bem vindo ao Gerenciador\n\n");
    printf("Instru��es: \n -Para utilizar o gerenciador, por favor, escolha qual o tipo de estabelecimento.\n -Em seguida coloque as informa��es do local escolhido.\n -O gerenciador est� apto para: || 1 - Restaurantes || 2 - Estacionamentos || 3 - Hot�is. ||  \n\n");

    printf("Digite o tipo de estabelecimento por meio do n�mero representado acima: ");
    scanf("%d", &tipo);

    switch (tipo){
        case 1:
            printf("Qual o nome do seu restaurante? ");
            scanf("%s", &restaurante);
            printf("Quantos lugares dispon�veis h� em seu estabelecimento? ");
            scanf("%d", &lugares);
            printf("Uma mesa em seu estabelecimento comporta quantas pessoas? ");
            scanf("%d", &mesa);
            Restaurante();
            break;
        case 2:
            printf("Qual o nome do seu estacionamento? ");
            scanf("%s", &estacionamento);
            Estacionamento();
            break;
        case 3:
            printf("Qual o nome do seu hotel? ");
            scanf("%s", &hotel);
            Hotel();
            break;
        default:
            printf("Op��o n�o encontrada. Deseja voltar? ");
            MenuInicial();
            break;
    }

}

void Restaurante()
{
    int vaga, escolha;

    system("cls");
    printf("Bem vindo ao %s\n\n", restaurante);

    printf("O que voc� deseja fazer?\n");
    printf(" 0 - Reservar vaga; \n 1 - Cancelar vaga; \n 2 - Ver vagas dispon�veis; \n");
    scanf("%d", &vaga);

    if (vaga == 1){
        printf("ok");
    }
    if(vaga == 2){
        printf("Ainda restam %d lugares dispon�veis no restaurante\n\n", lugares);
        system("pause");
        Restaurante();
    }
    else{
        printf("Para fazer a reserva, me informe os seguintes dados:\n");
        printf("Nome do cliente: ");
        scanf("%s", &reserva.nome);
        printf("Quantidade de pessoas para a mesa: ");
        scanf("%d", &reserva.quantidade);
        if(reserva.quantidade > mesa){
            aux = reserva.quantidade / mesa;
            lugares = lugares - aux;
        }else{
            aux = 1;
            lugares--;
        }
        printf("Hor�rio de entrada: ");
        scanf("%d", &reserva.hora);

        printf("\n\nReserva realizada:\n");
        printf("Nome do cliente: %s\n", reserva.nome);
        printf("Mesa para %d pessoas\n", reserva.quantidade);
        printf("Entrada �s %d horas\n", reserva.hora);
        printf("Quantidades de mesas para reserva: %d", aux);

        fprintf(file, "\n\nReserva realizada: Cliente: %s | Necess�rio %d mesa(s) para %d pessoas | Entrada �s %d horas\n", reserva.nome, aux, reserva.quantidade, reserva.hora);
        fclose(file);

        printf("\n\nPara voltar ao menu inicial do restaurante, pressione a tecla 9\nPara ver o relat�rio pressione a tecla 8\n");
        scanf("%d", &escolha);

        if(escolha == 9){
            Restaurante();
        }
    }
}

void Estacionamento()
{
    system("cls");
    printf("Bem vindo ao %s\n\n", estacionamento);
}

void Hotel()
{
    system("cls");
    printf("Bem vindo ao %s\n\n", hotel);

    printf("O que você deseja fazer?\n");
    printf(" 1 - Reservar quarto; \n 2 - Cancelar quarto; \n 3 - Ver quartos disponíveis; \n");
    scanf("%d", );
}