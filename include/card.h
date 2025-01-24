#ifndef CARD_H
#define CARD_H

/**
 * @brief Exibe as funcionalidades disponíveis para o usuário e solicita uma
 *        escolha válida.
 * 
 * Esta função apresenta ao usuário duas opções de funcionalidades e solicita
 * que ele escolha uma delas.
 * Caso o valor inserido seja inválido (não seja 1 ou 2), exibe uma mensagem de
 * erro e solicita novamente.
 * 
 * @details
 * - A função utiliza um loop `do-while` para garantir que o usuário insira um
 *   valor válido.
 * - Caso a entrada fornecida não seja um número, o buffer de entrada é limpo.
 * - Mensagens claras são exibidas para orientar o usuário em caso de erro.
 * 
 * @note Esta função é interativa e requer entrada do usuário pelo teclado.
 * 
 * @return int O número da funcionalidade escolhida pelo usuário:
 * 
 *         - 1: Registro de cartas.
 * 
 *         - 2: Registro e comparação de cartas.
 */
int choose_functionality();

/**
 * @brief Registra múltiplas cartas de cidades, gerenciando entrada de dados e
 *        alocação de memória.
 * 
 * Esta função permite que o usuário registre até um número máximo de cartas
 * (cidades) especificado.
 * Os dados de cada carta são obtidos por meio da função `get_city_data`,
 * armazenados em memória dinâmica
 * e exibidos ao usuário. O processo continua até que o limite seja atingido ou
 * o usuário escolha não registrar mais cartas.
 * 
 * @param max_cities O número máximo de cartas (cidades) que podem ser
 *                   registradas.
 * 
 * @details
 * - A função verifica se o valor de `max_cities` é positivo. Caso contrário, um
 *   erro é exibido e o programa é encerrado.
 * - Cria uma lista de ponteiros para armazenar as cartas registradas.
 * - Para cada cidade, a memória é alocada dinamicamente e os dados são copiados
 *   para a estrutura correspondente.
 * - Após cada registro, os dados são exibidos e o ponteiro usado para entrada
 *   temporária é liberado.
 * - O usuário é perguntado se deseja continuar registrando até atingir o limite
 *   de cartas.
 * - No final, todos os dados alocados são liberados para evitar vazamentos de
 *   memória.
 * 
 * @note A função depende das seguintes funções auxiliares:
 * 
 *   - `get_city_data`: Obtém os dados da cidade do usuário.
 * 
 *   - `register_city`: Copia os dados da cidade para o ponteiro correspondente
 *     e calcula o valor de propriedades extras utilizando os dados fornecidos.
 * 
 *   - `print_city`: Exibe os dados da cidade para o usuário.
 * 
 *   - `ask_to_keep_registering`: Pergunta ao usuário se deseja continuar
 *     registrando.
 * 
 *   - `free_city`: Libera a memória de uma única cidade.
 * 
 *   - `free_city_list`: Libera a memória de todas as cidades registradas.
 * 
 * @pre 
 * - O valor de `max_cities` deve ser maior que 0.
 * 
 * @warning 
 * - Caso `max_cities` seja menor ou igual a 0, a função exibirá um erro e
 *   encerrará a execução do programa.
 * 
 * - A função auxiliar `get_city_data` não realiza validações rigorosas de
 *   entrada, portanto, espera-se que o usuário insira dados válidos para evitar
 *   comportamentos indesejados.
 */
void register_cards(int max_cities);

/**
 * @brief Compara duas cartas de cidades com base em várias propriedades.
 * 
 * A função registra duas cartas de cidades, comparando-as com base em
 * diferentes critérios, como população, área, densidade populacional, PIB, PIB
 * per capita, número de pontos turísticos e um atributo fictício de "super
 * poder".
 * Para cada propriedade, a carta vencedora é determinada e exibida ao usuário.
 * 
 * @details
 * - A função aloca dinamicamente memória para armazenar as cartas das duas
 *   cidades.
 * - As duas cidades são registradas e seus dados são comparados em diversas
 *   propriedades.
 * - Após a comparação, o resultado é impresso, indicando qual cidade venceu em
 *   cada uma das propriedades.
 * 
 * @note
 * - A função depende das seguintes funções auxiliares:
 * 
 *   - `alocate_city`: Aloca e inicializa uma cidade.
 * 
 *   - `get_one_city_data`: Obtém os dados de uma cidade do usuário.
 * 
 *   - `register_city`: Registra os dados da cidade em um ponteiro específico.
 * 
 *   - `print_card_to_compare`: Exibe os dados de uma cidade para comparação.
 * 
 * @warning A função não realiza validações rigorosas de entrada, portanto,
 *          espera-se que o usuário insira dados válidos para evitar
 *          comportamentos indesejados.
 */
void compare_cards();

#endif
