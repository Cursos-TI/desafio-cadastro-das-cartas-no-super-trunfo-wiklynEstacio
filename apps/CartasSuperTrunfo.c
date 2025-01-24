#include "card.h"

// O jogo original possui 32 cartas
#define MAX_CITIES 32

int main()
{
    int chosen_functionality = choose_functionality();

    if (chosen_functionality == 1)
        register_cards(MAX_CITIES);
    else
        compare_cards();
    
    return 0;
}
