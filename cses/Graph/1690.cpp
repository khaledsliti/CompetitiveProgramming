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
const int N = 20;

int n;
int dp[1 << N][N];
vector<int> g[N];

int solve(int cur, int mask) {
  if(cur == n - 1) return (mask + 1 == (1 << n) ? 1 : 0);
  int& r = dp[mask][cur];
  if(r != -1) return r;
  r = 0;
  for(int nxt: g[cur]) {
    if(!(mask & (1 << nxt))) {
      r = (r + solve(nxt, mask | (1 << nxt))) % Mod;
    }
  }
  return r;
}

int main()
{
  int m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 1) << endl;
  return 0;
}
