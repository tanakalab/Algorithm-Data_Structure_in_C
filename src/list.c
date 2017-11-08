#include <list.h>

/********** for string ***********/
string_cell* string_list_search(string_list* L, char* s) {
  string_cell* x = L->head;
  while (NULL != x && 0 != strcmp(x->key, s)) { x = x->next; }
  return x;
}

void string_list_insert(string_list* L, char* s) {
  string_cell* new = (string_cell*)malloc(sizeof(string_cell));
  unsigned l = strlen(s) + 1;
  new->key = (char*)malloc(l*sizeof(char));
  strcpy(new->key, s);
  string_list_insert_sub(L,new);
}

void string_list_insert_sub(string_list* L, string_cell* x) {
  x->next = L->head;
  if (NULL != L->head) { L->head->prev = x; }
  else { L->last = x; }
  L->head = x;
  x->prev = NULL;
}

void string_list_delete(string_list* L, char* s) {
  string_cell* x = string_list_search(L, s);
  if (NULL != x) { string_list_delete_sub(L, x); }
}

void string_list_delete_sub(string_list* L, string_cell* x) {
  if (NULL != x->prev) { x->prev->next = x->next; }
  else { L->head = x->next; }
  if (NULL != x->next) { x->next->prev = x->prev; }
  else { L->last = x->prev; }
}

string_list* string_lists_concat(string_list* L1, string_list* L2) {
  if (NULL == L1) { return L2; }
  L1->last->next = L2->head;
  if (NULL != L2) { L2->head->prev = L1->last; }
  return L1;
}

void string_list_clear(string_list* L) {
  string_cell* p, *q;
  for (p = L->head; NULL != p; ) {
    free(p->key);
    q = p;
    p = p->next;
    free(q);
  }
}

void show_string_list(string_list* L) {
  string_cell* p;
  for (p = L->head; NULL != p; p = p->next) { printf("%s\n", p->key); }
}


/********** for pair of unsigned ***********/
pair_unsigned_cell* pair_unsigned_list_search(pair_unsigned_list* L, pair_unsigned pu) {
  pair_unsigned_cell* x = L->head;
  while (NULL != x && eq_pair_unsigned(x->key, pu)) { x = x->next; }
  return x;
}

void pair_unsigned_list_insert(pair_unsigned_list* L, pair_unsigned pu) {
  pair_unsigned_cell* new = (pair_unsigned_cell*)malloc(sizeof(pair_unsigned_cell));
  new->key = pu;
  pair_unsigned_list_insert_sub(L,new);
}

void pair_unsigned_list_insert_sub(pair_unsigned_list* L, pair_unsigned_cell* x) {
  x->next = L->head;
  if (NULL != L->head) { L->head->prev = x; }
  else { L->last = x; }
  L->head = x;
  x->prev = NULL;
}

void pair_unsigned_list_delete(pair_unsigned_list* L, pair_unsigned pu) {
  pair_unsigned_cell* x = pair_unsigned_list_search(L, pu);
  if (NULL != x) { pair_unsigned_list_delete_sub(L, x); }
}

void pair_unsigned_list_delete_sub(pair_unsigned_list* L, pair_unsigned_cell* x) {
  if (NULL != x->prev) { x->prev->next = x->next; }
  else { L->head = x->next; }
  if (NULL != x->next) { x->next->prev = x->prev; }
  else { L->last = x->prev; }
}

pair_unsigned_list* pair_unsigned_lists_concat(pair_unsigned_list* L1, pair_unsigned_list* L2) {
  if (NULL == L1) { return L2; }
  L1->last->next = L2->head;
  if (NULL != L2) { L2->head->prev = L1->last; }
  return L1;
}

void pair_unsigned_list_clear(pair_unsigned_list* L) {
  pair_unsigned_cell* p, *q;
  for (p = L->head; NULL != p; ) {
    q = p;
    p = p->next;
    free(q);
  }
}

pair_unsigned_list* pair_unsigned_list_copy(pair_unsigned_list* L) {
  if (NULL == L) { return NULL; }
  
  pair_unsigned_list* C = (pair_unsigned_list*)calloc(1, sizeof(pair_unsigned_list));
  pair_unsigned_cell* l;
  pair_unsigned p;
  for (l = L->head; NULL != l; l = l->next) {
    p.first = l->key.first, p.second = l->key.second;
    pair_unsigned_list_insert(C, p);
  }
  
  return C;
}

void show_pair_unsigned_list(pair_unsigned_list* L) {
  pair_unsigned_cell* p;
  for (p = L->head; NULL != p; p = p->next) { printf("(%d, %d)\n", p->key.first, p->key.second); }
}
