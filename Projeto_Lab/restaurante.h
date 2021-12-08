#ifndef RESTAURANTE_H_INCLUDED
#define RESTAURANTE_H_INCLUDED

struct no
{
    struct no *ant;
    char nome[20];
    int hora;
    int quantidade;
    int dado;
    struct no *prox;
};

typedef struct
{
    struct no *inicio;
    struct no *fim;
} listacircularde;

void cria(listacircularde *q);
int  insere(listacircularde *q, char n[30], int h, int quant);
void mostra(listacircularde *q, int sentido);
int  estaVazia(listacircularde q);
int  retira(listacircularde *q, int n);
void Restaurante(char nomeR[30], int lugar, int mesas);
void iniciar(char nomeR[30], int lugar, int mesas);

struct no reserva;
char nomeR[30];
int lugar, mesas, estac;
#endif // RESTAURANTE_H_INCLUDED
