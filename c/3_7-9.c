/* binary tree */
#include <stdio.h>
#include <stdlib.h>

typedef enum { yes, no } yn;	// 列挙型データyn

struct NODE {	// 構造体node
  int element;
  struct NODE* left;
  struct NODE* right;
};
typedef struct NODE node;

void insert(int, node**);
yn member(int, node*);
int min(node*);
node* off(node*);
void delete(int, node**);
void print_tree(node*);

// 2分探索木の処理のテストプログラム
int main(void)
{
  node* init;	// 根へのポインタ
  yn a;
  int x;

  init = NULL;	// initの初期化
  // 2分探索木データの入力
  x = 13; insert(x, &init);	// 要素xの挿入
  x = 14; insert(x, &init);	// 要素xの挿入
  x = 8; insert(x, &init);	// 要素xの挿入
  x = 15; insert(x, &init);	// 要素xの挿入
  x = 11; insert(x, &init);	// 要素xの挿入
  x = 12; insert(x, &init);	// 要素xの挿入
  x = 9; insert(x, &init);	// 要素xの挿入
  x = 10; insert(x, &init);	// 要素xの挿入
  a = member(x, init);
  x = min(init);
  printf("min = %d\n", x);
  print_tree(init);
  delete(8, &init);
  x = min(init);
  printf("\nmin = %d\n", x);
  print_tree(init);
	
  return 0;
}

// ポインタ*pが指す2分探索木にxを挿入し，*pを更新
void insert(int x, node** p)
{
  node *q, **r;	// qはポインタ，rはその親

  r = p; q = *r;	// rとqを初期化
  while (NULL != q) {
    if (q->element == x) return;	// xは既に存在
    if (q->element < x) {	// 右の子へ
      r = &(q->right);	q = q->right;
    }
    else	{	// 左の子へ
      r = &(q->left);	q = q->left;
    }
  }
  // *pの指す木が空ならば，*rと*pは同じところを指す
  *r = (node*)malloc(sizeof(node));	// xを入れる場所
  (*r)->element = x;
  (*r)->left = NULL;
  (*r)->right = NULL;
  return;
}

// pが指す2分探索木にxの存在を判定
yn member(int x, node* p)
{
  node* q;

  q = p;	// 根initから探索開始
  while (NULL != q) {
    if (q->element == x) return yes;	// xを発見
    if (q->element < x) q = q->right;
    else	q = q->left;
  }
  return no;	// x存在せず

}

// pが指す2分探索木の最小要素を出力
int min(node* p)
{
  node *q, *r;	// qは探索中のポインタ，rはその親
  q = p;	// 根から左端の路を下がる
  if (NULL == q) {	// 木は空（誤り）
    printf("Error: Tree is empty.\n");
    exit(1);
  }
  while (NULL != q)	{
    r = q; q = q->left;
  }
  return r->element;	// 結果を返す
}

// ポインタ*pが指す2分探索木から要素xを除去し，*pの更新
void delete(int x, node** p)
{
  node *q, **r;	// qは探索中のポインタ，rはその親

  r = p; q = *r;	// 根からの探索開始
  while (NULL != q) {
    if (q->element == x) {	// xを発見
      *r = off(q);	// xのセルqを除去し，qの部分木を更新
      return;	// 終了
    }
    // 探索を続ける
    if (q->element < x) { r = &(q->right); }
    else { r = &(q->left); }
    q = *r;
  }
  return ;	// xは存在せず
}

// ポインタpが指す接点を除去，pの部分木を更新，根へのポインタを返す
node* off(node* p)
{
  node *q, **r;	// qは探索中のポインタ，rはその親

  if (NULL == p->left && NULL == p->right) {	// pの子は共に空
    free(p); return NULL;
  }
  if (NULL == p->left) {	// pの左の子が空
    q = p->right; free(p); return q;
  }
  if (NULL == p->right) {	// pの右の子が空
    q = p->left; free(p); return q;
  }
  r = &(p->right);	// pの子は共に存在
  q = *r;	// 右の部分木の最小要素を探索
  while (NULL != q->left) {
    r = &(q->left);	q = q->left;
  }
  *r = off(q);	// 最小要素qの除去；再帰的実行
  return p;
}

// 木を中順でなぞる
void print_tree(node* p)
{
  if (NULL == p)
    return;
  print_tree(p->left);
  printf("%2d\n", p->element);
  print_tree(p->right);

}
