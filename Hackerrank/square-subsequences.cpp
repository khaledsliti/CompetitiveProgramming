// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 201;
const int Mod = 1000000007;

int n;
string s, a, b;
int dp[N][N];

int solve(int i, int j) {
  if(i >= sz(a) || j >= sz(b)) return 0;
  int& r = dp[i][j];
  if(r != -1) return r;
  r = 0;
  if(a[i] == b[j]) {
    r = 1 + solve(i + 1, j + 1);
  }
  r += ((solve(i + 1, j) + solve(i, j + 1)) % Mod - solve(i + 1, j + 1)) % Mod;
  r = (r + Mod) % Mod;
  return r;
}

void solve() {
  cin >> s;
  n = sz(s);
  int ans = 0;
  for(int i = 0; i < n - 1; i++) {
    a = s.substr(0, i + 1);
    b = s.substr(i + 1);
    memset(dp, -1, sizeof dp);
    for(int j = 0; j < sz(a); j++) {
      if(a[j] == b[0]) {
        ans = (ans + 1 + solve(j + 1, 1)) % Mod;
      }
    }
  }
  cout << ans << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
