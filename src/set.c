/* set.c */

#include <set.h>

/********** unsigned **********/

void set_unsigned_init(set_unsigned* T) {
  T->nil = (unsigned_node*)calloc(1, sizeof(unsigned_node));
  T->nil->color = black;
  T->root = T->nil;
}

bool set_unsigned_member(set_unsigned* T, unsigned x) {
  if (T->nil != tree_search_unsigned(T->nil,T->root,x)) { return true; }
  else { return false; }
}
  
unsigned_node* tree_search_unsigned(unsigned_node* nil, unsigned_node* x, unsigned k) {
  if (nil == x || k == x->key) { return x; }
  if (k < x->key) { return tree_search_unsigned(nil, x->left, k); }
  else { return tree_search_unsigned(nil, x->right, k); }
}

unsigned tree_minimum_value_unsigned(set_unsigned* T) { /* assume that T has at least one element */
  unsigned_node* p = T->root;
  while (T->nil != p->left) { p = p->left; }
  return p->key;
}

unsigned_node* tree_minimum_unsigned(unsigned_node* nil, unsigned_node* x) {
  while (nil != x->left) { x = x->left; }
  return x;
}

unsigned_node* tree_maximum_unsigned(unsigned_node* nil, unsigned_node* x) { /* ; */
  while (nil != x->right) { x = x->right; }
  return x;
}
  
/* this subroutine assumes that NULL != x->right and NULL == T->nil */
void left_lotate_unsigned(set_unsigned* T, unsigned_node* x) {
  if (T->nil == x->right) { return ; }
  unsigned_node* y = x->right;
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
void right_lotate_unsigned(set_unsigned* T, unsigned_node* y) {
  if (T->nil == y->left) { return ; }
  unsigned_node* x = y->left;
  y->left = x->right;
  if (T->nil != x->right) { x->right->p = y; }
  x->p = y->p;
  if (T->nil == y->p) { T->root = x; }
  else if (y == y->p->right) { y->p->right = x; }
  else { y->p->left = x; }
  x->right = y;
  y->p = x;
}

void set_insert_unsigned(set_unsigned* T, unsigned v) {
  if (T->nil != tree_search_unsigned(T->nil,T->root,v)) { return; }
  unsigned_node* z = (unsigned_node*)calloc(1,sizeof(unsigned_node));
  z->key = v;
  z->left = z->right = z->p = T->nil;
  set_insert_unsigned_sub(T, z);
}

void set_insert_unsigned_sub(set_unsigned* T, unsigned_node* z) {
  unsigned_node* y = T->nil;
  unsigned_node* x = T->root;
  while (T->nil != x) {
    y = x;
    if (z->key < x->key) { x = x->left; }
    else { x = x->right; }
    z->p = y;
  }
  if (y == T->nil) { T->root = z; } /* T is empty */
  else if (z->key < y->key) { y->left = z; }
  else { y->right = z; }
  z->left = T->nil;
  z->right = T->nil;
  z->color = red;
  set_instert_fixup_unsigned(T, z);
}

void set_instert_fixup_unsigned(set_unsigned* T, unsigned_node* z) {
  unsigned_node* y;
  
  /* while (z->p != T->nil && red == z->p->color) { */
  while (red == z->p->color) {
    if (z->p == z->p->p->left) {
      y = z->p->p->right;
      /* if (T->nil != y && red == y->color) { /\* case 1 *\/ */
      if (red == y->color) { /* case 1 */
	z->p->color = black;
	y->color = black;
	z->p->p->color = red;
	z = z->p->p;
      }
      else {
	if (z == z->p->right) { /* case 2 */
	  z = z->p;
	  left_lotate_unsigned(T,z);
	}
	z->p->color = black; /* case 3 */
	z->p->p->color = red;
	right_lotate_unsigned(T,z->p->p);
      }
    }
    else {
      y = z->p->p->left;
      /* if (T->nil != y && red == y->color) { */
      if (red == y->color) {
	z->p->color = black;
	y->color = black;
	z->p->p->color = red;
	z = z->p->p;
      }
      else {
	if (z == z->p->left) {
	  z = z->p;
	  right_lotate_unsigned(T,z);
	}
	z->p->color = black;
	z->p->p->color = red;
	left_lotate_unsigned(T,z->p->p);
      }
    }
  }
  T->root->color = black;
}

void set_transplant_unsigned(set_unsigned* T, unsigned_node* u, unsigned_node* v) {
  if (u->p == T->nil) { T->root = v; }
  else if (u == u->p->left) { u->p->left = v; }
  else { u->p->right = v; }
  v->p = u->p;
}

void set_delete_unsigned(set_unsigned* T, unsigned v) {
  /* unsigned_node* z = (unsigned_node*)calloc(1,sizeof(unsigned_node)); */
  unsigned_node* z = tree_search_unsigned(T->nil,T->root,v);
  if (NULL == z) { return; }
  set_delete_unsigned_sub(T, z);
}

void set_delete_unsigned_sub(set_unsigned* T, unsigned_node* z) {
  unsigned_node *x, *y = z;
  color y_original_color = y->color;
  if (z->left == T->nil) {
    x = z->right;
    set_transplant_unsigned(T,z,z->right);
  }
  else if (z->right == T->nil) {
    x = z->left;
    set_transplant_unsigned(T,z,z->left);
  } else {
    y = tree_minimum_unsigned(T->nil, z->right);
    y_original_color = y->color;
    x = y->right;
    if (y->p == z) { x->p = y; }
    else {
      set_transplant_unsigned(T,y,y->right);
      y->right = z->right;
      y->right->p = y;
    }
    set_transplant_unsigned(T,z,y);
    y->left = z->left;
    y->left->p = y;
    y->color = z->color;
  }
  if (black == y_original_color) { set_delete_fixup_unsigned(T,x); }
}

void set_delete_fixup_unsigned(set_unsigned* T, unsigned_node* x) {
  unsigned_node* w;
  while (x != T->root && black == x->color) {
    if (x == x->p->left) {
      w = x->p->right;
      if (red == w->color) {
	w->color = black;
	x->p->color = red;
	left_lotate_unsigned(T,x->p);
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
	  right_lotate_unsigned(T,w);
	  w = x->p->right;
	}
	w->color = x->p->color;
	x->p->color = black;
	w->right->color = black;
	left_lotate_unsigned(T,x->p);
	x = T->root;
      }
    }
    else {
      w = x->p->left;
      if (red == w->color) {
	w->color = black;
	x->p->color = red;
	right_lotate_unsigned(T,x->p);
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
	  left_lotate_unsigned(T,w);
	  w = x->p->left;
	}
	w->color = x->p->color;
	x->p->color = black;
	w->left->color = black;
	right_lotate_unsigned(T,x->p);
	x = T->root;
      }
    }
  }
  x->color = black;
}

bool set_unsigned_is_empty(set_unsigned* S) { if (S->root == S->nil) { return true; } return false; }

/* S := S ∪ T */
void set_unsigned_union(set_unsigned* S, set_unsigned* T) { set_unsigned_union_sub(S, T->root, T->nil); }

void set_unsigned_union_sub(set_unsigned* S, unsigned_node* p, unsigned_node* nil) {
  if (nil == p || NULL == p) { return; }
  set_unsigned_union_sub(S, p->left, nil);
  set_unsigned_union_sub(S, p->right, nil);
  set_insert_unsigned(S, p->key);
}

/* S := T */
void set_unsigned_copy(set_unsigned* S, set_unsigned* T) { set_unsigned_copy_sub(S, T->root, T->nil); }

void set_unsigned_copy_sub(set_unsigned* S, unsigned_node* p, unsigned_node* nil) {
  if (nil == p || NULL == p) { return; }
  set_unsigned_copy_sub(S, p->left, nil);
  set_unsigned_copy_sub(S, p->right, nil);
  set_insert_unsigned(S, p->key);
}

void set_show_unsigned_debug(unsigned_node* p, unsigned_node* nil, unsigned i) { /* post order */
  if (nil == p || NULL == p) { return; }
  set_show_unsigned_debug(p->left, nil, i+1);
  set_show_unsigned_debug(p->right, nil, i+1);
  printf("depth = %d: key = %d -- %d\n", i, p->key, p->color);
}

void set_show_unsigned(unsigned_node* p, unsigned_node* nil) { /* post order */
  if (nil == p || NULL == p) { return; }
  set_show_unsigned_sub(p, nil, 0);
}

void set_show_unsigned_sub(unsigned_node* p, unsigned_node* nil, unsigned i) { /* post order */
  if (nil == p || NULL == p) { return; }
  set_show_unsigned_sub(p->left, nil, i+1);
  set_show_unsigned_sub(p->right, nil, i+1);
  printf("%d, ", p->key);
}

void set_unsigned_clear(set_unsigned* T) {
  unsigned_node* p = T->root;
  set_unsigned_clear_sub(T->nil, p);
  free(T->nil);
}

void set_unsigned_clear_sub(unsigned_node* nil, unsigned_node* p) {
  if (nil == p) { return; }
  set_unsigned_clear_sub(nil, p->left);
  set_unsigned_clear_sub(nil, p->right);
  free(p);
}


/********** pair unsigned **********/
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
  pair_unsigned_node* z = (pair_unsigned_node*)calloc(1,sizeof(pair_unsigned_node));
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
}

void set_instert_fixup_unsigned_pair(set_unsigned_pair* T, pair_unsigned_node* z) {
  pair_unsigned_node* y;
  
  while (z->p != T->nil && red == z->p->color) {
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
  pair_unsigned_node* z = tree_search_unsigned_pair(T->root,v);
  if (NULL == z) { return; }
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

void set_unsigned_pair_clear(set_unsigned_pair* T) {
  pair_unsigned_node* p = T->root;
  set_unsigned_pair_clear_sub(p);
}

void set_unsigned_pair_clear_sub(pair_unsigned_node* p) {
  if (NULL == p) { return; }
  set_unsigned_pair_clear_sub(p->left);
  set_unsigned_pair_clear_sub(p->right);
  free(p);
}
