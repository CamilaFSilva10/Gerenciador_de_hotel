#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

#define TAM 20
// ESTRUTURA CADASTRO
typedef struct cad
{
  char nome[25], sobrenome[50];
  int idade, CPF, RG, dias, NQuartos, QPessoas;
} Cadastro;

// VETOR~/BANCO DE DADOS CLIENTE 1
Cadastro Cli[TAM];
int cliente = 0;
int Ncli = 0;

void principal();
void cadastro();
void Dados();
void Editar();
void Excluir();
int menu();

#endif // HOTEL_H_INCLUDED
