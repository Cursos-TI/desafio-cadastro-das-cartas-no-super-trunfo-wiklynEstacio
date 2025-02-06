#include "city.h"
#include "interface.h"

City* alocate_city()
{
    // Aloca espaço, na memória heap, para uma estrutura `City`
    City *city = (City*) calloc(1, sizeof(City));
    
    // Checa se a memória foi alocada corretamente
    if (city == NULL) {
        perror("Erro ao alocar memoria para a cidade em `get_city_data`\n");
        exit(EXIT_FAILURE);
    }

    return city;
}

void register_city(City* city, City* city_in_list)
{
    // Checa se a memória para a estrutura `City` foi alocada corretamente
    if (city == NULL) {
        fprintf(stderr, "Erro: ponteiro NULL `city` fornecido para `register_city`.\n");
        exit(EXIT_FAILURE);
    }
    
    if (city_in_list == NULL) {
        perror("Erro: ponteiro NULL `city_in_list` fornecido para `register_city`.\n");
        exit(EXIT_FAILURE);
    }

    // Copia os dados fornecidos pelo usuário para a estrutura `City` alocada
    // no array de cidades
    // Aloca memória para os arrays de caracteres (`card_code` e `city_name`)
    city_in_list->state = city->state;

    city_in_list->card_code = calloc(3, sizeof(char));
    strcpy(city_in_list->card_code, city->card_code);

    city_in_list->city_name = calloc(
        (strlen(city->city_name) + 1), sizeof(char)
    );
    if (city_in_list->city_name == NULL) {
        perror("Erro ao alocar memoria para o nome da cidade em `register_city`.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(city_in_list->city_name, city->city_name);

    city_in_list->population_size = city->population_size;
    city_in_list->area = city->area;

    // Verifica se os valores numéricos que serão usados como denominador no
    // cálculo das propriedades extras não é zero.
    if (city->area != 0)
    {
        city_in_list->population_density = 
            (float)city->population_size / city->area;
    }
    // Caso sejam zero, não faz o cálculo e atribui o valor 0.0 à propriedade
    else
    {
        city_in_list->population_density = 0.0;
    }

    city_in_list->gpd = city->gpd;

    if (city->population_size != 0)
    {
        city_in_list->gpd_pc = city->gpd / (float)city->population_size;
    } else
    {
        city_in_list->gpd_pc = 0.0;
    }

    city_in_list->tourist_sites_count = city->tourist_sites_count;

    // Calcula o valor do Super Poder, fazendo a conversão dos valores inteiros
    // para float
    city_in_list->super_power =
        (float)city_in_list->population_size
        + city_in_list->area
        + (float)1/city_in_list->population_density
        + city_in_list->gpd
        + city_in_list->gpd_pc
        + (float)city_in_list->tourist_sites_count;
}

void free_city(City** city_ref)
{
    // Verifica se o ponteiro para o ponteiro da cidade é NULL.
    // Se for, não há nada para liberar, então a função retorna.
    if (city_ref == NULL)
        return;

    // Verifica se o ponteiro para a cidade é NULL.
    // Se for, a cidade já foi liberada ou nunca foi alocada.
    if (*city_ref == NULL)
        return;

    // Armazena o ponteiro da cidade em uma variável local para facilitar o
    // acesso.
    City *city = *city_ref;

    // Libera a memória alocada para `card_code` e `city_name`
    free(city->card_code);
    free(city->city_name);

    // Libera a memória alocada para a estrutura `City`.
    free(city);

    // Define o ponteiro original para NULL para evitar referências pendentes.
    *city_ref = NULL;
}

void free_city_list(City** city_list, int registered_cities_count)
{
    // Itera sobre cada item da lista de cidades para liberar o espaço alocado
    // pelos ponteiros, caso não sejam nulos. Se forem nulos, nada acontece.
    for (int i = 0; i < registered_cities_count; i++) {
        if (city_list[i] != NULL)
            free_city(&city_list[i]);
    }
}

void alocate_cities_to_compare(City* city_list[2])
{
    // Aloca um array com dois ponteiros nulos
    for (int i = 0; i < 2; i++) {
        city_list[i] = NULL;
    }

    // Aponta os ponteiros nulos para estruturas `City` 
    city_list[0] = alocate_city();
    city_list[1] = alocate_city();

    // Coleta os dados para as estruturas `City`. Também copia os dados
    // fornecidos para a lista de cidades e calcula valores extras através
    // desses dados
    City *first_city = get_one_city_data("primeira");
    register_city(first_city, city_list[0]);

    puts("\nCarta registrada com sucesso.\n");

    City *second_city = get_one_city_data("segunda");
    register_city(second_city, city_list[1]);

    puts("\nCarta registrada com sucesso.");

    // Exibe os dados coletados e calculados no terminal
    print_card_to_compare(city_list[0], 1);
    print_card_to_compare(city_list[1], 2);
}
