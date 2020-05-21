// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n, x, y;
vector<int> g[N];
int sub[N], par[N];

void dfs(int u, int p) {
  sub[u] = 1;
  par[u] = p;
  for(int i = 0 ; i < sz(g[u]) ; i++) {
    int v = g[u][i];
    if(v == p) continue;
    dfs(v, u);
    sub[u] += sub[v];
  }
}

int main()
{
  scanf("%d%d%d", &n, &x, &y); --x, --y;
  for(int i = 1 ; i < n ; i++) {
    int a, b;
    scanf("%d%d", &a, &b); --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(x, -1);
  long long tot = 1LL * n * (n - 1);
  long long a = sub[y];
  while(par[y] != x)
    y = par[y];
  a *= n - sub[y];
  cout << tot - a << endl; 
  return 0;
}
