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
const int N = 5007;

int occ[26];
int dp[N][26];
int C[N][N];

void pre() {
  C[0][0] = 1;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
    }
  }
}

int solve(int len, int cur) {
  if(len <= 0) return 1;
  if(cur >= 26) return 0;
  int& r = dp[len][cur];
  if(r != -1) return r;
  r = 0;
  for(int take = 0; take <= occ[cur]; take++) {
    r = (r + 1LL * C[len][take] * solve(len - take, cur + 1) % Mod) % Mod;
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pre();

  string s; cin >> s;
  for(char c: s) {
    occ[c - 'a']++;
  }

  int ans = 0;
  memset(dp, -1, sizeof dp);
  for(int len = 1; len <= sz(s); len++) {
    ans = (ans + solve(len, 0)) % Mod;
  }
  cout << ans << endl;

  return 0;
}
