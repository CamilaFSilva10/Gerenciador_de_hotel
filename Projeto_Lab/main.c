/*Gerenciador de estabelecimentos:

O gerenciador está apto para gerenciar: - somente hotel
                                        - somente restaurante
                                        - somente estacionamento

O projeto foi dividido entre os integrantes do grupos: Hotel -> Thiago || Restaurante -> Camila || Estacionamento -> Giovana e Raphael*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include "Menu.h"

int main()
{
    char nome[24]="\tOLÁ, SEJA BEM VINDO!!\n\n";
    int j;
    setlocale(LC_ALL, "Portuguese");
    system("color 70");

    printf("\n\n");
    for(j=0; nome[j]!= 24; j++){
        printf("%c", nome[j]); Sleep(100);

    }
    //Menu inicial para mostrar as opções de estabelecimentos
    MenuInicial();
}

/*Decidimos dividir o código em Headers e .c para facilitar o entendimento e deixar mais organizado

REFERENCIA DA ESTRUTURA UTILIZADA:
Video: https://www.youtube.com/watch?v=QWMmuZtcDIs&t=456s  */
