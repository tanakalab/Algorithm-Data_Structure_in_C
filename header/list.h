/* list.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TANAKALAB_LIST_H__
#define __TANAKALAB_LIST_H__

/********** pair of string **********/
struct STRING_CELL {
  char* key;
  struct STRING_CELL* prev;
  struct STRING_CELL* next;
};
typedef struct STRING_CELL string_cell;

struct STRING_LIST {
  string_cell* head;
  string_cell* last;
};
typedef struct STRING_LIST string_list;
  
string_cell* string_list_search(string_list*, char*);
void string_list_insert(string_list*, char*);
void string_list_insert_sub(string_list*, string_cell*);
void string_list_delete(string_list*, char*);
void string_list_delete_sub(string_list*, string_cell*);
string_list* string_lists_concat(string_list*, string_list*);
void string_list_clear(string_list*);
void show_string_list(string_list*);

/********** pair of unsigned **********/
struct PAIR_UNSIGNED_CELL {
  pair_unsigned key;
  struct PAIR_UNSIGNED_CELL* prev;
  struct PAIR_UNSIGNED_CELL* next;
};
typedef struct PAIR_UNSIGNED_CELL pair_unsigned_cell;

struct PAIR_UNSIGNED_LIST {
  pair_unsigned_cell* head;
  pair_unsigned_cell* last;
};
typedef struct PAIR_UNSIGNED_LIST pair_unsigned_list;
  
pair_unsigned_cell* pair_unsigned_list_search(pair_unsigned_list*, pair_unsigned);
void pair_unsigned_list_insert(pair_unsigned_list*, pair_unsigned);
void pair_unsigned_list_insert_sub(pair_unsigned_list*, pair_unsigned_cell*);
void pair_unsigned_list_delete(pair_unsigned_list*, pair_unsigned);
void pair_unsigned_list_delete_sub(pair_unsigned_list*, pair_unsigned_cell*);
pair_unsigned_list* pair_unsigned_lists_concat(pair_unsigned_list*, pair_unsigned_list*);
void pair_unsigned_list_clear(pair_unsigned_list*);
void show_pair_unsigned_list(pair_unsigned_list*);

#endif
