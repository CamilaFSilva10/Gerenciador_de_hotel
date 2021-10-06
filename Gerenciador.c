#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Restaurante();
void Estacionamento();
void Hotel();
void MenuInicial();


int main()
{
    setlocale(LC_ALL, "Portuguese");
    system("color 80");

    MenuInicial();

}

void MenuInicial(){

    int tipo, sn;

    printf("Bem vindo ao Gerenciador\n\n");
    printf("Instru��es: \n -Para utilizar o gerenciador, por favor, escolha qual o tipo de estabelecimento.\n -Em seguida coloque as informa��es do local escolhido.\n -O gerenciador est� apto para: || 1 - Restaurantes || 2 - Estacionamentos || 3 - Hot�is. ||  \n\n");

    printf("Digite o tipo de estabelecimento por meio do n�mero representado acima: ");
    scanf("%d", &tipo);

    if(tipo == 1)
        Restaurante();
    if (tipo == 2)
        Estacionamento();
    if (tipo == 3)
        Hotel();
    else{
        printf("Op��o n�o encontrada. Deseja voltar?");
        scanf("%d", &sn);
        if (sn == 4){
            MenuInicial();
        }
    }
}

void Restaurante()
{
    char restaurante[20];

    printf("Qual o nome do seu restaurante?");
    scanf("%s", &restaurante);

    printf("%s", restaurante);

}

void Estacionamento()
{
    printf("Qual o nome do seu estacionamento?");

}

void Hotel()
{
    printf("Qual o nome do seu hotel?");

}
