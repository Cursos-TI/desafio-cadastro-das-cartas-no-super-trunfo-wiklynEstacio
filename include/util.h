#ifndef UTIL_H // Include Guards
#define UTIL_H

#include <stdbool.h>

/**
 * @brief Verifica se uma funcionalidade é válida.
 * 
 * @param functionality O valor da funcionalidade a ser verificada.
 * @return true se a funcionalidade for válida, false caso contrário.
 * 
 * @details Uma funcionalidade é considerada válida se seu valor estiver dentro 
 * do intervalo definido por `RegisterCards` e `CompareAllProperties`.
 */
bool is_valid_functionality(int property);

#endif
