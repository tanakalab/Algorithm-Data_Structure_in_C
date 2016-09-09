//stack ライブラリを使ってみる．

#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
  stack<int> xs;

  for (int i = 1; i <= 10; ++i)
    xs.push(i);

  int j, sum = 0, product = 1, n = xs.size();

  for (int i = 0; i < n; ++i) {
    j = xs.top();
    xs.pop();
    sum += j;
    product *= j;
    printf("j = %d, sum = %d, product = %d\n", j, sum, product);
  }
  printf("sum = %d, product = %d\n", sum, product);

  return 0;
}
