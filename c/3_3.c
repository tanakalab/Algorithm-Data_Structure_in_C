#include <stdio.h>
#include <stdlib.h> // for exit 
#define N 500	// 最大配列長

int deletemin(int *, int*);
void downmin(int, int *, int);
void swap(int, int, int*);
void insert(int, int*, int*);
void upmin(int, int*, int);

int main(void)
{
	// set Fig. 3.1 config
	int A[N] = {2, 7, 4, 9, 7, 4, 12, 10 , 13, 11};
	int n = 10;

	{ // print elements of the Tree A
		int i;
		for (i = 0; i < n; ++i)
			printf("A[%d] = %d\n", i, A[i]);
	}
	printf("\ndelte the minmum element in A\n");
	printf("min = %d\n\n", deletemin(A,&n));
				
	{ // print elements of the Tree A
		int i;
		for (i = 0; i < n; ++i)
			printf("A[%d] = %d\n", i, A[i]);
	}

	printf("\ninsert 5 to A\n\n");
	insert(5,A,&n);
	
	{ // print elements of the Tree A
		int i;
		for (i = 0; i < n; ++i)
			printf("A[%d] = %d\n", i, A[i]);
	}

	return 0;
}

// ヒープA[0], ..., A[n-1]から最小の要素A[0]の出力と除去; n = n-1
int deletemin(int *A, int *n)
{
	int min, n1;

	n1 = *n;	// nの値を仮置き
	if (n1 < 1)	{ // Aは空
		printf("Error: Heap is empty.\n");
		exit(1);
	}
	min = A[0];	// A[0]の出力
	A[0] = A[n1-1];	// A[n-1]の移動
	if (n1 > 1)
		downmin(0, A, n1-1);	// ヒープ条件回復のため下へ
	*n = n1-1;	// nの更新a
	return min;
}

// A[i]から下方へ，ヒープ条件回復のためのswap操作を適用
void downmin(int i, int *A, int n)
{
	int j;

	if (i < 0 || i >= n) {	// 誤りチェック
		printf("Illegal element i = %d for n = %d\n", i, n);
		exit(1);
	}
	j = 2*i+1;	// iの左の子
	//printf("j = %d, n = %d\n", j, n);
	if (j >= n) return;
	if (j+1 < n && A[j] > A[j+1]) ++j;	// jの子で小さな値を持つ方
	if (A[j] < A[i]) {
		//printf("A[%d] = %d, A[%d] = %d\n", i, A[i], j, A[j]);
		swap(i, j, A);
		downmin(j, A, n);	// jの下方へ再帰的実行
	}

	return;
}

// A[i]とA[j]の交換
void swap(int i, int j, int* A)
{
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	return ;
}

// ヒープA[0],...,A[n-1]へ新しい要素xの挿入
void insert(int x, int* A, int* n)
{
	int n1;
	n1 = *n;	// nの値を仮置き
	if (n1 >= N) {	// 誤りチェック
		printf("Error: Heap A is full.\n");
		exit(1);
	}
	A[n1] = x;	// 末尾へxを置く
	upmin(n1, A, n1+1);	// 上への修正
	*n = n1+1;
	return;
}

// A[i]から上方へ，ヒープ条件回復のためのswap操作を適用
void upmin(int i, int *A, int n)
{
	int j;

	if (i < 0 || i >= n) {	// 誤りチェック
		printf("Illegal element i = %d for n = %d\n");
		exit(1);
	}
	if (i == 0) return;	// 根へ到達すれば終了
	j = (i-1)/2;	// iの親
	if (A[j] > A[i]) {
		swap(i, j, A);
		upmin(j, A, n);	// jの上方への再帰的実行
	}
	return;
}


