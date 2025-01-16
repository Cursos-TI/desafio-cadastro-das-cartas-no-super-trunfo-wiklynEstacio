#include "city.h"

// O jogo original possui 32 cartas
#define MAX_CITIES 32

int main()
{
    // Cria uma lista de ponteiros nulos, onde serão apontadas as cartas
    City* city_list[MAX_CITIES] = {NULL};
    
    // Adiciona variáveis de apoio
    int registered_cities_count = 0;
    char keep_registering = 'S';
    
    // Mantém interação com usuário até o número máximo de cartas ser registrado
    // ou até o usuário responder que não quer mais registrar nenhuma carta.
    while (registered_cities_count < MAX_CITIES && keep_registering == 'S')
    {
        // Cria um ponteiro para ter acesso aos dados enviados pelo usuário
        City* city = get_city_data();

        // Usa um dos ponteiros da lista de cidades para apontar para os dados
        // enviados pelo usuário
        register_city(city, city_list, registered_cities_count);

        puts("\nCarta cadastrada com sucesso.\n");

        // Exibe os dados enviados pelo usuário
        print_city(city_list[registered_cities_count]);

        registered_cities_count++;

        // Libera o ponteiro `city`
        free_city(&city);

        // Pergunta ao usuário se deve continuar a registrar cartas
        if (registered_cities_count < MAX_CITIES) {
            if (ask_to_keep_registering())
            {
                keep_registering = 'S';
                puts("");
            }
            else
            {
                keep_registering = 'N';
            }
        } else {
            puts("\nNumero maximo de cartas atingido.");
        }
    }

    // Libera o espaço na memória alocado para as cidades
    free_city_list(city_list, registered_cities_count);
    
    return 0;
}
