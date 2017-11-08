/* hash.h (static set) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TANAKALAB_HASH_H__
#define __TANAKALAB_HASH_H__

#ifndef __TANAKALAB_CONST_H__
#include <const.h>
#endif

#ifndef __TANAKALAB_PAIR_H__
#include <pair.h>
#endif

typedef enum { occupied, empty, deleted } oed;

struct HASH_UNSIGNED_CELL {
  unsigned v;
  oed state;
};
typedef struct HASH_UNSIGNED_CELL hash_unsigned_cell;

struct HASH_UNSIGNED {
  unsigned B; /* budget size */
  hash_unsigned_cell* A;
};
typedef struct HASH_UNSIGNED hash_unsigned;

void hash_init(hash_unsigned*, unsigned);
bool member(unsigned, hash_unsigned*);
bool member_sub(unsigned, hash_unsigned_cell*, unsigned);
void hash_unsigned_delete(unsigned, hash_unsigned*);
void hash_unsigned_delete_sub(unsigned, hash_unsigned_cell*, unsigned);
void hash_unsigned_insert(unsigned, hash_unsigned*);
void hash_unsigned_insert_sub(unsigned, hash_unsigned_cell*, unsigned);
void hash_unsigned_clear(hash_unsigned*);
int h(unsigned, unsigned);

#endif
