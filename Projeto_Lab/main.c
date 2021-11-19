#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include "Menu.h"
#include "restaurante.h"

int main()
{
    char nome[24]="  OLÁ, SEJA BEM VINDO!!\n\n";
    int j, teste;
    setlocale(LC_ALL, "Portuguese");
    system("color 70");

    printf("\n\n");
    for(j=0; nome[j]!= 24; j++){
        printf("%c", nome[j]); Sleep(100);

    }

    MenuInicial();
}
