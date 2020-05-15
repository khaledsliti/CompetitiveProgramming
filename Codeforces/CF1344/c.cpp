// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, m;
vector<int> g[N];
int vis[N], mn[N];
bool imp;
char sol[N];

void dfs(int u) {
  vis[u] = 1;
  mn[u] = u;
  for(int v : g[u]) {
    if(vis[v] == 0) {
      dfs(v);
      mn[u] = min(mn[u], mn[v]);
    } else if(vis[v] == 1) {
      imp = true;
    }
  }
  vis[u] = 2;
}

void dfs1(int u) {
  vis[u] = 3;
  sol[u] = 'E';
  for(int v : g[u])
    dfs1(v);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for(int i = 0 ; i < m ; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].pb(y);
  }
  imp = false;
  for(int i = 0 ; i < n ; i++) {
    if(vis[i] == 0)
      dfs(i);
  }
  if(imp) return cout << -1 << endl, 0;
  int ans = 0;
  for(int i = 0 ; i < n ; i++) {
    if(vis[i] != 3) {
      if(mn[i] < i) {
        dfs1(i);
      } else {
        ++ans;
        sol[i] = 'A';
        for(int v : g[i])
          dfs1(v);
      }
    }
  }
  cout << ans << endl;
  for(int i = 0 ; i < n ; i++)
    cout << sol[i]; cout << endl;
  return 0;
}
