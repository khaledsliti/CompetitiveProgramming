#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  int x = atoi(argv[2]);
  cout << n << ' '  << x << '\n';
  for (int i = 0; i < n; ++i) {
    cout << char('a' + rnd.next(0, 25));
  }
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    cout << char('a' + rnd.next(0, 25));
  }
  cout <<'\n';
  return 0;
}
