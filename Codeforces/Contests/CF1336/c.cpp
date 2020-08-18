// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3013;
const int Mod = 998244353;

string s, t;
int len;
int dp[N][N];

int solve(int l, int r) {
  int idx = r - l - 1;
  if(idx >= len && l == -1)
    return sz(s) - idx + 1;
  if(idx >= sz(s))
    return 0;
  int& ret = dp[idx][l + 1];
  if(ret != -1) return ret;
  ret = 0;
  if(l >= 0 && (s[idx] == t[l] || t[l] == '#'))
    ret = (ret + solve(l - 1, r)) % Mod;
  if(r < sz(t) && (s[idx] == t[r] || t[r] == '#'))
    ret = (ret + solve(l, r + 1)) % Mod;
  return ret;
}

int main()
{
  cin >> s >> t;
  len = sz(t);
  while(sz(t) < sz(s)) t += '#';
  memset(dp, -1, sizeof dp);
  int ans = 0;
  for(int i = -1 ; i < sz(t) ; i++) {
    ans = (ans + solve(i, i + 1) % Mod) % Mod;
  }
  cout << ans << endl;
  return 0;
}
