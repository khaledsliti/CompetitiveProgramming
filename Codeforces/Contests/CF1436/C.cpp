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

const int N = 1e3 + 5;
const int Mod = 1e9 + 7;

int n, x, pos;
int gt, lt;
ll C[N][N], fact[N];

int main()
{
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
    }
  }
  fact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % Mod;
  }

  cin >> n >> x >> pos;
  int l = 0, r = n;
  while(l < r) {
    int mid = (l + r) / 2;
    if(mid == pos) {
      l = mid + 1;
    } else if(mid < pos) {
      lt++;
      l = mid + 1;
    } else {
      gt++;
      r = mid;
    }
  }

  ll ans = C[x - 1][lt] * fact[lt] % Mod;
  ans = ans * C[n - x][gt] % Mod * fact[gt] % Mod;
  ans = ans * fact[n - 1 - lt - gt] % Mod;
  cout << ans << endl;
  return 0;
}
