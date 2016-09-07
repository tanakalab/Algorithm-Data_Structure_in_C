#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 100	/* バケット数 */
#define W 6	/* 語長 */
typedef enum { yes, no } yn;

struct HASH {
	char name[W+1];
	struct HASH *next;
};
typedef struct HASH hash;

void insert(char*, hash **);
void delete(char*, hash**);
yn member(char*, hash**);

int h(char*);

int main(void)
{
	hash* A[B];	/* ハッシュ表A */

	{ 
		int j;
		for (j = 0; j <B; ++j) A[j] = NULL;
	}

	/* debug code 
	printf("insert \"hoge\" to the hash table A\n");
	insert("hoge", A);
	printf("insert \"piyo\" to the hash table A\n");
	insert("piyo", A);

	if (yes == member("hoge", A))
		printf("hoge is in the hash table A\n");
	*/

	return 0;
}

void insert(char*x, hash **A)
{
	int k;
	hash *p, *q, *r;

	k = h(x);	/* xの入るバケット番号 */
	q = A[k];	/* バケットk内の探索 */
	p = (hash*)malloc(sizeof(hash));	/* 新しいポインタの獲得 */
	if (NULL == q) A[k] = p;
	else {
		while (NULL != q) {
			if (0 == strcmp(q->name,x)) { /* xは既に存在 */
				free(p); return;
			}
			else { r = q; q = q->next; }
		}
		r->next = p;	/* 次へ */
	}
	strcpy(p->name,x);	/* xの挿入 */
	p->next = NULL;
	return; 
}

void delete(char* x, hash** A) /* ハッシュ表Aから文字列xの除去 */
{
	int k;
	hash *q, *r;

	k = h(x);	/* xのハッシュ函数値 */
	q = A[k];	/* バケットk内でxの探索 */
	r = NULL;
	while (NULL != q) {
		if (0 == strcmp(q->name, x)) {
			if (NULL == r) A[k] = q->next;
			else r->next = q->next;
			free(q); return;
		}
		r = q; q = q->next;
	}
	return;	/* xはAに存在せず */
}

yn member(char* x, hash** A)
{
	hash *q, *r;

	q = A[h(x)];	/* h(x)内でxの探索 */
	while (NULL != q) {
		if (0 == strcmp(q->name,x)) /* xを発見 */
			return yes;
		r = q; q = q->next;
	}
	return no;
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
