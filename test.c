#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "set.h"


int main(void) {
  /**************** list pair unsigned ****************/
  pair_unsigned x = { 3, 5 };
  pair_unsigned y = { 7, 9 };
  pair_unsigned z = { 9, 0 };

  list_pair_unsigned* L = (list_pair_unsigned*)malloc(sizeof(list_pair_unsigned));
  list_pair_unsigned_insert2(L, x);
  list_pair_unsigned_insert2(L, y);
  list_pair_unsigned_insert2(L, z);
  list_pair_unsigned_insert(L, 99, 100);

  list_pair_unsigned_print(L); putchar('\n');
  list_pair_unsigned_delete(L, 99, 4);
  list_pair_unsigned_delete(L, 3, 5);
  list_pair_unsigned_print(L); putchar('\n');

  list_pair_unsigned_clear(L);
  free(L);

  /**************** list pair unsigned ****************/
  set_unsigned* S = (set_unsigned*)malloc(sizeof(set_unsigned));
  set_unsigned_init(S);

  set_unsigned_insert(S, 2);
  set_unsigned_insert(S, 3);
  set_unsigned_insert(S, 5);

  set_unsigned_print(S); putchar('\n');
  set_unsigned_delete(S, 2);
  set_unsigned_delete(S, 0);
  set_unsigned_print(S); putchar('\n');

  set_unsigned_clear(S);
  free(S);

  return 0;
}
