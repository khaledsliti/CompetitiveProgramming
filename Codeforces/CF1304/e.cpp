#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int L = 19;

int n;
int parent[N], lev[N];
int dp[N][L], dist[N][L];
vector<int> g[N];

void dfs(int u, int p)
{
	parent[u] = p;
	for(int i = 0 ; i < sz(g[u]) ; i++){
		int v = g[u][i];
		if(v != p){
			lev[v] = 1 + lev[u];
			dfs(v, u);
		}
	}
}

void preprocess()
{
	for(int i=0;i<n;i++)
		for(int j=0;(1<<j)<n;j++)
			dp[i][j] = -1, dist[i][j] = 0;

	for(int i=0;i<n;i++)
		dp[i][0] = parent[i], dist[i][0] = 1;

	for(int j=1;(1<<j)<n;j++)
		for(int i=0;i<n;i++)
			if(dp[i][j-1] != -1)
				dp[i][j] = dp[dp[i][j-1]][j-1],
        dist[i][j] = dist[i][j - 1] + dist[dp[i][j-1]][j - 1];
}

int LCA(int a,int b)
{
	if(lev[a] < lev[b])
		swap(a,b);

	int Log = 0;
	for(; (1<<Log) <= lev[a] ; Log++);
	Log--;
	
	for(int i=Log ; i >= 0 ; i--)
		if(lev[a] - (1<<i) >= lev[b])
			a = dp[a][i];

	if(a == b) return a;
	for(int i=Log ; i>=0 ; i--)
		if(dp[a][i] != dp[b][i])
			a = dp[a][i], b = dp[b][i];
	return parent[a];
}

int length(int a, int b)
{
  int lca = LCA(a, b);
  return lev[a] + lev[b] - lev[lca] - (lca ? lev[parent[lca]] : 0);
}

bool check(int len, int k)
{
  return len <= k && ((len ^ k) & 1) == 0;
}

bool solve(int x, int y, int a, int b, int k)
{
  return check(length(a, b), k) ||
    check(length(a, x) + 1 + length(y, b), k) ||
    check(length(a, x) + length(x, y) + 1 + length(x, b), k);
}

int main()
{
  scanf("%d", &n);
  for(int i = 1 ; i < n ; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    g[--a].pb(--b);
    g[b].pb(a);
  }
  dfs(0, -1);
  preprocess();
  int q;
  scanf("%d", &q);
  while(q--){
    int a, b, x, y, k;
    scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
    --x, --y, --a, --b;
    swap(x, a);
    swap(y, b);
    cout << (solve(x, y, a, b, k) || solve(y, x, a, b, k) ? "YES" : "NO") << endl;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity