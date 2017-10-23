/* set.c */

#include <set.h>

pair_unsigned_node* tree_search_unsigned_pair(pair_unsigned_node* x, pair_unsigned k) {
  if (NULL == x || eq_pair_unsigned(k,x->key)) { return x; }
  if (leq_pair_unsigned(k, x->key)) { return tree_search_unsigned_pair(x->left, k); }
  else { return tree_search_unsigned_pair(x->right, k); }
}

pair_unsigned_node* tree_minimum_unsigned_pair(pair_unsigned_node* x) {
  while (NULL != x->left) { x = x->left; }
  return x;
}

pair_unsigned_node* tree_maximum_unsigned_pair(pair_unsigned_node* x) {
  while (NULL != x->right) { x = x->right; }
  return x;
}
  
/* this subroutine assumes that NULL != x->right and NULL == T->nil */
void left_lotate_unsigned_pair(set_unsigned_pair* T, pair_unsigned_node* x) {
  if (NULL == x->right) { return ; }
  pair_unsigned_node* y = x->right;
  x->right = y->left;
  if (T->nil != y->left) { y->left->p = x; }
  y->p = x->p;
  if (T->nil == x->p) { T->root = y; }
  else if (x == x->p->left) { x->p->left = y; }
  else { x->p->right = y; }
  y->left = x;
  x->p = y;
}

/* this subroutine assumes that NULL != y->left and NULL == T->nil */
void right_lotate_unsigned_pair(set_unsigned_pair* T, pair_unsigned_node* y) {
  if (NULL == y->left) { return ; }
  pair_unsigned_node* x = y->left;
  y->left = x->right;
  if (T->nil != x->right) { x->right->p = y; }
  x->p = y->p;
  if (T->nil == y->p) { T->root = x; }
  else if (y == y->p->right) { y->p->right = x; }
  else { y->p->left = x; }
  x->right = y;
  y->p = x;
}

void set_insert_unsigned_pair(set_unsigned_pair* T, pair_unsigned v) {
  if (NULL != tree_search_unsigned_pair(T->root,v)) { return; }
  printf("1: %d %d\n", v.first, v.second);
  pair_unsigned_node* z = (pair_unsigned_node*)malloc(sizeof(pair_unsigned_node));
  z->key.first = v.first;
  z->key.second = v.second;
  z->left = z->right = z->p = NULL;
  set_insert_unsigned_pair_sub(T, z);
}

void set_insert_unsigned_pair_sub(set_unsigned_pair* T, pair_unsigned_node* z) {
  pair_unsigned_node* y = T->nil;
  pair_unsigned_node* x = T->root;
  while (T->nil != x) {
    y = x;
    if (lt_pair_unsigned(z->key,x->key)) { x = x->left; }
    else { x = x->right; }
    z->p = y;
  }
  if (y == T->nil) { T->root = z; } /* T is empty */
  else if (lt_pair_unsigned(z->key, y->key)) { y->left = z; }
  else { y->right = z; }
  z->left = T->nil;
  z->right = T->nil;
  z->color = red;
  set_instert_fixup_unsigned_pair(T, z);
  printf("2: %d %d\n\n", z->key.first, z->key.second);
}

void set_instert_fixup_unsigned_pair(set_unsigned_pair* T, pair_unsigned_node* z) {
  pair_unsigned_node* y;
  
  while (z->p != T->nil && red == z->p->color) {
    printf("hoge\n");
    if (z->p == z->p->p->left) {
      y = z->p->p->right;
      if (T->nil != y && red == y->color) { /* case 1 */
	z->p->color = black;
	y->color = black;
	z->p->p->color = red;
	z = z->p->p;
      }
      else {
	if (z == z->p->right) { /* case 2 */
	  z = z->p;
	  left_lotate_unsigned_pair(T,z);
	}
	z->p->color = black; /* case 3 */
	z->p->p->color = red;
	right_lotate_unsigned_pair(T,z->p->p);
      }
    }
    else {
      y = z->p->p->left;
      if (T->nil != y && red == y->color) {
	z->p->color = black;
	y->color = black;
	z->p->p->color = red;
	z = z->p->p;
      }
      else {
	if (z == z->p->left) {
	  z = z->p;
	  right_lotate_unsigned_pair(T,z);
	}
	z->p->color = black;
	z->p->p->color = red;
	left_lotate_unsigned_pair(T,z->p->p);
      }
    }
  }
  T->root->color = black;
}

void set_transplant_unsigned_pair(set_unsigned_pair* T, pair_unsigned_node* u, pair_unsigned_node* v) {
  if (u->p == T->nil) { T->root = v; }
  else if (u == u->p->left) { u->p->left = v; }
  else { u->p->right = v; }
  v->p = u->p;
}

void set_delete_unsigned_pair(set_unsigned_pair* T, pair_unsigned v) {
  if (NULL == tree_search_unsigned_pair(T->root,v)) { return; }
  pair_unsigned_node* z = (pair_unsigned_node*)malloc(sizeof(pair_unsigned_node));
  z->key.first = v.first;
  z->key.second = v.second;
  set_delete_unsigned_pair_sub(T, z);
}

void set_delete_unsigned_pair_sub(set_unsigned_pair* T, pair_unsigned_node* z) {
  pair_unsigned_node *x, *y = z;
  color y_original_color = y->color;
  if (z->left == T->nil) {
    x = z->right;
    set_transplant_unsigned_pair(T,z,z->right);
  }
  else if (z->right == T->nil) {
    x = z->left;
    set_transplant_unsigned_pair(T,z,z->left);
  } else {
    y = tree_minimum_unsigned_pair(z->right);
    y_original_color = y->color;
    x = y->right;
    if (y->p == z) { x->p = y; }
    else {
      set_transplant_unsigned_pair(T,y,y->right);
      y->right = z->right;
      y->right->p = y;
    }
    set_transplant_unsigned_pair(T,z,y);
    y->left = z->left;
    y->left->p = y;
    y->color = z->color;
  }
  if (black == y_original_color) { set_delete_fixup_unsigned_pair(T,x); }
}

void set_delete_fixup_unsigned_pair(set_unsigned_pair* T, pair_unsigned_node* x) {
  pair_unsigned_node* w;
  while (x != T->root && black == x->color) {
    if (x == x->p->left) {
      w = x->p->right;
      if (red == w->color) {
	w->color = black;
	x->p->color = red;
	left_lotate_unsigned_pair(T,x->p);
	w = x->p->right;
      }
      if (black == w->left->color && black == w->right->color) {
	w->color = red;
	x = x->p;
      }
      else {
	if (black == w->right->color) {
	  w->left->color = black;;
	  w->color = red;
	  right_lotate_unsigned_pair(T,w);
	  w = x->p->right;
	}
	w->color = x->p->color;
	x->p->color = black;
	w->right->color = black;
	left_lotate_unsigned_pair(T,x->p);
	x = T->root;
      }
    }
    else {
      w = x->p->left;
      if (red == w->color) {
	w->color = black;
	x->p->color = red;
	right_lotate_unsigned_pair(T,x->p);
	w = x->p->left;
      }
      if (black == w->right->color && black == w->left->color) {
	w->color = red;
	x = x->p;
      }
      else {
	if (black == w->left->color) {
	  w->right->color = black;;
	  w->color = red;
	  left_lotate_unsigned_pair(T,w);
	  w = x->p->left;
	}
	w->color = x->p->color;
	x->p->color = black;
	w->left->color = black;
	right_lotate_unsigned_pair(T,x->p);
	x = T->root;
      }
    }
  }
  x->color = black;
}

/* post order */
void set_show_unsigned_pair(pair_unsigned_node* p, unsigned i) {
  if (NULL == p) { return; }
  set_show_unsigned_pair(p->left, i+1);
  set_show_unsigned_pair(p->right, i+1);
  printf("%d: (%d, %d) -- %d\n", i, p->key.first, p->key.second, p->color);
}
