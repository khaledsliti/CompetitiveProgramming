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

const int N = 1003;
const int Mod = 1e9 + 7;

int solve(int i, int sum, const string& s, vector<vector<int>>& dp) {
  if(i >= sz(s)) return sum == 0;
  int& r = dp[i][sum];
  if(r != -1) return r;
  r = solve(i + 1, sum, s, dp);
  int v = s[i] == '(' ? 1 : -1;
  if(sum + v >= 0) {
    r = (r + solve(i + 1, sum + v, s, dp)) % Mod;
  }
  return r;
}

void solve() {
  string s;
  cin >> s;
  vector<vector<int>> dp(sz(s), vector<int>(sz(s) + 1, -1));
  cout << ((solve(0, 0, s, dp) - 1) + Mod % Mod) << endl; 
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef LOCAL
  freopen("balancing.in", "r", stdin);
#endif

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}