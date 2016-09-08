#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 100	/* バケット数 */
#define W 6	/* 語長 */
typedef enum { yes, no } yn;	/* 列挙型データ yn */
typedef enum { occupied, empty, deleted } oed;	/* 列挙型データ oed */

struct WORD {
  char name[W+1];
  oed state;
};
typedef struct WORD word;

void insert(char*, word*);
void delete(char*, word*);
yn member(char*, word*);

int h(char*);

int main(void)
{
  word A[B];	/* ハッシュ表A */

  {
    int i;
    for (i = 0; i < B; ++i)
      A[i].state = empty;
  }

  // debug code 
  /* printf("insert \"a\" to the hash table A\n"); */
  /* insert("a", A); */
  /* printf("delete \"a\" to the hash table A\n"); */
  /* delete("a", A); */
  /* printf("insert \"a\" to the hash table A\n"); */
  /* insert("a", A); */
  /* member("a", A); */
  /* printf("insert \"aa\" to the hash table A\n"); */
  /* insert("aa", A); */
  /* printf("insert \"ab\" to the hash table A\n"); */
  /* insert("ab", A); */
  /* printf("insert \"ac\" to the hash table A\n"); */
  /* insert("ac", A); */
  /* printf("insert \"ad\" to the hash table A\n"); */
  /* insert("ad", A); */

  /* if (yes == member("hoge", A)) */
  /*   printf("hoge is in the hash table A\n"); */
  
  return 0;
}

void insert(char*x, word *A) // ハッシュ表Aへ文字列xの挿入
{
  int i, k, found = -1;
  oed cstate;

  k = i = h(x);	// xのハッシュ函数値
  do {
    cstate = A[k].state;
    printf("x = %s, i = %d, h(x) = %d, cstate = %d\n", x, i, k, cstate);
    if (empty == cstate || deleted == cstate) {
      if (found < 0)
	found = k; // 空きセル有り
    }
    else {
      if (0 == (strcmp(x, A[k].name))) { // xは既に存在
	printf("%s already exists.\n", x);
	return;
      }
    }
    k = (k+1)%B;	// 次のセルへ
  }
  while (empty != cstate && k != i);
  if (found < 0) {	// Aは満杯（誤り）
    printf("Error: Dictionary is full.\n");
    exit(1);
  }
  strcpy(A[found].name,x);	// A[found]へxの挿入
  A[found].state = occupied;
}

void delete(char* x, word* A) // ハッシュ表Aから文字列xの除去 
{
  int i, k;
  oed cstate;

  k = i = h(x);	// xのハッシュ函数値 
  do {
    cstate = A[k].state;
    if (occupied == cstate) 
      if (0 == strcmp(x, A[k].name)) {
	A[k].state = deleted;
	return;
      }
    k = (k+1)%B;	// 次のセルへ
  } while (empty != cstate && k != i);

  return;	// xは存在せず
}

yn member(char* x, word* A)
{
  int i, k;
  oed cstate;

  k = i = h(x);	// xのハッシュ函数値
  do { // xの探索
    cstate = A[k].state;
    if (occupied == cstate) {
      if (0 == strcmp(x, A[k].name)) {
	printf("found \"%s\" in A[%d]\n", x, k);
	return yes;	// xの発見
      }
    }
    k = (k+1)%B;	// 次のセルへ
  } while (empty != cstate && k != i);
  return no;	// xは存在せず
}

int h(char* x)
{
  int i, hash;
	
  hash = i = 0;
  while (x[i] != 0 && i < W) {
    hash = hash + (int)x[i]; ++i;
  }
  hash = hash % B;
  return hash;
}
