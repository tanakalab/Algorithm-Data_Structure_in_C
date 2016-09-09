#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
  queue<int> q;

  for (int i = 1; i <= 10; ++i)
    q.push(i);

  int n = q.size();
  printf("The size of q is %d\n", n);
  for (int i = 0; i < n; ++i) {
    printf("%d\n", q.front());
    q.pop();
  }
  return 0;
}
