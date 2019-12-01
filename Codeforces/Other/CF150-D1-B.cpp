#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2005;
const int mod = 1e9 + 7;

int n, m, k, comp;
int par[N];

int fs(int x)
{
  return x == par[x] ? x : par[x] = fs(par[x]);
}

void us(int a, int b)
{
  a = fs(a);
  b = fs(b);
  if(a != b){
    par[a] = b;
    comp--;
  }
}
int main()
{
  while(cin >> n >> m >> k){
    comp = n;
    for(int i = 0 ; i < n ; i++)
      par[i] = i;
    for(int i = 0 ; i < n - k + 1 ; i++){
      int l = i, r = i + k - 1;
      while(l < r)
        us(l++, r--);
    }
    int ans = 1;
    for(int i = 1 ; i <= comp ; i++)
      ans = (1LL * ans * m) % mod;
    cout << ans << endl;
  }
  return 0;
}
