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

void dfs_lca(int u) {
  for(int j = 1 ; j < L ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(int v: g[u]) {
    lev[v] = 1 + lev[u];
    dfs_lca(v);
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

int main()
{
  int q;
  cin >> n >> q;
  for(int i = 1; i < n; i++) {
    cin >> anc[i][0];
    anc[i][0]--;
    g[anc[i][0]].push_back(i);
  }
  anc[0][0] = -1;
  dfs_lca(0);
  while(q--) {
    int a, b;
    cin >> a >> b;
    cout << get_lca(--a, --b) + 1 << endl;
  }
  return 0;
}
