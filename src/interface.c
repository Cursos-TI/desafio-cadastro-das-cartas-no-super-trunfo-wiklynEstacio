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

City* get_one_city_data(char* card_number)
{
    // Esta função é quase idêntica à função `get_city_data()`. A única
    // diferença são as mensagens que aparecem pedindo a inserção dos dados.

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
    printf("Digite o estado da %s carta: ", card_number);
    scanf(" %c", &provided_state);
    getchar();
    provided_state = toupper(provided_state);
    city->state = provided_state;

    printf("Digite o codigo da %s carta: ", card_number);
    scanf("%3s", provided_card_code);
    getchar();
    provided_card_code[0] = toupper(provided_card_code[0]);
    city->card_code = calloc(strlen(provided_card_code) + 1, sizeof(char));
    if (city->card_code == NULL) {
        perror("Erro ao alocar memoria para o codigo da carta");
        exit(EXIT_FAILURE);
    }
    strcpy(city->card_code, provided_card_code);

    printf("Digite o nome da cidade da %s carta: ", card_number);
    fgets(provided_city_name, sizeof(provided_city_name), stdin);
    provided_city_name[strcspn(provided_city_name, "\n")] = '\0';
    provided_city_name[0] = toupper(provided_city_name[0]);
    city->city_name = calloc(strlen(provided_city_name) + 1, sizeof(char));
    if (city->city_name == NULL) {
        perror("Erro ao alocar memória para o nome da cidade");
        exit(EXIT_FAILURE);
    }
    strcpy(city->city_name, provided_city_name);

    printf("Digite a populacao da %s carta: ", card_number);
    scanf("%ld", &city->population_size);
    getchar();

    printf("Digite a area da %s carta: ", card_number);
    scanf("%f", &city->area);
    getchar();

    printf("Digite o PIB da %s carta: ", card_number);
    scanf("%f", &city->gpd);
    getchar();
 
    printf("Digite o numero de pontos turisticos da %s carta: ", card_number);
    scanf("%d", &city->tourist_sites_count);
    getchar();

    return city;
}

void print_city(const City *city)
{
    // Checa se a memória para a estrutura `City` foi alocada corretamente
    if (city == NULL) {
        fprintf(stderr, "Erro: ponteiro NULL fornecido para `print_city`.\n");
        exit(EXIT_FAILURE);
    }

    // Exibe no terminal as propriedades da estrutura `City`
    printf("Estado: %c\n", city->state);
    printf("Codigo da Carta: %s\n", city->card_code);
    printf("Nome da Cidade: %s\n", city->city_name);
    printf("Populacao: %ld\n", city->population_size);
    printf("Area: %.2f km²\n", city->area);
    printf("Densidade Populacional: %.2f pessoas/km²\n", city->population_density);
    printf("PIB: %.2f bilhoes de reais\n", city->gpd / 1e9);
    printf("PIB per Capta: %.0f reais\n", city->gpd_pc);
    printf("Numero de Pontos Turisticos: %d\n", city->tourist_sites_count);
}

bool ask_to_keep_registering()
{
    // Adiciona variável auxiliar
    char response;

    printf("\nRegistrar outra carta? (S/N): ");
    
    do {
        scanf(" %c", &response);
        getchar();

        // Transforma em maiúscula a resposta do usuário
        response = toupper(response);

        // Checa se a resposta é válida
        if (response != 'S' && response != 'N')
            printf("Entrada invalida. Por favor, digite 'S' para sim ou 'N' para nao: ");

    } while (response != 'S' && response != 'N');

    // Retorna o resultado desta comparação. 1, caso verdadeiro. 0, caso falso.
    return response == 'S';
}
