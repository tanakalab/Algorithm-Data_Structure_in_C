/* set.h (dynamic set) */
/* implement a red-black tree */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TANAKALAB_SET_H__
#define __TANAKALAB_SET_H__

typedef enum { red, black } color;

#ifndef __TANAKALAB_CONST_H__
#include <const.h>
#endif

#ifndef __TANAKALAB_PAIR_H__
#include <pair.h>
#endif

/* unsigned */
struct UNSIGNED_NODE {
  color color;
  unsigned key;
  struct UNSIGNED_NODE* p;
  struct UNSIGNED_NODE* left;
  struct UNSIGNED_NODE* right;
};
typedef struct UNSIGNED_NODE unsigned_node;

struct SET_UNSIGNED {
  unsigned_node* root;
  unsigned_node* nil;
};
typedef struct SET_UNSIGNED set_unsigned;

void set_unsigned_init(set_unsigned*);
bool set_unsigned_member(set_unsigned*, unsigned);
unsigned_node* tree_search_unsigned(unsigned_node*, unsigned_node*, unsigned);
unsigned tree_minimum_value_unsigned(set_unsigned*);
unsigned_node* tree_minimum_unsigned(unsigned_node*, unsigned_node*);
unsigned_node* tree_maximum_unsigned(unsigned_node*, unsigned_node*);
void left_lotate_unsigned(set_unsigned*, unsigned_node*);
void right_lotate_unsigned(set_unsigned*, unsigned_node*);
void set_insert_unsigned(set_unsigned*, unsigned);
void set_insert_unsigned_sub(set_unsigned*, unsigned_node*);
void set_instert_fixup_unsigned(set_unsigned*, unsigned_node*);
void set_transplant_unsigned(set_unsigned*, unsigned_node*, unsigned_node*);
void set_delete_unsigned(set_unsigned*, unsigned);
void set_delete_unsigned_sub(set_unsigned*, unsigned_node*);
void set_delete_fixup_unsigned(set_unsigned*, unsigned_node*);
bool set_unsigned_is_empty(set_unsigned*);
void set_unsigned_union(set_unsigned*, set_unsigned*);
void set_unsigned_union_sub(set_unsigned*, unsigned_node*, unsigned_node*);
void set_unsigned_copy(set_unsigned*, set_unsigned*);
void set_unsigned_copy_sub(set_unsigned*, unsigned_node*, unsigned_node*);
void set_show_unsigned_debug(unsigned_node*, unsigned_node*, unsigned);
void set_show_unsigned(unsigned_node*, unsigned_node*);
void set_show_unsigned_sub(unsigned_node*, unsigned_node*, unsigned);
void set_unsigned_clear(set_unsigned*);
void set_unsigned_clear_sub(unsigned_node*, unsigned_node*);

/* pair unsigned */
struct PAIR_UNSIGNED_NODE {
  color color;
  pair_unsigned key;
  struct PAIR_UNSIGNED_NODE* p;
  struct PAIR_UNSIGNED_NODE* left;
  struct PAIR_UNSIGNED_NODE* right;
};
typedef struct PAIR_UNSIGNED_NODE pair_unsigned_node;

struct SET_UNSIGNED_PAIR {
  pair_unsigned_node* root;
  pair_unsigned_node* nil;
};
typedef struct SET_UNSIGNED_PAIR set_unsigned_pair;

pair_unsigned_node* tree_search_unsigned_pair(pair_unsigned_node*, pair_unsigned);
pair_unsigned_node* tree_minimum_unsigned_pair(pair_unsigned_node*);
pair_unsigned_node* tree_maximum_unsigned_pair(pair_unsigned_node*);
void left_lotate_unsigned_pair(set_unsigned_pair*, pair_unsigned_node*);
void right_lotate_unsigned_pair(set_unsigned_pair*, pair_unsigned_node*);
void set_insert_unsigned_pair(set_unsigned_pair*, pair_unsigned);
void set_insert_unsigned_pair_sub(set_unsigned_pair*, pair_unsigned_node*);
void set_instert_fixup_unsigned_pair(set_unsigned_pair*, pair_unsigned_node*);
void set_transplant_unsigned_pair(set_unsigned_pair*, pair_unsigned_node*, pair_unsigned_node*);
void set_delete_unsigned_pair(set_unsigned_pair*, pair_unsigned);
void set_delete_unsigned_pair_sub(set_unsigned_pair*, pair_unsigned_node*);
void set_delete_fixup_unsigned_pair(set_unsigned_pair*, pair_unsigned_node*);

void set_show_unsigned_pair(pair_unsigned_node*, unsigned);
void set_unsigned_pair_clear(set_unsigned_pair*);
void set_unsigned_pair_clear_sub(pair_unsigned_node*);

#endif
