#ifndef CITY_H
#define CITY_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct City
 * @brief Representa os dados de uma cidade.
 *
 * Esta estrutura armazena informações detalhadas sobre uma cidade, 
 * incluindo estado, nome, população, área e outras estatísticas relevantes.
 */
typedef struct _city
{
    char state; /**< O estado associado à cidade. Possíveis valores: A, B, C, D, E, F, G, H. */
    char* card_code; /**< O código da carta associado à cidade. Possíveis valores: a combinação de valor de `state` e um número entre 01, 02, 03 e 04.*/
    char* city_name; /**< O nome da cidade. */
    unsigned long int population_size; /**< Tamanho da população da cidade. */
    float area; /**< Área da cidade (km²). */
    float population_density; /**< Densidade populacional (pessoas por km²). */
    float gpd; /**< Produto Interno Bruto (PIB) da cidade. */
    float gpd_pc; /**< PIB per capita da cidade. */
    int tourist_sites_count; /**< Número de pontos turísticos na cidade. */
    float super_power; /**< A soma de todos os valores numéricos da cidade. */
} City;

/**
 * @brief Aloca memória para uma nova cidade.
 *
 * Esta função aloca dinamicamente memória para uma estrutura do tipo `City`
 * usando a função `calloc`. Se a alocação falhar, a função imprime uma
 * mensagem de erro e termina o programa com `exit(EXIT_FAILURE)`.
 *
 * @return Um ponteiro para a estrutura `City` alocada na memória.
 *
 * @note A memória alocada para a cidade deve ser liberada com a função
 *       `free_city` quando não for mais necessária.
 */
City* alocate_city();

/**
 * @brief Registra os dados de uma cidade em um item de lista.
 *
 * Esta função copia os dados de uma cidade (`city`) para um item de uma lista
 * de cidades (`city_in_list`). Ela realiza a alocação dinâmica de memória para
 * os campos da cidade na lista, como o nome da cidade e o código da carta.
 * Além disso, calcula a densidade populacional, o PIB per capita e o superpoder
 * da cidade com base nos dados fornecidos.
 *
 * @param city Ponteiro para a cidade de origem cujos dados serão copiados.
 * @param city_in_list Ponteiro para a cidade na lista onde os dados serão
 *                     registrados.
 *
 * @note Se algum dos ponteiros fornecidos for `NULL`, a função imprimirá uma
 *       mensagem de erro e finalizará o programa com `exit(EXIT_FAILURE)`.
 *       Além disso, a função realiza alocação dinâmica de memória, e o espaço
 *       alocado deve ser liberado quando não for mais necessário.
 *
 * @see alocate_city()
 */
void register_city(City* city, City* city_in_list);

/**
 * @brief Libera a memória alocada para uma cidade.
 *
 * Esta função libera a memória associada a uma cidade, incluindo o código da
 * carta, o nome da cidade e a estrutura da cidade em si. Ela verifica se o
 * ponteiro fornecido não é `NULL` antes de tentar liberar a memória, garantindo
 * que a operação seja segura.
 * Após liberar a memória, o ponteiro da cidade é setado para `NULL` para evitar
 * o uso de ponteiros pendentes.
 *
 * @param city_ref Ponteiro duplo para a cidade que será liberada.
 *
 * @note Se o ponteiro `city_ref` ou o ponteiro para a cidade (referenciado por
 *       `city_ref`) forem `NULL`, a função não realizará nenhuma operação.
 *
 * @see alocate_city()
 */
void free_city(City** city_ref);

/**
 * @brief Libera a memória de uma lista de cidades.
 *
 * Esta função itera sobre uma lista de cidades e, para cada cidade registrada
 * (não `NULL`), chama a função `free_city()` para liberar a memória alocada
 * para essa cidade. A função garante que a memória alocada para cada cidade da
 * lista seja liberada de forma segura.
 *
 * @param city_list Ponteiro para a lista de cidades a serem liberadas.
 * @param registered_cities_count Número de cidades registradas na lista.
 *
 * @note A função não verifica se `city_list` é `NULL`. A verificação é feita na
 *       função `free_city()`.
 *       A função `free_city()` é chamada para cada cidade na lista, garantindo
 *       que todos os elementos sejam liberados corretamente.
 *
 * @see free_city()
 */
void free_city_list(City** city_list, int registered_cities_count);

#endif
