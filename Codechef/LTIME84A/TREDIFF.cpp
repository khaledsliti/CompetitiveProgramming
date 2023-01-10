// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 200006;
const int L = 19;
const int V = 100;

int n, q;
int arr[N];
vector<int> g[N];
int anc[N][L], lev[N];

void dfs1(int u, int p) {
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs1(v, u);
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
  for(int i = lg ; i >= 0 ; i--) {
    if(lev[a] - (1 << i) >= lev[b]) {
      a = anc[a][i];
    }
  }
  if(a == b) return a;
  for(int i = lg ; i >= 0 ; i--)
    if(anc[a][i] != anc[b][i]) {
      a = anc[a][i], b = anc[b][i];
    }
  return anc[a][0];
}

int query(int a, int b) {
  int lca = get_lca(a, b);
  int dist = lev[a] + lev[b] - 2 * lev[lca];
  if(dist >= 105) {
    return 0;
  }
  int fr[101];
  for(int i = 0; i <= 100; i++)
    fr[i] = 0;
  while(a != lca) {
    fr[arr[a]]++;
    a = anc[a][0];
  }
  while(b != lca) {
    fr[arr[b]]++;
    b = anc[b][0];
  }
  fr[arr[lca]]++;
  int best = V + 5;
  for(int i = 1; i <= V; i++) {
    if(fr[i] > 1) return 0;
    if(fr[i]) {
      int j = i + 1;
      while(j <= V && !fr[j])
        j++;
      if(j <= V)
        best = min(best, j - i);
    }
  }
  return best;
}

void solve() {
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    g[i].clear();
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  lev[0] = 0;
  dfs1(0, -1);
  while(q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    printf("%d\n", query(a, b));
  }
}

int main()
{
  int T = 1;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
