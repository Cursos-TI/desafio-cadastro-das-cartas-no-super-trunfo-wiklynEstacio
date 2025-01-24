#include "city.h"

City* get_city_data()
{
    // Declara variáveis auxiliares
    char provided_state;
    char provided_card_code[4];
    char provided_city_name[256];
    
    // Aloca memória para uma estrutura `City`
    City *city = alocate_city();

    // Coleta os dados da cidade
    // Usa as propriedades auxiliares em `state`, `card_code` e `city_name`
    // Transforma para maísculas as primerias letras dessas três propriedades
    // Aloca espaço na memória para os arrays de caracteres
    // Copia os valores inseridos para as propriedades da estrutura `City`
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
    fgets(provided_city_name, sizeof(provided_city_name), stdin);
    provided_city_name[strcspn(provided_city_name, "\n")] = '\0';
    provided_city_name[0] = toupper(provided_city_name[0]);
    city->city_name = calloc(strlen(provided_city_name) + 1, sizeof(char));
    if (city->city_name == NULL) {
        perror("Erro ao alocar memória para o nome da cidade");
        exit(EXIT_FAILURE);
    }
    strcpy(city->city_name, provided_city_name);

    printf("Digite a populacao: ");
    scanf("%ld", &city->population_size);
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
