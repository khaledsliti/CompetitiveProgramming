#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5;
const int MOD = 1e9 + 7;

int n, k;
int par[N], compSz[N];

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
    compSz[b] += compSz[a];
  }
}

int myPow(int a, int b)
{
  if(!b) return 1;
  int r = myPow(a, b >> 1);
  r = (1LL * r * r) % MOD;
  if(b & 1) r = (1LL * r * a) % MOD;
  return r;
}

int main()
{
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++)
    compSz[i] = 1, par[i] = i;
  for(int i = 1 ; i < n ; i++){
    int a, b, x;
    cin >> a >> b >> x;
    if(!x)
      us(--a, --b);
  }
  int ans = myPow(n, k);
  for(int i = 0 ; i < n ; i++){
    if(fs(i) == i)
      ans = ((ans - myPow(compSz[i], k) % MOD) + MOD) % MOD;
  }
  cout << ans << endl;
  return 0;
}
