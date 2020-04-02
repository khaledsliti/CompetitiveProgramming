// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100007;

int n, root;
int par[N], val[N];
array<int, 2> g[N];
set<int> found;

void dfs(int u, int mn, int mx) {
  if(val[u] >= mn && val[u] <= mx)
    found.insert(val[u]);
  if(~g[u][0])
    dfs(g[u][0], mn, min(mx, val[u]));
  if(~g[u][1])
    dfs(g[u][1], max(mn, val[u]), mx);
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    par[i] = -1;
  for(int i = 0 ; i < n ; i++) {
    scanf("%d%d%d", val + i, &g[i][0], &g[i][1]);
    if(~g[i][0]) par[--g[i][0]] = i;
    if(~g[i][1]) par[--g[i][1]] = i;
  }
  for(int i = 0 ; i < n ; i++)
    if(par[i] == -1)
      root = i;
  dfs(root, 0, 1e9);
  int ans = 0;
  for(int i = 0 ; i < n ; i++)
    if(found.find(val[i]) == found.end())
      ans++;
  cout << ans << endl;
  return 0;
}
