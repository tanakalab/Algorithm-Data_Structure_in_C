// merge sort

#include <stdio.h>

#define N 100

void merge(int*, int, int*, int, int, int*);
void mergesort(int i, int j, int* A);

int main(void)
{
  int A[4] = { 3, 5, 41, 44 };
  int B[4] = { 1, 4, 40, 129 };
  int C[8];

  merge(A, 4, B, 4, 0, C);
  int i;
  for (i = 0; i < 8; ++i)
    printf("C[%d] = %d\n", i, C[i]);

  int D[] = { 3, 2, 0, 5, 8, 3, 4, 1, 3, 2 };

  int E[] = {
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

  int n = sizeof D / sizeof D[0];
  mergesort(0, n-1, D);
  putchar('\n');
  for (i = 0; i < n; ++i)
    printf("D[%2d] = %d\n", i, D[i]);

  return 0;
}

// 整列配列A[0],..,A[nA-1]とB[0],..,B[nB-1]を併合し整列配列C[i],..,C[i+nA+nB-1]に入れる
void merge(int* A, int nA, int* B, int nB, int i, int* C)
{
  int iA, iB, iC;	// iAはAの添字，iBはBの添字，iCは合計

  iA = iB = iC = 0;	// 併合の開始
  while (iC <= nA+nB-1) {
    if (iA >= nA) {	// Aは既に空
      C[i+iC] = B[iB];
      ++iB;
    }
    else {
      if (iB >= nB) {	// Bは既に空
	C[i+iC] = A[iA];
	++iA;
      }
      else {	// A[iA]とB[iB]の小さい方をCへ
	if (A[iA] < B[iB]) {
	  C[i+iC]	= A[iA];
	  ++iA;
	}
	else {
	  C[i+iC] = B[iA];
	  ++iB;
	}
      }
    }
    ++iC;
  }
}

// 配列A[0],..,A[n-1]をマージソートにより整列
void mergesort(int i, int j, int *A)
{
  int k, n, n1, n2, mid;

  n = j-i+1;	// 配列のサイズ
  if (n > 1) {
    mid = i+(n-1)/2;	// 中央値により分割
    mergesort(i, mid, A);	// 前半の整列
    mergesort(mid+1, j, A);	// 後半の整列
    n1 = mid-i+1;
    int A1[n1]; 
    for (k = i; k <= mid; ++k)
      A1[k-i] = A[k];	// A1は前半の部分配列
    n2 = j-mid;
    int A2[j-mid];
    for (k = mid+1; k <= j; ++k)
      A2[k-mid-1] = A[k];	// A2は後半の部分配列
    merge(A1, n1, A2, n2, i, A);	// 併合
  }
}
