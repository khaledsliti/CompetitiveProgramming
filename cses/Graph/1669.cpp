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

const int N = 1e5 + 5;

int n, m;
vector<int> g[N], st, cycle;
int vis[N], found;

void dfs(int u, int p) {
  if(found) return;
  if(vis[u]) {
    found = true;
    while(true) {
      int cur = st.back();
      st.pop_back();
      cycle.push_back(cur + 1);
      if(cur == u) break;
    }
    return;
  }
  vis[u] = 1;
  st.push_back(u);
  for(int v : g[u]) {
    if(v == p) continue;
    dfs(v, u);
    if(found) break;
  }
  st.pop_back();
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  for(int i = 0; i < n; i++)
    if(!vis[i])
      dfs(i, i);
  if(!found) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << sz(cycle) + 1 <<  endl;
    for(int i = 0; i < sz(cycle); i++)
      cout << cycle[i] << " ";
    cout << cycle[0] << endl;
  }
  return 0;
}
