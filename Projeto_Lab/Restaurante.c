#include "restaurante.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//inclusão do arquivo
FILE *file;
listacircularde lista;

//iniciar a lista e o código do restaurante
void iniciar(char nomeR[30], int lugar, int mesas){
    cria(&lista);
    Restaurante(nomeR, lugar, mesas);
}

void Restaurante(char nomeR[30], int lugar, int mesas)
{

    int vaga, auxi = 0, i = 0;
    char fim[24]=" Expediente finalizado!";
    char nome[15], consulta[10];

    file = fopen("project_lab.txt", "r+");
    if(file == NULL){
        printf("\nArquivo nao existe e sera criado agora como relatório...\n\n");
        file = fopen("project_lab.txt", "r+");
    }

    system("cls");

    printf("  Bem vindo ao %s\n\n", nomeR);

    printf("  O que você deseja fazer? ");

    //Menu do restaurante sem estacionamento
    printf("\n 1 - Reservar vaga; \n 2 - Cancelar vaga; \n 3 - Ver vagas disponíveis;"
            "\n 4 - Mostrar os clientes; \n 0 - Finalizar expediente; \n");
    scanf("%d", &vaga);

    switch (vaga){
        case 1:
            //reservar vaga
            if(lugar <= 0){
                    printf("      ____________________");
                    printf("\n\n  |  Vagas esgotadas! |\n\n");
                    printf("      ____________________");

                    system("pause");

                    Restaurante(nomeR, lugar, mesas);
            }
            else
            {
                printf(" Para fazer a reserva, me informe os seguintes dados:\n");
                printf(" Nome do cliente: ");
                scanf("%s", &reserva.nome);//gets não funcionou
                strupr(reserva.nome);
                printf(" Quantidade de pessoas para a mesa: ");
                scanf("%d", &reserva.quantidade);
                printf(" Horário de entrada: ");
                scanf("%d", &reserva.hora);
                if(reserva.hora < 0 && reserva.hora > 23){
                    printf("Horario invalido");
                    Restaurante(nomeR, lugar, mesas);
                }
                //contar quantas mesas são necessarias levando em conta a quantidade de pessoas e as mesas disponiveis no restaurante
                if(reserva.quantidade > mesas){
                    auxi = reserva.quantidade / mesas;
                    //diminui as mesas reservadas do total
                    lugar = lugar - auxi;
                }else{
                    auxi = 1;
                    lugar--;
                }

                if(!insere(&lista, reserva.nome, reserva.hora, reserva.quantidade)){
                    printf("\n\n(Não foi)\n\n");//AVISO
                }
                else{
                    printf(" \n\n Reserva realizada:\n");
                    printf(" Nome do cliente: %s\n", reserva.nome);
                    printf(" Mesa para %d pessoas\n", reserva.quantidade);
                    printf(" Entrada ás %d horas\n", reserva.hora);
                    printf(" Quantidades de mesas para reserva: %d", auxi);

                    //guarda no arquivo/relatório
                    printf("\n\nGravando o registro no arquivo...\n\n");
                    fseek(file, 0*sizeof(struct no), SEEK_END);
                    fwrite(&reserva, sizeof(struct no), 1, file);
                    //fprintf(file, "\n\nReserva realizada: Cliente: %s | Necessário %d mesa(s) para %d pessoas | Entrada ás %d horas\n", reserva.nome, auxi, reserva.quantidade, reserva.hora);

                    fclose(file);
                }

                system("pause");
                Restaurante(nomeR, lugar, mesas);
            }
            break;

        case 2:
            //cancelamento de vaga por meio do nome
            printf(" Qual o nome do cliente que deseja cancelar a vaga? ");
            scanf("%s", &nome);
            strupr(nome);
            int n = strlen(nome);
            //função retira recebe o endereço da lista e o strlen do nome que deseja ser removido
            retira(&lista,n);
            mostra(&lista,0);
            system("pause");
            Restaurante(nomeR, lugar, mesas);
            break;

        case 3:
            //se acabar os lugares/mesas disponiveis (lugar = 0), esgotou as vagas
            if(lugar <= 0){
                printf("Vagas esgotadas!");
            }
            printf("Restam %d vagas", lugar);
            system("pause");
            Restaurante(nomeR, lugar, mesas);
            break;

        case 4:

            mostra(&lista,0);
            printf("\n\n");

            printf("Digite o nome do cliente = ");
            scanf("%s", &consulta);

            strupr(consulta);

            rewind(file);

            while (!feof(file))
            {
                //printf("Entrou"); AVISO
                fread(&reserva,sizeof(struct no),1,file);

                if (!feof(file) && consulta == reserva.nome)
                {
                    printf("Nome=%s | Hora=%d | Quantidade=%d\n\n",
                           reserva.nome, reserva.hora, reserva.quantidade);
                    break;
                }
            }

            if (feof(file))
            {
                printf("Nome não encontrado...\n\n");
            }

            system("pause");
            Restaurante(nomeR, lugar, mesas);
            break;

        case 0:
            //finalizar expediente
            system("cls");
            for(i = 0; i < 24; i++){
                printf("%c", fim[i]);
                Sleep(100);
            }
            printf("\n Só um momento!\n AVISO: Um arquivo contendo todo relatório de utilização do gerenciador está disponivel"
                   " com o nome de  project_lab.txt. \n Finalizando o gerenciador...");
            break;

        default:
            printf("Opção não encontrada");
            system("pause");
            Restaurante(nomeR, lugar, mesas);
            break;
    }
}

//cria a lista
void cria(listacircularde *q)
{
    q->inicio = NULL;
    q->fim = NULL;
}

//insere as reservas na lista
int  insere(listacircularde *q, char n[30], int h, int quant)
{
    struct no *aux;

    aux = (struct no*) malloc(sizeof(struct no));

    if (aux == NULL){
        return 0;
    }
    if (q->inicio == NULL)
    {
        strcpy(aux->nome, n);
        aux->hora = h;
        aux->quantidade = quant;
        q->inicio = aux;
        q->fim = aux;
        aux->prox = q->inicio;
        aux->ant = q->fim;
        return 1;
    }

    strcpy(aux->nome, n);
    aux->hora = h;
    aux->quantidade = quant;
    aux->ant = q->fim;
    q->fim->prox = aux;
    aux->prox = q->inicio;
    q->inicio->ant = aux;
    q->fim = aux;
    return 1;
}

//mostra quem está na lista
void mostra(listacircularde *q, int sentido)
{
    struct no *aux;

    if (q->inicio == NULL){
        printf("Lista vazia...\n\n");//AVISO
    }
    else
    {
        if (sentido == 0) //ordem de cadastramento
        {
            aux = q->inicio;
            do
            {
                printf("\n%s", aux->nome);
                aux = aux->prox;
            } while (aux != q->inicio);
            return;
        }
        else
        {
            aux = q->fim;
            do
            {
                printf("%s", reserva.nome);
                aux = aux->ant;
            } while (aux != q->fim);
        }
    }
}

int  estaVazia(listacircularde q)
{
    if (q.inicio == NULL)
        return 1;
    return 0;
}

int  retira(listacircularde *q, int n)
{
    struct no *aux, *anterior, *atual;

    if (q->inicio == NULL){
        return 0;
    }
    // remover o primeiro nó de uma lista unitária
    if (q->inicio == q->fim && n == strlen(q->inicio->nome))
    {
        printf("\n\nRemovendo o primeiro\n\n");//AVISO
        aux = q->inicio;
        q->inicio = NULL;
        q->fim = NULL;
        free(aux);
        return 1;
    }

    // remover o primeiro de uma lista não unitária
    if (q->inicio != q->fim && n == strlen(q->inicio->nome))
    {
        printf("\n\nRemovendo o primeiro de uma lista não unitária\n\n");//AVISO
        aux = q->inicio;
        q->inicio = q->inicio->prox;
        q->inicio->ant = q->fim;
        q->fim->prox = q->inicio;
        free(aux);
        return 1;
    }

    // remover o último nó da lista
    if (n == strlen(q->fim->nome))
    {
        printf("\n\nRemovendo o ultimo\n\n");//AVISO
        aux = q->fim;
        q->fim = q->fim->ant;
        q->fim->prox = q->inicio;
        q->inicio->ant = q->fim;
        free(aux);
        return 1;
    }

    // remover um nó no meio da lista
    printf("Processando o no com o nome = %s\n", q->inicio->nome);
    anterior = q->inicio;
    atual = q->inicio->prox;
    while (strlen(atual->nome) != n && atual != q->inicio)
    {
        printf("Processando o no com o nome = %s\n", atual->nome);
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == q->inicio)
    {
        printf("\nDado %s nao existe na lista...\n", atual->nome);
        return 0;
    }
    else
    {
        printf("Dado %s encontrado e sera removido...\n", atual->nome);
        aux = atual;
        anterior->prox = atual->prox;
        atual->prox->ant = anterior;
        free(aux);
        return 1;
    }
}

/*REFERENCIA:
O código foi feito baseado nos códigos exemplos da teoria de AED*/
