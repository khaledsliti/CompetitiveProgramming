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

int n;
vector<int> g[N], st;
int idx[N], low[N], compof[N], dfs_num;
vector<vector<int>> comp;
int ans[N];

int var(int x) {
  return x << 1;
}

int neg(int x) {
  return x ^ 1;
}

void add_or(int a, int b) {
  g[neg(a)].push_back(b);
  swap(a, b);
  g[neg(a)].push_back(b);
}

void dfs(int u) {
  idx[u] = low[u] = dfs_num++;
  st.push_back(u);
  for(int v : g[u]) {
    if(idx[v] == -1) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if(compof[v] == -1) {
      low[u] = min(low[u], low[v]);
    }
  }
  if(idx[u] == low[u]) {
    comp.push_back(vector<int>());
    while(true) {
      int t = st.back();
      st.pop_back();
      compof[t] = sz(comp) - 1;
      comp.back().push_back(t);
      if(t == u) break;
    }
  }
}

int main()
{
  int q;
  cin >> q >> n;
  for(int i = 0; i < q; i++) {
    int a, b;
    char x, y;
    cin >> x >> a >> y >> b;
    --a, --b;
    a = var(a), b = var(b);
    if(x == '-') a = neg(a);
    if(y == '-') b = neg(b);
    add_or(a, b);
  }
  memset(idx, -1, sizeof idx);
  memset(compof, -1, sizeof compof);
  for(int i = 0; i < 2 * n; i++)
    if(idx[i] == -1)
      dfs(i);
  for(int i = 0; i < n; i++)
    if(compof[var(i)] == compof[neg(var(i))])
      return cout << "IMPOSSIBLE" << endl, 0;
  memset(ans, -1, sizeof ans);
  for(int i = 0; i < sz(comp); i++) {
    int cur = 1;
    for(int v : comp[i])
      if(~ans[v])
        cur = ans[v];
    for(int v : comp[i]) {
      ans[v] = cur;
      ans[neg(v)] = !cur;
    }
  }
  for(int i = 0; i < n; i++) {
    if(ans[var(i)]) cout << "+ ";
    else cout << "- ";
  }
  cout << endl;
  return 0;
}
