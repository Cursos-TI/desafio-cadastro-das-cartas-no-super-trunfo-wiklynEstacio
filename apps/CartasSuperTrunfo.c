#include "card.h"

// O jogo original possui 32 cartas
#define MAX_CITIES 32

int main()
{
    // Exibe e explica as funcionalidades implementadas
    show_functionalities_menu();
    
    // Armazena a funcionalidade escolhida pelo usuário
    int chosen_functionality = choose_functionality();

    // Redireciona o fluxo de acordo com a funcionalidade escolhida
    switch (chosen_functionality)
    {
        case RegisterCards:
            register_cards(MAX_CITIES);
            break;
        
        case CompareAllProperties:
            compare_cards();
            break;

        // Não foi necessária a implementação do caso `default` pois há
        // validacão e verificação da entrada do usuário. O programa ficará em
        // loop até que o usuário insira um valor válido
        default:
            break;
    }
    
    return 0;
}
