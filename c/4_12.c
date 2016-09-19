// select

#include <stdio.h>
#include <stdlib.h>

void swap(int, int, int*);
int partition(int, int, int, int*);
void bubblesort(int, int, int*);
int select(int, int, int, int*);

int main(void)
{
  int A[] = { 
      3, 734, 305, 782, 436,
    660, 251, 713, 206, 606,
    288, 280, 689, 254, 223,
    768, 609, 123, 719, 170,
    457, 624, 842, 498, 486,
     41, 550, 774, 619, 463,
    865, 680, 843, 151, 898,
    503,  19, 497, 233,  44,
    685, 964, 367, 743, 610,
    905, 465, 947, 811, 124,
    59,  665, 294, 341, 153,
    640, 362, 962, 160, 710,
    981,  49, 445, 631, 469,
     10, 770, 872, 588, 943,
    492, 135,  84, 884, 336,
    775, 431, 164, 173,  73,
    851, 224, 951, 789, 241,
    805, 250, 411, 232, 419,
    194, 274, 839, 959, 529,
    663, 652, 836, 540, 760
  };
  int n = sizeof A / sizeof A[0];
  printf("size of A = %d\n", n);
  printf("%d\n", select(0,n-1,(n-1)/3,A));
  int i;
  bubblesort(0, n-1, A);
  for (i = 0; i < n; ++i)
    printf("A[%d] = %d\n", i, A[i]);
  return 0;
}

// A[i]とA[j]の交換
void swap(int i, int j, int* A)
{
  int temp;

  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

// A[i],...,A[j]を軸要素aによって分割
// 前半はA[i],..,A[k-1]<a, 後半はA[k],..,A[j]>=aを満たす．
// このkを出力する．
int partition(int i, int j, int a, int* A)
{
  int l, r, k;

  l = i; r = j;	// lは左から，rは右から
  while (1) {
    while (A[l] < a) ++l;
    while (A[r] >= a) --r;
    if (l <= r) {	// A[l]とA[r]の交換
      swap(l, r, A); 
      ++l; --r;
    }
    else	// 終了
      break;
  }
  k = l;
  return k;
}

// A[h],..,A[k]の要素をバブルソートによって整列
void bubblesort(int h, int k, int* A)
{
  int i, j;
  int test;	// test==1 既に整列済み

  for (i = h; i < k; ++i) {
    test = 1;
    for (j = k; j >= i+1; --j)
      if (A[j] < A[j-1]) {
	swap(j, j-1, A);
	test = 0;
      }
    if (test == 1) return;
  }
}

// 配列A[i],..,A[j]からp番目の大きさの要素を返す
int select(int i, int j, int p, int*A)
{
  int m, a, h, k;
	
  if (j-i+1 < 50) {	// Aのサイズが小さい場合
    bubblesort(i, j, A);
    return A[i+p-1];
  }
  else {	// Aのサイズが大きい場合
    m = (j-i+1)/5;
    for (h=0; h<m; ++h) {	// 5要素ずつmグループに分割
      bubblesort(i+5*h, i+5*h+4, A);
      swap(i+h, i+5*h+2, A);	// 各グループの中央値を先頭へ
    }
    a = select(i, i+m-1, (j-i+6)/10, A);	// a: m個の中央値の中央値
    k = partition(i, j, a, A);	// aによって分割
    if (p <= k-i)
      return select(i, k-1, p, A);
    else
      return select(k, j, p-k+1, A);
  }
}

