#ifndef CITY_H
#define CITY_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _city
{
    char state;
    char* card_code;
    char* city_name;
    int population_size;
    float area;
    float population_density;
    float gpd;
    float gpd_pc;
    int tourist_sites_count;
} City;

/// @brief Aloca memória e coleta os dados de uma cidade a partir da entrada do
///        usuário via CLI.
/// @details 
/// - Aloca memória dinamicamente para uma estrutura do tipo City.
/// - Solicita ao usuário que insira os dados da cidade, como estado, código da
///   carta, nome, população, área, PIB, e número de pontos turísticos.
/// - Converte a entrada do estado para maiúscula.
/// - Garante que o primeiro caractere do código da carta seja convertido para
///   maiúscula.
/// - Garante que o primeiro caractere do nome da cidade seja convertido para
///   maiúscula.
/// - Valida a entrada para evitar erros de alocação, encerrando o programa em
///   caso de falha.
/// @return Um ponteiro para uma estrutura do tipo City alocada dinamicamente.
City* get_city_data();

/// @brief Registra os dados de uma cidade na lista de cidades.
/// @details
/// - Verifica se o ponteiro fornecido não é NULL. 
///   Caso contrário, exibe uma mensagem de erro descritiva e encerra o
///   programa.
/// - Aloca memória para uma nova entrada na lista de cidades.
/// - Copia os dados da cidade fornecida para a nova entrada, incluindo:
///   - Estado.
///   - Código da carta (alocando memória dinâmica para a string).
///   - Nome da cidade (alocando memória dinâmica para a string).
///   - População.
///   - Área.
///   - PIB.
///   - Número de pontos turísticos.
/// - Usa os dados fornecidos para calcular a Densidade Populacional e o PIB per
///   Capta. Adiciona os valores calculados para a nova entrada na lista de
///   cidades.
/// - Verifica se a alocação de memória foi bem-sucedida. Em caso de falha,
///   exibe uma mensagem de erro e encerra o programa.
/// @param city Um ponteiro para os dados da cidade a serem registrados. Não
///             deve ser NULL.
/// @param city_list Um ponteiro para o array de ponteiros de cidades onde a
///                  nova cidade será adicionada.
///                  Deve ter espaço suficiente para armazenar a nova entrada.
/// @param registered_cities_count O índice onde a nova cidade será armazenada. 
///                                Deve ser menor que o tamanho máximo do array.
void register_city(City* city, City** city_list, int registered_cities_count);

/// @brief Exibe as propriedades de uma cidade no CLI.
/// @details 
/// - Verifica se o ponteiro fornecido não é NULL. 
///   Caso contrário, exibe uma mensagem de erro descritiva e encerra o
///   programa.
/// - Exibe os dados armazenados na estrutura `City` no seguinte formato:
///   - Estado: Caractere representando o estado da cidade.
///   - Código da Carta: String com até 3 caracteres representando o código
///     único da cidade.
///   - Nome da Cidade: String contendo o nome completo da cidade.
///   - População: Número inteiro representando a população total da cidade.
///   - Área: Número de ponto flutuante representando a área em quilômetros
///     quadrados, com duas casas decimais.
///   - Densidade Populacional: Número de ponto flutuante representando a
///     densidade populacional em pessoas por quilômetro quadrado, com duas
///     casas decimais.
///   - PIB: Número de ponto flutuante representando o PIB em bilhões de reais,
///     com duas casas decimais.
///   - PIB per Capta: Número de ponto flutuante representando o PIB per Capta
///     em bilhões de reais, com zero casas decimais.
///   - Número de Pontos Turísticos: Número inteiro indicando a quantidade de
///     pontos turísticos.
/// - A função assume que o ponteiro `city` não é NULL. Não realiza validações
///   de NULL.
/// @param city Um ponteiro para a estrutura do tipo `City` cujas propriedades
///             serão exibidas.
///             O ponteiro deve ser válido e não NULL.
/// @note
/// - Para seguir o modelo de exibição de dados mostrado no nível "Aventureiro":
///   - A propriedade PIB é dividida por 1_000_000_000 antes de ser exibida.
///   - A propriedade PIB per Capta é mostrada sem casas decimais, apesar de ser
///     do tipo float.
void print_city(const City *city);

/// @brief Libera a memória alocada para os dados de uma cidade.
/// @details
/// - A função verifica se os argumentos fornecidos são válidos:
///   - Se `city_ref` (o ponteiro para o ponteiro da estrutura `City`) for NULL,
///     a função retorna imediatamente.
///   - Se o valor de `*city_ref` (o ponteiro para a estrutura `City`) for NULL,
///     a função também retorna imediatamente.
/// - Caso os argumentos sejam válidos:
///   - Libera a memória alocada dinamicamente para os campos `card_code` e
///     `city_name` da estrutura `City`.
///   - Em seguida, libera a memória alocada para a própria estrutura `City`.
///   - Após liberar a memória, redefine o ponteiro original (`*city_ref`) como
///     NULL para evitar dangling pointers.
/// @param city_ref Um ponteiro para o ponteiro da estrutura do tipo `City`. 
///                 Deve apontar para memória alocada dinamicamente e não deve
///                 ser NULL.
/// @note
/// - Passar `city_ref` como NULL ou um valor de `*city_ref` que seja NULL não
///   causa erros, mas a função não realizará nenhuma ação.
/// - Após a execução bem-sucedida, o ponteiro original referenciado por
///   `city_ref` será redefinido para NULL.
void free_city(City** city_ref);

/// @brief Solicita ao usuário que decida se deseja continuar registrando dados.
/// @details Exibe uma mensagem pedindo ao usuário para inserir 'S' para
///          continuar ou 'N' para parar.
///          Aceita apenas entradas válidas ('S' ou 'N', sem diferenciação entre
///          maiúsculas e minúsculas). 
///          Em caso de entrada inválida, continua solicitando até que uma
///          resposta válida seja fornecida.
/// @return Retorna true se o usuário optar por continuar ('S') ou false se
///         optar por parar ('N').
bool ask_to_keep_registering();

/// @brief Libera a memória alocada para todas as cidades na lista.
/// @details
/// - A função percorre a lista de cidades apontada por `city_list` e libera a
///   memória de cada elemento utilizando a função `free_city`.
/// - Antes de chamar `free_city`, a função verifica se cada ponteiro individual
///   no array (ou seja, `city_list[i]`) não é NULL.
/// - Após liberar a memória de cada cidade, os ponteiros individuais no array
///   são automaticamente definidos como NULL pela função `free_city`.
/// @param city_list Um ponteiro para o array de ponteiros de cidades. 
///                  Cada ponteiro no array deve apontar para uma estrutura
///                  válida do tipo `City` ou ser NULL.
/// @param registered_cities_count O número de cidades atualmente registradas na
///                                lista.
///                                Deve ser um valor não negativo.
/// @note
/// - A função não realiza nenhuma ação se `city_list` for NULL.
/// - Se algum elemento do array `city_list` for NULL, ele será ignorado sem
///   causar erros.
void free_city_list(City** city_list, int registered_cities_count);

#endif
