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

const int N = 3005;
const int Mod = 1e9 + 7;

int n;
string s;
int p[N], C[N][N];
int dp[N][N];

int solve(int l, int r) {
  if(l >= r) return 1;
  int& ret = dp[l][r];
  if(ret != -1) return ret;
  ret = 0;
  for(int i = l; i <= r; i++) {
    bool p = true;
    if(i != r) p &= s[i] == '<';
    if(i != l) p &= s[i - 1] == '<';
    if(p) {
      ret += (1LL * C[r - l][i - l] * solve(l, i - 1) % Mod * solve(i + 1, r) % Mod) % Mod;
      ret %= Mod;
    }
  }
  return ret;
}

int main()
{
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
    }
  }
  cin >> n >> s;
  cout << s << endl;
  p[0] = s[0] == '>';
  p[n - 1] = s[n - 2] == '<';
  for(int i = 1; i < n - 1; i++) {
    p[i] = (s[i - 1] == '<' && s[i] == '>');
  }
  for(int i = 0 ; i < n ; i++)
    cout << p[i] << " ";
  cout << endl;
  memset(dp, -1, sizeof dp);
  D(solve(0, 0));
  D(solve(2, 3));
  cout << solve(0, n - 1) << endl;
  return 0;
}
