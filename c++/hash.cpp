// unordered_setを使ってみる
//
// g++ -std=c++0x hash.cpp

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
  unordered_set<int> A;

  for (int i = 0; i < 9; ++i)
    A.insert(i*i);

  for (auto it = A.begin(); it != A.end(); ++it) {
    cout << *it << endl;
  }

  auto it = A.find(48);
  if (it == A.end())
    printf("48 isn't in A\n");
  else
    printf("48 is in  A\n");

  return 0;
}
