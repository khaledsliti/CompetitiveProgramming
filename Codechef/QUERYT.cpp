#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 4e4 + 5;
const int V = 205;
const int L = 18;

int n;
int arr[N];
vector<int> tr[N];
int par[N][L], lev[N];
int lg[N];
bool good[V][V];
int dp[V][N];

void add_edge(int a, int b)
{
  tr[a].pb(b);
  tr[b].pb(a);
}

void dfs(int u)
{
  for(auto v : tr[u]){
    if(v != par[u][0]){
      par[v][0] = u;
      lev[v] = 1 + lev[u];
      dfs(v);
    }
  }
}

int lca(int a, int b)
{
  if(lev[a] < lev[b])
    swap(a, b);
  for(int j = lg[n] ; j >= 0 ; j--)
    if(lev[a] - (1 << j) >= lev[b])
      a = par[a][j];
  if(a == b)
    return a;
  for(int j = lg[n] ; j >= 0 ; j--)
    if(par[a][j] != par[b][j])
      a = par[a][j], b = par[b][j];
  return par[a][0];
}

int solve(int u, int v)
{
  int cur_lca = lca(u, v);
  int key = arr[cur_lca];
  return dp[key][u] + dp[key][v] - dp[key][cur_lca] - (par[cur_lca][0] == -1 ? 0 : dp[key][par[cur_lca][0]]);
}

int main()
{
  for(int i = 1 ; i < V ; i++)
    for(int j = 1 ; j < V ; j++)
      good[i][j] = __gcd(i, j) != 1;
  lg[1] = 0;
  for(int i = 2 ; i < N ; i++)
    lg[i] = lg[i >> 1] + 1;

  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", &arr[i]);
  for(int i = 0 ; i < n - 1 ; i ++){
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(--u, --v);
  }

  memset(par, -1, sizeof par);
  dfs(0);

  for(int j = 1 ; (1 << j) < n ; j++)
    for(int i = 0 ; i < n ; i++)
      if(~par[i][j - 1])
        par[i][j] = par[par[i][j - 1]][j - 1];

  queue<int> q;
  q.push(0);
  for(int val = 1 ; val < V ; val++)
    dp[val][0] = good[val][arr[0]];
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v : tr[u]){
      if(v != par[u][0]){
        q.push(v);
        for(int val = 1 ; val < V ; val++)
          dp[val][v] = dp[val][u] + good[val][arr[v]];
      }
    }
  }

  int qs;
  scanf("%d", &qs);
  while(qs--){
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", solve(--u, --v));
  }
  return 0;
}
