#ifndef ESTACIONAMENTOSL_H_INCLUDED
#define ESTACIONAMENTOSL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define MAXPLACA 8

#define NUM_VAGAS 20

void clrscr();
void limpaBuffer(void);
void entradadecarro();
void mostrarlista();
int menuP();
void saidadecarro();
int minutototal(int hora, int minuto);
int Estacionamento(char nomesR, int lugar, int mesas, int estac);

struct Vaga
{
    char placa[MAXPLACA];
    int h1, h2, m1, m2, T1, T2, totalT, posicao, regcar, placa_NUM;
    float valorT;
};

struct Vaga carro[NUM_VAGAS];
int opcao, i, listar, sair, numero, horas;
int registro = 0, regAux = 0;
int totalVagas=NUM_VAGAS, dataDia, dataMes, dataAno;
char loc[8], escolha[2] = "n", LETRAS[4];
struct Vaga listagem[NUM_VAGAS];


#endif // ESTACIONAMENTOSL_H_INCLUDED
