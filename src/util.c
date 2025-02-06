#include "city.h"
#include "card.h"
#include "util.h"

bool is_valid_functionality(int functionality)
{
    // Checa se o valor inserido pelo usuário representa uma das funcionalidades
    // apresentadas
    return functionality >= RegisterCards
            && functionality <= CompareAllProperties;
}
