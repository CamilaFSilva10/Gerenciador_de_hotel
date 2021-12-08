#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Menu.h"

char t;
int lugares = 0, mesa = 0, aux = 0, ti;

void MenuInicial(){

    int tipo;

    printf("\n  Instru��es: \n   - Para utilizar o gerenciador, por favor, escolha qual o tipo de estabelecimento.\n"
           "   - Em seguida coloque as informa��es do local escolhido.\n"
           "   - O gerenciador est� apto para: || 1 - Restaurantes || 2 - Estacionamentos || 3 - Hot�is. ||  \n\n");

    printf("  Digite o tipo de estabelecimento por meio do n�mero representado acima: ");
    scanf(" %d", &tipo);

    switch (tipo){
        case 1://restaurante
            printf("  Qual o nome do seu restaurante? ");
            scanf("  %s", &restaurante);
            printf("  Quantos lugares dispon�veis h� em seu estabelecimento? ");
            scanf("  %d", &lugares);
            printf("  Uma mesa em seu estabelecimento comporta quantas pessoas? ");
            scanf("  %d", &mesa);
            iniciar(restaurante, lugares, mesa);
            break;
        case 2://estacionamento
            principalE();
            break;
        case 3://hotel
            principal();
            break;
        default:
            printf("Op��o n�o encontrada. Deseja voltar? ");
            MenuInicial();
            break;
    }

}
