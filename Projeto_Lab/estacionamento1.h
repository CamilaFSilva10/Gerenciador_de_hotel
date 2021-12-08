#ifndef ESTACIONAMENTO1_H_INCLUDED
#define ESTACIONAMENTO1_H_INCLUDED

#define MAXPLACA 8

#define NUM_VAGAS 20

/**<struct responsavel por setar os conteudos de cada vetor em separado. pode ser alterado
    com adições de campos futuramente.*/
struct Vaga
{
    char placa[MAXPLACA];
    int h1, h2, m1, m2, T1, T2, totalT, posicao, regcar, placa_NUM;
    float valorT;
};

void clrscr();
void limpaBuffer(void);
int minutototal(int hora, int minuto);
int principalE();

#endif // ESTACIONAMENTO1_H_INCLUDED
