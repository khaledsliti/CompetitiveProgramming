// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;
const int L = 18;

int n;
vector<int> g[N];
int anc[N][L], lev[N];

void dfs_lca(int u, int p) {
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs_lca(v, u);
    }
  }
}

int get_lca(int a, int b)
{
  if(lev[a] < lev[b])
    swap(a,b);
  int lg = 0;
  for(; (1 << lg) <= lev[a] ; lg++);
  lg--;
  for(int i = lg ; i >= 0 ; i--)
    if(lev[a] - (1 << i) >= lev[b])
      a = anc[a][i];
  if(a == b) return a;
  for(int i = lg ; i >= 0 ; i--)
    if(anc[a][i] != anc[b][i])
      a = anc[a][i], b = anc[b][i];
  return anc[a][0];
}

int solve(int a, int b) {
  int lca = get_lca(a, b);
  return lev[a] + lev[b] - 2 * lev[lca];
}

int main()
{
  int q;
  cin >> n >> q;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].pb(--b);
    g[b].pb(a);
  }
  dfs_lca(0, -1);
  while(q--) {
    int a, b;
    cin >> a >> b;
    cout << solve(--a, --b) << endl;
  }
  return 0;
}
