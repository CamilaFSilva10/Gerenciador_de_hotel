#include "restaurante.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;

void Restaurante(char nomeR[30], int lugar, int mesas)
{
    file = fopen("lab.txt", "r+");

    listacircularde lista;
    int vaga, escolha, aux = 0, i = 0;
    char fim[35]=" Expediente finalizado!";
    char nome[15];

    cria(&lista);

    system("cls");

    printf("  Bem vindo ao %s\n\n", nomeR);

    printf("  O que você deseja fazer?\n");
    printf("\n 0 - Reservar vaga; \n 1 - Cancelar vaga; \n 2 - Ver vagas disponíveis; \n 3 - Finalizar expediente \n");
    scanf(" %d", &vaga);
    //scanf(" Operação:   %d", &vaga);

    if(vaga == 0){

        printf(" Para fazer a reserva, me informe os seguintes dados:\n");
        printf(" Nome do cliente: ");
        scanf(" %s", reserva.nome);
        printf(" Quantidade de pessoas para a mesa: ");
        scanf(" %d", &reserva.quantidade);
        if(reserva.quantidade > mesas){
            aux = reserva.quantidade / mesas;
            lugar = lugar - aux;
        }else{
            aux = 1;
            lugar--;
        }
        printf(" Horário de entrada: ");
        scanf(" %d", &reserva.hora);


        insere(&lista, reserva.nome, reserva.hora, reserva.quantidade);

        if(!insere(&lista, reserva.nome, reserva.hora, reserva.quantidade)){
            printf("Não foi");
        }else{
            printf(" \n\nReserva realizada:\n");
            printf(" Nome do cliente: %s\n", reserva.nome);
            printf(" Mesa para %d pessoas\n", reserva.quantidade);
            printf(" Entrada ás %d horas\n", reserva.hora);
            printf(" Quantidades de mesas para reserva: %d", aux);

            fprintf(file, "\n\nReserva realizada: Cliente: %s | Necessário %d mesa(s) para %d pessoas | Entrada ás %d horas\n", reserva.nome, aux, reserva.quantidade, reserva.hora);
            fclose(file);
        }

        printf("\n\n Para voltar ao menu inicial do restaurante, pressione a tecla 9\n Para ver o relatório pressione a tecla 8\n");
        scanf("%d", &escolha);

        if(escolha == 9){
            Restaurante(nomeR, lugar, mesas);
        }
        if (escolha == 8)
        {
            mostra(lista,0);
            printf("\n\n");
            system("pause");
            Restaurante(nomeR, lugar, mesas);
        }
        else
            printf("Lista vazia...\n\n");
    }
    if(vaga == 1){
        printf("Qual o nome do cliente que deseja cancelar a vaga? ");
        gets(nome);
        retira(&lista,nome);
        mostra(lista,0);
        system("pause");
        Restaurante(nomeR, lugar, mesas);
    }
    if(vaga == 3){
        system("cls");
        for(i = 0; fim[i] != "\0"; i++){
            printf("%c", fim[i]); Sleep(100);

        }
    }
}

void cria(listacircularde *q)
{
    q->inicio = NULL;
    q->fim = NULL;
}

int  insere(listacircularde *q, char n[30], int h, int quant)
{
    struct no *aux;

    aux = (struct no*) malloc(sizeof(struct no));
    if (aux == NULL)
        return 0;
    if (q->inicio == NULL)
    {
        aux->nome[15] = n[15];
        aux->hora = h;
        aux->quantidade = quant;
        q->inicio = aux;
        q->fim = aux;
        aux->prox = q->inicio;
        aux->ant = q->fim;
        return 1;
    }

    aux->nome[15] = n[15];
    aux->hora = h;
    aux->quantidade = quant;
    aux->ant = q->fim;
    q->fim->prox = aux;
    aux->prox = q->inicio;
    q->inicio->ant = aux;
    q->fim = aux;
    return 1;
}

void mostra(listacircularde q, int sentido)
{
    struct no *aux;

    if (q.inicio == NULL){
        printf("Lista vazia...\n\n");
        printf("Não tem nada");
    }
    else
    {
        if (sentido == 0)
        {
            aux = q.inicio;
            do
            {
                printf("\n%s", reserva.nome);
                printf("\n%s", aux->nome);
                aux = aux->prox;
            } while (aux != q.inicio);
            return;
        }
        else
        {
            aux = q.fim;
            do
            {
                printf("%s", aux->nome);
                aux = aux->ant;
            } while (aux != q.fim);
        }
    }
}

int  estaVazia(listacircularde q)
{
    if (q.inicio == NULL)
        return 1;
    return 0;
}

int  retira(listacircularde *q, char d[15])
{
    struct no *aux, *anterior, *atual;

    if (q->inicio == NULL){
        printf("q->inicio = null\n\n");
        return 0;
    }
    // remover o primeiro nó de uma lista unitária
    if (q->inicio == q->fim && d == q->inicio->nome)
    {
        printf("Removendo o primeiro");
        aux = q->inicio;
        q->inicio = NULL;
        q->fim = NULL;
        free(aux);
        return 1;
    }

    // remover o primeiro de uma lista não unitária
    if (q->inicio != q->fim && d == q->inicio->nome)
    {
        printf("Removendo o primeiro");
        aux = q->inicio;
        q->inicio = q->inicio->prox;
        q->inicio->ant = q->fim;
        q->fim->prox = q->inicio;
        free(aux);
        return 1;
    }

    // remover o último nó da lista
    if (strlen(q->fim->nome) == strlen(d))//FAZER TESTE COM STRLEN, STRINGS
    {
        printf("Removendo o ultimo");
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
    while (atual->nome != d && atual != q->inicio)
    {
        printf("Processando o no com o nome = %s\n", atual->nome);
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == q->inicio)
    {
        printf("\nDado %s nao existe na lista...\n", d);
        return 0;
    }
    else
    {
        printf("Dado %s encontrado e sera removido...\n",atual->nome);
        aux = atual;
        anterior->prox = atual->prox;
        atual->prox->ant = anterior;
        free(aux);
        return 1;
    }
}

