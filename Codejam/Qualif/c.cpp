// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1002;

int n;
int st[N], en[N];
int g[N][N];
int ans[N];

bool dfs(int u) {
  for(int v = 0 ; v < n ; v++)
    if(g[u][v]) {
      if(ans[v] == -1) {
        ans[v] = !ans[u];
        if(!dfs(v))
          return false;
      } if(ans[v] == ans[u])
        return false;
    }
  return true;
}

void solve() {
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> st[i] >> en[i];
  for(int i = 0 ; i < n ; i++)
    for(int j = i + 1 ; j < n ; j++) {
      g[i][j] = g[j][i] = !(st[i] >= en[j] || en[i] <= st[j]);
    }
  for(int i = 0 ; i < n ; i++)
    ans[i] = -1;
  bool yes = true;
  for(int i = 0 ; i < n ; i++)
    if(ans[i] == -1) {
      ans[i] = 0;
      yes &= dfs(i);
    }
  if(!yes) cout << "IMPOSSIBLE" << endl;
  else {
    for(int i = 0 ; i < n ; i++)
      cout << (ans[i] ? 'J' : 'C');
    cout << endl;
  }
}

int main()
{
  int t, tc(1);
  cin >> t;
  while(t--) {
    printf("Case #%d: ", tc++);
    solve();
  }
  return 0;
}
