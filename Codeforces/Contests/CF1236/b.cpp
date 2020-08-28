#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;

int po(int a, int b)
{
  if(!b)
    return 1;
  int r = po(a, b >> 1);
  r = (1LL * r * r) % mod;
  if(b & 1)
    r = (1LL * r * a) % mod;
  return r;
}

int main()
{
  int n, m;
  cin >> n >> m;
  cout << po(((po(2, m) - 1) + mod) % mod, n) << endl;
  return 0;
}
