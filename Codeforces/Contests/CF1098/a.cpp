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

int n;
int par[N], lev[N];
vector<int> g[N];
int s[N], a[N];

void dfs0(int u) {
  for(int v : g[u]) {
    lev[v] = 1 + lev[u];
    dfs0(v);
  }
}

void dfs(int u) {
  if(s[u] == -1) {
    int top = s[par[u]], mn = 2e9;
    for(int v : g[u]) {
      mn = min(mn, s[v]);
    }
    if(g[u].empty())
      mn = top;
    a[u] = mn - top;
    for(int v : g[u]) {
      a[v] = s[v] - top - a[u];
    }
  }
  for(int v : g[u])
    dfs(v);
}

int main()
{
  cin >> n;
  par[0] = -1;
  for(int i = 1 ; i < n ; i++) {
    cin >> par[i];
    --par[i];
    g[par[i]].pb(i);
  }
  for(int i = 0 ; i < n ; i++) {
    cin >> s[i];
  }
  a[0] = s[0];
  dfs0(0);
  bool ok = true;
  for(int i = 0 ; i < n ; i++)
    ok &= (s[i] == -1) == (lev[i] %2 == 1);
  dfs(0);
  for(int i = 0 ; i < n ; i++)
    ok &= a[i] >= 0;
  if(!ok) cout << -1 << endl;
  else {
    long long s = 0;
    for(int i = 0 ; i < n ; i++)
      s += a[i];
    cout << s << endl;
  }
  return 0;
}
