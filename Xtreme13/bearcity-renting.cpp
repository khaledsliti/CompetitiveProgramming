#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5, E = 4e5 + 5;
const int L = 21;

int n, m;
int par[N];
int dp[N][L], lev[N];
vector<pair<int, pair<int, int>>> edges, extra;

int e;
int head[N], nxt[E], cost[E], to[E], fr[E];
int par_edge[N], children[N], is_bad[E];

vector<int> add[N], del[N];

int fs(int x)
{
  return x == par[x] ? x : par[x] = fs(par[x]);
}

void add_edge(int f, int t, int c)
{
  nxt[e] = head[f];
  head[f] = e;
  fr[e] = f;
  to[e] = t;
  cost[e] = c;
  c++;
}

void add_bi_edge(int a, int b, int c)
{
  add_edge(a, b, c);
  add_edge(b, a, c);
}

void dfs(int u, int p)
{
  dp[u][0] = p;
  children[u] = 0;
  for(int k = head[u] ; ~k ; k = nxt[k]){
    int v = to[k];
    if(v != p){
      lev[v] = 1 + lev[u];
      par_edge[v] = k;
      dfs(v, u);
      children[u]++;
    }
  }
}

int lca(int a, int b)
{
  if(lev[a] < lev[b])
    swap(a, b);
  int Log = 0;
  for(; (1 << Log) <= lev[a] ; Log++);
	Log--;
  for(int i = Log ; i >= 0 ; i--)
		if(lev[a] - (1<<i) >= lev[b])
			a = dp[a][i];
  if(a == b) return a;
  for(int i = Log ; i >= 0 ; i--)
		if(dp[a][i] != dp[b][i])
			a = dp[a][i], b = dp[b][i];
	return dp[a][0];
}

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    par[i] = i, head[i] = -1;
  for(int i = 0 ; i < m ; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges.pb({c, {--a, --b}});
  }
  sort(all(edges));
  reverse(all(edges));
  while(sz(edges)){
    int a = edges.back().second.first;
    int b = edges.back().second.second;
    int c = edges.back().first;
    a = fs(a);
    b = fs(b);
    if(a != b){
      add_bi_edge(a, b, c);
    }else{
      extra.push_back(edges.back());
    }
    edges.pop_back();
  }
  dfs(0, -1);
  for(int j = 1 ; (1 << j) < n ; j++)
    for(int i = 0 ; i < n ; i++)
      if(dp[i][j - 1] != -1)
        dp[i][j] = dp[dp[i][j - 1]][j - 1];
  for(auto edge : extra){
    int a = edge.second.first;
    int b = edge.second.second;
    int c = edge.first;
    int p = lca(a, b);
    add[a].push_back(c);
    add[b].push_back(c);
    del[p].push_back(c);
  }
  return 0;
}
