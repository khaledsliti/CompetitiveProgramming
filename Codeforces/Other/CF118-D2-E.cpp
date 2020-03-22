// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, m, dfs_idx;
int low[N], idx[N];
bool noSolution = false;
vector<int> g[N];
vector<array<int, 2>> sol;

void dfs(int u, int p) {
  low[u] = idx[u] = ++dfs_idx;
  for(int i = 0 ; i < sz(g[u]) ; i++) {
    int v = g[u][i];
    if(idx[v] == 0) {
      sol.push_back({u + 1, v + 1});
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if(low[v] > idx[u])
        noSolution = true;
    } else if(v != p) {
      low[u] = min(low[u], idx[v]);
      if(idx[v] < idx[u])
        sol.push_back({u + 1, v + 1});
    }
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < m ; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0, -1);
  if(noSolution) printf("0\n");
  else {
    for(int i = 0 ; i < (int) sol.size() ; i++)
      printf("%d %d\n", sol[i][0], sol[i][1]);
  }
  return 0;
}
