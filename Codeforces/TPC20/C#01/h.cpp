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

int n, root;
int c[N];
vector<int> g[N];

bool dfs(int u, int p) {
  if(c[u]) return true;
  for(int v : g[u])
    if(v != p && dfs(v, u))
      return true;
  return false;
}

int main()
{
  cin >> n >> root;
  --root;
  for(int i = 1 ; i < n ; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  int k;
  cin >> k;
  while(k--) {
    int u; cin >> u;
    c[--u] = 1;
  }
  int ans = 0;
  for(int i = 0 ; i < sz(g[root]) ; i++)
    ans += dfs(g[root][i], root);
  cout << ans << endl;
  return 0;
}
