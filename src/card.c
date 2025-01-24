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

void register_cards(int max_cities)
{
    if (max_cities <= 0)
    {
        fprintf(stderr, "Erro: valor de `max_cites` precisa ser positivo.\n");
        exit(EXIT_FAILURE);
    }

    // Cria uma lista de ponteiros nulos, onde serão apontadas as cartas
    City* city_list[max_cities];
    for (int i = 0; i < max_cities; i++) {
        city_list[i] = NULL;
    }
    
    // Adiciona variáveis de apoio
    int registered_cities_count = 0;
    char keep_registering = 'S';
    
    // Mantém interação com usuário até o número máximo de cartas ser registrado
    // ou até o usuário responder que não quer mais registrar nenhuma carta.
    while (registered_cities_count < max_cities && keep_registering == 'S')
    {
        // Cria um ponteiro para ter acesso aos dados enviados pelo usuário
        City* city = get_city_data();

        city_list[registered_cities_count] = (City*) calloc(1, sizeof(City));

        // Usa um dos ponteiros da lista de cidades para apontar para os dados
        // enviados pelo usuário
        register_city(city, city_list[registered_cities_count]);

        puts("\nCarta cadastrada com sucesso.\n");

        // Exibe os dados enviados pelo usuário
        print_city(city_list[registered_cities_count]);

        registered_cities_count++;

        // Libera o ponteiro `city`
        free_city(&city);

        // Pergunta ao usuário se deve continuar a registrar cartas
        if (registered_cities_count < max_cities)
        {
            if (ask_to_keep_registering())
            {
                keep_registering = 'S';
                puts("");
            }
            else
                keep_registering = 'N';
        } else
            puts("\nNumero maximo de cartas atingido.");
    }

    // Libera o espaço na memória alocado para as cidades
    free_city_list(city_list, registered_cities_count);
}
