#include "city.h"

City* get_city_data()
{
    char provided_state;
    char provided_card_code[4];
    char provided_city_name[256];
    
    City *city = (City*) calloc(1, sizeof(City));
    
    if (city == NULL) {
        perror("Erro ao alocar memoria para a cidade em `get_city_data`\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite o estado: ");
    scanf(" %c", &provided_state);
    getchar();
    provided_state = toupper(provided_state);
    city->state = provided_state;

    printf("Digite o codigo da carta: ");
    scanf("%3s", provided_card_code);
    getchar();
    provided_card_code[0] = toupper(provided_card_code[0]);
    city->card_code = calloc(strlen(provided_card_code) + 1, sizeof(char));
    if (city->card_code == NULL) {
        perror("Erro ao alocar memoria para o codigo da carta");
        exit(EXIT_FAILURE);
    }
    strcpy(city->card_code, provided_card_code);

    printf("Digite o nome da cidade: ");
    scanf("%255s", provided_city_name);
    getchar();
    city->city_name = calloc(strlen(provided_city_name) + 1, sizeof(char));
    if (city->city_name == NULL) {
        perror("Erro ao alocar memória para o nome da cidade");
        exit(EXIT_FAILURE);
    }
    strcpy(city->city_name, provided_city_name);

    printf("Digite a populacao: ");
    scanf("%d", &city->population_size);
    getchar();

    printf("Digite a area: ");
    scanf("%f", &city->area);
    getchar();

    printf("Digite o PIB: ");
    scanf("%f", &city->gpd);
    getchar();
 
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &city->tourist_sites_count);
    getchar();

    return city;
}

void register_city(City* city, City** city_list, int registered_cities_count)
{
    if (city == NULL) {
        fprintf(stderr, "Erro: ponteiro NULL fornecido para `register_city`.\n");
        exit(EXIT_FAILURE);
    }

    city_list[registered_cities_count] = (City*) calloc(1, sizeof(City));
    
    if (city_list[registered_cities_count] == NULL) {
        perror("Erro ao alocar memoria para uma cidade em `register_city`.\n");
        exit(EXIT_FAILURE);
    }

    city_list[registered_cities_count]->state = city->state;

    city_list[registered_cities_count]->card_code = calloc(3, sizeof(char));
    strcpy(city_list[registered_cities_count]->card_code, city->card_code);

    city_list[registered_cities_count]->city_name = calloc(
        (strlen(city->city_name) + 1), sizeof(char)
    );
    if (city_list[registered_cities_count]->city_name == NULL) {
        perror("Erro ao alocar memoria para o nome da cidade em `register_city`.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(city_list[registered_cities_count]->city_name, city->city_name);

    city_list[registered_cities_count]->population_size = city->population_size;
    city_list[registered_cities_count]->area = city->area;

    if (city->area != 0) {
        city_list[registered_cities_count]->population_density = 
            (float)city->population_size / city->area;
    } else {
        city_list[registered_cities_count]->population_density = 0.0;
    }

    city_list[registered_cities_count]->gpd = city->gpd;

    if (city->population_size != 0) {
        city_list[registered_cities_count]->gpd_pc = 
            city->gpd / (float)city->population_size;
    } else {
        city_list[registered_cities_count]->gpd_pc = 0.0;
    }

    city_list[registered_cities_count]->tourist_sites_count = city->tourist_sites_count;
}

void print_city(const City *city)
{
    if (city == NULL) {
        fprintf(stderr, "Erro: ponteiro NULL fornecido para `print_city`.\n");
        exit(EXIT_FAILURE);
    }

    printf("Estado: %c\n", city->state);
    printf("Codigo da Carta: %s\n", city->card_code);
    printf("Nome da Cidade:: %s\n", city->city_name);
    printf("Populacao: %d\n", city->population_size);
    printf("Area: %.2f km²\n", city->area);
    printf("Densidade Populacional: %.2f pessoas/km²\n", city->population_density);
    printf("PIB: %.2f bilhoes de reais\n", city->gpd  / 1e9);
    printf("PIB per Capta: %.0f reais\n", city->gpd_pc);
    printf("Numero de Pontos Turisticos: %d\n", city->tourist_sites_count);
}

void free_city(City** city_ref)
{
    if (city_ref == NULL)
        return;

    if (*city_ref == NULL)
        return;

    City *city = *city_ref;
    free(city->card_code);
    free(city->city_name);
    free(city);
    *city_ref = NULL;
}

bool ask_to_keep_registering()
{
    char response;
    
    do {
        printf("\nRegistrar outra carta? (S/N): ");
        scanf(" %c", &response);
        getchar();
        puts("");
        response = toupper(response);

        if (response != 'S' && response != 'N') {
            puts("Entrada invalida. Por favor, digite 'S' para sim ou 'N' para nao.");
        }
    } while (response != 'S' && response != 'N');

    return response == 'S';
}

void free_city_list(City** city_list, int registered_cities_count)
{
    for (int i = 0; i < registered_cities_count; i++) {
        if (city_list[i] != NULL)
            free_city(&city_list[i]);
    }
}
