#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(void) {
  /*********** list pair unsigned ***********/
  pair_unsigned x = { 3, 5 };
  pair_unsigned y = { 7, 9 };
  pair_unsigned z = { 9, 0 };

  list_pair_unsigned* L = (list_pair_unsigned*)malloc(sizeof(list_pair_unsigned));
  list_pair_unsigned_insert2(L, x);
  list_pair_unsigned_insert2(L, y);
  list_pair_unsigned_insert2(L, z);
  list_pair_unsigned_insert(L, 99, 100);

  list_pair_unsigned_print(L);

  free(L);



  return 0;
}
