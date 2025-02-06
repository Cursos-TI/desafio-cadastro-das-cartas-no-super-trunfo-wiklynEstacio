#ifndef INTERFACE_H // Include Guards
#define INTERFACE_H

#include "city.h"

/**
 * @brief Solicita e coleta dados sobre uma cidade.
 *
 * Esta função interage com o usuário para obter informações sobre uma cidade,
 * como estado, código da carta, nome da cidade, população, área, PIB e número
 * de pontos turísticos.
 * Após coletar esses dados, a função aloca a memória necessária para
 * armazená-los, com função auxilixar `alocate_city()` e retorna um ponteiro
 * para uma estrutura `City` preenchida com as informações fornecidas.
 *
 * @return Ponteiro para uma estrutura `City` contendo os dados fornecidos pelo
 *         usuário.
 *
 * @note A função realiza a alocação dinâmica de memória para o código da carta
 *       (`card_code`) e para o nome da cidade (`city_name`), e a memória
 *       alocada é de responsabilidade do chamador. Caso ocorra falha na
 *       alocação de memória, o programa será finalizado com um erro.
 *
 * @warning Certifique-se de liberar a memória da estrutura `City` e seus campos
 *          após o uso, utilizando a função `free_city()`.
 */
City* get_city_data();

/**
 * @brief Solicita e coleta dados sobre uma cidade. Esta função é praticamente
 * idêntica à função `get_city_data()`, mas é usada no fluxo de comparação de
 * cartas.
 *
 * Esta função interage com o usuário para obter informações sobre uma cidade,
 * como estado, código da carta, nome da cidade, população, área, PIB e número
 * de pontos turísticos.
 * Após coletar esses dados, a função aloca a memória necessária para
 * armazená-los, com função auxilixar `alocate_city()` e retorna um ponteiro
 * para uma estrutura `City` preenchida com as informações fornecidas.
 *
 * @return Ponteiro para uma estrutura `City` contendo os dados fornecidos pelo
 *         usuário.
 *
 * @note A função realiza a alocação dinâmica de memória para o código da carta
 *       (`card_code`) e para o nome da cidade (`city_name`), e a memória
 *       alocada é de responsabilidade do chamador. Caso ocorra falha na
 *       alocação de memória, o programa será finalizado com um erro.
 *
 * @warning Certifique-se de liberar a memória da estrutura `City` e seus campos
 *          após o uso, utilizando a função `free_city()`.
 */
City* get_one_city_data(char* card_number);

/**
 * @brief Exibe os dados de uma cidade.
 *
 * Esta função imprime no console as informações detalhadas sobre uma cidade,
 * incluindo o estado, código da carta, nome da cidade, população, área,
 * densidade populacional, PIB, PIB per capita e o número de pontos turísticos.
 *
 * @param city Ponteiro para a estrutura `City` contendo os dados a serem
 *             exibidos.
 *
 * @note
 *  * - A Área é exibida com duas casa decimais em quilômetros quadrados.
 * 
 * - A Densidade Populacional é exibida com duas casa decimais em pessoas por
 *   quilômetro quadrado.
 * 
 * - O valor do PIB é exibido com duas casa decimais em bilhões de reais.
 * 
 * - O PIB per capita é exibido em reais com zero casas decimais, pois assim
 *   estava no modelo fornecido.
 * 
 * @warning Se o ponteiro `city` for `NULL`, a função exibirá uma mensagem de
 *          erro e encerrará o programa.
 */
void print_city(const City *city);

/**
 * @brief Exibe os dados de uma cidade. Esta função é praticamente idêntica à
 * função `print_city()`, mas é usada no fluxo de comparação de cartas.
 *
 * Esta função imprime no console as informações detalhadas sobre uma cidade,
 * incluindo o estado, código da carta, nome da cidade, população, área,
 * densidade populacional, PIB, PIB per capita, o número de pontos turísticos e
 * o super poder.
 *
 * @param city Ponteiro para a estrutura `City` contendo os dados a serem
 *             exibidos.
 *
 * @note
 * - A Área é exibida com duas casa decimais em quilômetros quadrados.
 * 
 * - A Densidade Populacional é exibida com duas casa decimais em pessoas por
 *   quilômetro quadrado.
 * 
 * - O valor do PIB é exibido com duas casa decimais em bilhões de reais.
 * 
 * - O PIB per capita é exibido em reais com zero casas decimais, pois assim
 *   estava no modelo fornecido.
 * 
 * - O valor de Super Poder é exibido com duas casa decimais.
 * 
 * @warning Se o ponteiro `city` for `NULL`, a função exibirá uma mensagem de
 *          erro e encerrará o programa.
 */
void print_card_to_compare(const City *city, int card_number);

/**
 * @brief Pergunta ao usuário se deseja continuar registrando.
 *
 * Esta função solicita ao usuário que informe se deseja registrar outra carta.
 * O usuário deve responder com 'S' para sim ou 'N' para não. A função retorna
 * um valor booleano indicando se o usuário escolheu continuar registrando
 * (verdadeiro para 'S' e falso para 'N').
 *
 * @return Retorna `true` se o usuário responder 'S' (sim), e `false` se
 *         responder 'N' (não).
 *
 * @note Esta função utiliza a função `toupper` para garantir que a entrada seja
 *       tratada de forma insensível a maiúsculas e minúsculas.
 *
 * @warning A função continuará solicitando a entrada até que o usuário forneça
 *          uma resposta válida ('S' ou 'N').
 */
bool ask_to_keep_registering();

#endif
