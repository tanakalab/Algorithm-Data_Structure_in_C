/* set.h */

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
