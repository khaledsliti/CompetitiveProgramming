#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 30005;

int n;
int cost[N];
vector<int> g[N];
int subsz[N], lev[N];

int chainNo;
int chainHead[N];
int chainOf[N], chainIdx[N];
vector<int> chainNodes[N];

vector<int> bit[N];
int dp[N][20];

void dfs(int u, int p)
{
  dp[u][0] = p;
  subsz[u] = 1;
  for(int i = 0 ; i < sz(g[u]); i++)
    if(g[u][i] == p){
      swap(g[u][i], g[u].back());
      g[u].pop_back();
      break;
    }
  for(auto v : g[u]){
    lev[v] = 1 + lev[u];
    dfs(v, u);
    subsz[u] += subsz[v];
  }
}

void hld(int u)
{
  chainNodes[chainNo].pb(u);
  int bigChild = -1;
  for(auto v : g[u])
    if(bigChild == -1 || subsz[bigChild] < subsz[v])
      bigChild = v;
  if(bigChild != -1){
    hld(bigChild);
  }
  for(auto v : g[u]){
    if(v != bigChild){
      chainNo++;
      hld(v);
    }
  }
}

void add(vector<int>& bit, int idx, int val)
{
  for(int i = ++idx ; i < sz(bit) ; i += i & -i)
    bit[i] += val;
}

int get(vector<int>& bit, int idx)
{
  int r = 0;
  for(int i = ++idx; i > 0 ; i -= i & -i)
    r += bit[i];
  return r;
}

int get(vector<int>& bit, int l, int r)
{
  return get(bit, r) - get(bit, l - 1);
}

int LCA(int a, int b)
{
  if(lev[a] < lev[b])
    swap(a, b);
  int l = 0;
  while((1 << l) <= n) l++; l--;
  for(int i = l ; i >= 0 ; i--)
    if(lev[a] - (1 << i) >= lev[b])
      a = dp[a][i];
  if(a == b)
    return a;
  for(int i = l; i >= 0 ; i--){
    if(dp[a][i] != dp[b][i])
      a = dp[a][i], b = dp[b][i];
  }
  return dp[a][0];
}

void pre()
{
  lev[0] = 0;
  dfs(0, -1);
  chainNo = 0;
  for(int i = 0 ; i < n ; i++){
    chainNodes[i].clear();
  }
  hld(0);
  chainNo++;
  for(int c = 0 ; c < chainNo ; c++){
    bit[c].clear();
    bit[c].resize(sz(chainNodes[c]) + 5, 0);
    for(int i = 0 ; i < sz(chainNodes[c]) ; i++){
      int u = chainNodes[c][i];
      if(i == 0)
        chainHead[c] = u;
      chainIdx[u] = i;
      chainOf[u] = c;
      add(bit[c], i, cost[u]);
    }
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 1 ; (1 << j) <= n ; j++)
      dp[i][j] = -1;
  }
  for(int j = 1 ; (1 << j) <= n ; j++){
    for(int i = 0 ; i < n ; i++){
      if(dp[i][j - 1] != -1)
        dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }
  }
}

int go_up(int u, int v)
{
  int c = chainOf[u];
  if(c == chainOf[v])
    return get(bit[c], chainIdx[v], chainIdx[u]);
  return get(bit[c], 0, chainIdx[u]) + go_up(dp[chainHead[c]][0], v);
}

int query(int u, int v)
{
  int lca = LCA(u, v);
  return go_up(u, lca) + go_up(v, lca) - cost[lca];
}

void update(int u, int val)
{
  int old = cost[u];
  add(bit[chainOf[u]], chainIdx[u], val - old);
  cost[u] = val;
}

void test()
{
  for(int i = 0 ; i < n ; i++)
    cout << dp[i][0] << " ";
  cout << endl;
  for(int i = 0 ; i < chainNo; i++){
    for(auto v : chainNodes[i])
      cout << v << " ";
    cout << endl;
  }
  for(int i = 0 ; i < n ; i++)
    cout << lev[i] << " ";
  cout << endl;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++)
      cout << LCA(i, j) << " ";
    cout << endl;
  }
}

int main()
{
  int T, tc(1);
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
      scanf("%d", cost + i);
      g[i].clear();
    }
    for(int it = 1 ; it < n ; it++){
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].pb(v);
      g[v].pb(u);
    }
    pre();
    printf("Case %d:\n", tc++);
    int q;
    scanf("%d", &q);
    while(q--){
      int t, u, v, val;
      scanf("%d", &t);
      if(t == 0){
        scanf("%d%d", &u, &v);
        printf("%d\n", query(u, v));
      }else{
        scanf("%d%d", &u, &val);
        update(u, val);
      }
    }
  }
  return 0;
}
