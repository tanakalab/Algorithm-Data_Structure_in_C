/* list.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TANAKALAB_LIST_H__
#define __TANAKALAB_LIST_H__

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

#endif
