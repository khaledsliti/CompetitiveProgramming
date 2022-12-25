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

const int S = 3e5 + 3007;
const int T = 3007;

int s, t, m;
vector<int> g[S];
int dp[T][T];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s >> t >> m;

  while(m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v - s);
  }

  memset(dp, -1, sizeof dp);

  for(int i = 0; i < s; i++) {
    for(int x: g[i]) {
      for(int y: g[i]) {
        if(x == y) continue;
        if(dp[x][y] != -1) {
          cout << i + 1 << " " << s + x + 1 << " " << s + y + 1 << " " << dp[x][y] + 1 << endl;
          return 0;
        }
        dp[x][y] = i;
      }
    }
  }

  cout << -1 << endl;
  return 0;
}
