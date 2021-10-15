#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Restaurante();
void vagaR();
void Estacionamento();
void Hotel();
void MenuInicial();


typedef struct{
    char nome[30];
    int quantidade;
    int hora;
}cadastro;

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

void MenuInicial(){

    int tipo;

    printf("Bem vindo ao Gerenciador\n\n");
    printf("Instruções: \n -Para utilizar o gerenciador, por favor, escolha qual o tipo de estabelecimento.\n -Em seguida coloque as informações do local escolhido.\n -O gerenciador está apto para: || 1 - Restaurantes || 2 - Estacionamentos || 3 - Hotéis. ||  \n\n");

    printf("Digite o tipo de estabelecimento por meio do número representado acima: ");
    scanf("%d", &tipo);

    switch (tipo){
        case 1:
            printf("Qual o nome do seu restaurante? ");
            scanf("%s", &restaurante);
            printf("Quantos lugares disponíveis há em seu estabelecimento? ");
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
            printf("Opção não encontrada. Deseja voltar? ");
            MenuInicial();
            break;
    }

}

void Restaurante()
{
    int vaga, escolha;

    system("cls");
    printf("Bem vindo ao %s\n\n", restaurante);

    printf("O que você deseja fazer?\n");
    printf(" 0 - Reservar vaga; \n 1 - Cancelar vaga; \n 2 - Ver vagas disponíveis; \n");
    scanf("%d", &vaga);

    if (vaga == 1){
        printf("ok");
    }
    if(vaga == 2){
        printf("Ainda restam %d lugares disponíveis no restaurante\n\n", lugares);
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
        printf("Horário de entrada: ");
        scanf("%d", &reserva.hora);

        printf("\n\nReserva realizada:\n");
        printf("Nome do cliente: %s\n", reserva.nome);
        printf("Mesa para %d pessoas\n", reserva.quantidade);
        printf("Entrada ás %d horas\n", reserva.hora);
        printf("Quantidades de mesas para reserva: %d", aux);

        fprintf(file, "\n\nReserva realizada: Cliente: %s | Necessário %d mesa(s) para %d pessoas | Entrada ás %d horas\n", reserva.nome, aux, reserva.quantidade, reserva.hora);
        fclose(file);

        printf("\n\nPara voltar ao menu inicial do restaurante, pressione a tecla 9\nPara ver o relatório pressione a tecla 8\n");
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
}
