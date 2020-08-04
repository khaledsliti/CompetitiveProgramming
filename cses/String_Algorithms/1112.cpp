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

const int Mod = 1e9 + 7;

int n;
string s;
int f[1001];
int dp[1001][1001][2];

int solve(int i, int k, int t) {
  if(i >= n) return t;
  int& r = dp[i][k][t];
  if(r != -1) return r;
  r = 0;
  for(char c = 'A'; c <= 'Z'; c++) {
    int nw_k = k, nw_t = t;
    while(nw_k > 0 && c != s[nw_k])
      nw_k = f[nw_k - 1];
    if(c == s[nw_k]) nw_k++;
    if(nw_k == sz(s)) {
      nw_k = f[nw_k - 1];
      nw_t = 1;
    }
    r = (r + solve(i + 1, nw_k, nw_t)) % Mod;
  }
  return r;
}

int main()
{
  cin >> n >> s;
  for(int i = 1, k = 0; i < sz(s); i++) {
    while(k > 0 && s[i] != s[k]) k = f[k - 1];
    if(s[i] == s[k]) k++;
    f[i] = k;
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0) << endl;
  return 0;
}
