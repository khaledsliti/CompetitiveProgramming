// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int Mod = 998244353;
const int N = 51;

int n, k;
int a[N][N];
int par[2 * N], siz[2 * N];
ll fact[2 * N];

int fs(int x) {
  return x == par[x] ? x : par[x] = fs(par[x]);
}

void us(int a, int b) {
  a = fs(a), b = fs(b);
  if(a != b) {
    par[a] = b;
    siz[b] += siz[a];
  }
}

int main()
{
  fact[0] = 1;
  for(int i = 1; i < 2 * N; i++) {
    fact[i] = fact[i - 1] * i % Mod;
  }
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < 2 * n; i++) {
    par[i] = i;
    siz[i] = 1;
  }
  for(int j = 0; j < n; j++) {
    for(int jj = j + 1; jj < n; jj++) {
      bool can = 1;
      for(int i = 0; i < n; i++) {
        if(a[i][j] + a[i][jj] > k) {
          can = 0;
        }
      }
      if(can) {
        us(j + n, jj + n);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int ii = i + 1; ii < n; ii++) {
      bool can = 1;
      for(int j = 0; j < n; j++) {
        if(a[i][j] + a[ii][j] > k) {
          can = 0;
        }
      }
      if(can) {
        us(i, ii);
      }
    }
  }
  ll ans = 1;
  for(int i = 0; i < 2 * n; i++) {
    if(fs(i) == i) {
      ans *= fact[siz[i]];
      ans %= Mod;
    }
  }
  cout << ans << endl;
  return 0;
}
