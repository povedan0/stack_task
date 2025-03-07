/**
 * @file count.c
 * @brief Implementation of stack count utilities.
 *
 */
#include "count.h"

#include "stack.h"
#include "types.h"

/* ALL THE CODE must between written between the <START_CODE> and <END_CODE>
tags. Auxiliary functions can also be defined between those lines.
*/

#define COUNT_ERROR -1

/*<START_CODE>*/

int stack_count_if(Stack *stack, Boolean (*ele_check)(void *)) {
  Stack *aux = stack_new();
  void *element = NULL;
  long i = 0;

  if (!stack || !ele_check || !aux) return COUNT_ERROR;

  while (stack_is_empty(stack) == FALSE) {
    if (ele_check(element = stack_pop(stack))) {
      i++;
    }
    stack_push(aux, element);
  }

  while (stack_is_empty(aux) == FALSE) {
    stack_push(stack, stack_pop(aux));
  }

  return i;
}

/*<END_CODE>*/