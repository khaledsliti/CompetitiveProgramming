#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int a, b;
  cin >> a >> b;
  cout << max(max(a + b, a - b), a * b) << endl;
  return 0;
}
