#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3005;

int n;
vector<int> tree[N];
int sub[N][N], par[N][N];
long long dp[N][N];

void dfs(int root, int cur)
{
  sub[root][cur] = 1;
  for(int i = 0 ; i < sz(tree[cur]) ; i++){
    int nxt = tree[cur][i];
    if(nxt != par[root][cur]){
      par[root][nxt] = cur;
      dfs(root, nxt);
      sub[root][cur] += sub[root][nxt];
    }
  }
}

long long solve(int u, int v)
{
  if(u == v)
    return 0;
  long long& r = dp[u][v];
  if(r != -1)
    return r;
  r = 1LL * sub[u][v] * sub[v][u] + max(solve(par[v][u], v), solve(u, par[u][v]));
  return r;
}

int main()
{
  cin >> n;
  for(int i = 1 ; i < n ; i++){
    int u, v;
    cin >> u >> v;
    --u, --v;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  for(int i = 0 ; i < n ; i++){
    par[i][i] = -1;
    dfs(i, i);
  }
  memset(dp, -1, sizeof dp);
  long long best = 0;
  for(int i = 0 ; i < n ; i++)
    for(int j = i + 1 ; j < n ; j++)
      best = max(best, solve(i, j));
  cout << best << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity