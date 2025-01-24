#include "city.h"

int choose_functionality()
{
    int chosen_functionality = 0;

    puts("O programa possui duas funcionalidades principais:\n");
    puts("1. Se refere ao registro de cartas. Voce pode registrar e ver os dados registrados para cada carta.");
    puts("2. Se refere ao registro e comparacao de duas cartas. Voce pode registrar duas cartas e ver a comparacao entre os dados registrados para cada propriedade de cada carta.");
    printf("\nEscolha o numero da opcao que deseja executar: ");  

    do
    {
        // Tenta ler a entrada
        if (scanf("%d", &chosen_functionality) != 1)
        {
            // Se a entrada for inválida: limpa o buffer de entrada
            while (getchar() != '\n');
            printf("Opcao invalida. Por favor, insira 1 ou 2: ");
        }
        // Se a entrada for válida, checa se é um dos valores possíveis
        else if (chosen_functionality != 1 && chosen_functionality != 2)
            printf("Opcao invalida. Por favor, insira 1 ou 2: ");

    } while (chosen_functionality != 1 && chosen_functionality != 2);

    puts("");
    return chosen_functionality;
}
