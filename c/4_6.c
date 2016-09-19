// radix sort
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100	// 配列 A の最大サイズ
#define m 10	// 値の範囲は[0,1,...,m-1]
#define K 3	// 語長

struct WORD {	// 構造体 word
	int letter[K];
};
typedef struct WORD word;

struct CELL {	// 構造体 cell
	int index;
	struct CELL* next;
};
typedef struct CELL cell;

// radixsort というラベルは使えない?
void myradixsort(word*, int*, int);	
void bucketsort(word*, int*, int, int);
void insert(word*, int, cell**, int);

void set_word(word*, int, int);
void printword(word);

int main(void)
{
	word A[N];
	int idx[N];

	// 図4.5のように初期化
	int i, n = 12;
	for (i = 0; i < n; ++i)
		idx[i] = i;

	set_word(A,  0, 221);
	set_word(A,  1, 650);
	set_word(A,  2, 23);
	set_word(A,  3, 2);
	set_word(A,  4, 106);
	set_word(A,  5, 226);
	set_word(A,  6, 250);
	set_word(A,  7, 126);
	set_word(A,  8, 372);
	set_word(A,  9, 47);
	set_word(A, 10, 215);
	set_word(A, 11, 33);

	for (i = 0; i < n; ++i)
		printword(A[i]);

	return 0;
}

// 配列A[0],..,A[n-1]へ基数ソートの適用．
// 配列idx[0],..,idx[n-1]を用いて間接的に整列．
void myradixsort(word *A, int* idx, int n)
{
	int k;

	for (k = K-1; k >= 0; --k)
		bucketsort(A, idx, n, k);	// k桁毎にバケットソート

	return;
}

// A[0],..,A[n-1]をk桁目の値に従ってバケットソート（配列idx上で間接的に行う）
void bucketsort(word* A, int* idx, int n, int k)
{
	cell *B[m]; // バケット0,..,m-1
	cell *p, *q;
	int i, j;

	for (j = 0; j < m; ++j) B[j] = NULL;	// 初期化
	for (i = 0; i < n; ++i) insert(A, idx[i], B, k);	// idx[i]をBへ
	i = n-1;
	for (j = m-1; j >= 0; --j) {
		p = B[j];
		while (NULL != p) {
			idx[i] = p->index; --i;
			q = p->next; free(p); p = q;
		}
	}
}

// idxをk桁目の値A[idx].letter[k]のバケットBに挿入
void insert(word* A, int idx, cell** B, int k)
{
	cell *p;

	p = (cell*)malloc(sizeof(cell));	// 新しいポインタの獲得
	p->index = idx;	// バケットへの挿入
	p->next = B[A[idx].letter[k]];
	B[A[idx].letter[k]] = p;
}

// 教科書には載っていない main 用の自作函数
void set_word(word* A, int i, int n)
{
	int d = (int)floor(log10(n)) + 1;
	putchar('\n');
}

// 教科書には載っていない main 用の自作函数
void printword(word a)
{
	return ;
}
