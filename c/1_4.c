/* p.7 Euclidean Algorithm */

#include <stdio.h> /* 標準入出力のヘッダファイルの読み込み */
#include <stdlib.h> /* 標準ライブラリの読み込み */

/* 函数の宣言 */
int gcd(int a0, int a1);

/* メインプログラム：最大公約数計算のためのデータの入出力 */
int main(void)
{
  int a0, a1, temp;	/* 変数の宣言 */

  printf("Type in the first integer: "); /* a0 の入力を指示 */
  scanf("%d", &a0);	/*  キーボードから a0 の入力 */
  printf("a0 = %d\n", a0); /* a0の出力 */
  printf("Type in the second integer: "); /* a1 の入力を指示 */
  scanf("%d", &a1);	/*  キーボードから a1 の入力 */
  printf("a1 = %d\n", a1); /* a1の出力 */

  if (a0 <= 0 || a1 <= 0) { /* 正性のチェック */
    printf("Illegal input number\n");
    exit(1);
  }
  if (a0 < a1) { /* a0 ≧ a1 に正規化 */
    temp = a0; 
    a0 = a1;
    a1 = temp;
  }

  printf("GCD(%d,%d) = %d\n", a0, a1, gcd(a0,a1)); /* 最大公約数の計算と出力 */

  return(0);	/* 終了 */
}

int gcd(int a0, int a1) /* ユークリッドの互除法：a0 と a1 の最大公約数の計算 */
{
  int a, b, temp;	/* 変数の宣言 */

  a = a0; b = a1;	/* 初期設定 */
  while (b != 0) {	/* 互除法の反復 */
    temp = a % b;
    a = b;
    b = temp;
  }
  return (a);	/* 計算結果を返す */
}
