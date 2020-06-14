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

const int N = 100006;

int n, k, m;
vector<int> g[N];
int col[N], found = false;
vector<int> st, cycle;
int flag[N];
int idx[N];
vector<int> smallCycle;

void dfs(int u, int p) {
  if(found) return;
  st.push_back(u);
  col[u] = 1;
  for(int v : g[u]) {
    if(found) return;
    if(col[v] == 0) {
      flag[v] = !flag[u];
      dfs(v, u);
    } else if(v != p) {
      while(true) {
        cycle.push_back(st.back());
        st.pop_back();
        if(cycle.back() == v) break;
      }
      found = true;
      return;
    }
  }
  st.pop_back();
}

void reduceCycle() {
  memset(idx, -1, sizeof(idx));
  memset(col, 0, sizeof(col));
  for(int i = 0; i < sz(cycle); i++)
    idx[cycle[i]] = i;
  // for(int i = 0; i < sz(cycle); i++)
  //   cout << cycle[i] + 1 << " " << idx[cycle[i]] << endl;
  int cur = cycle[0];
  int f = 1;
  while(true) {
    col[cur] = 1;
    smallCycle.push_back(cur);
    if(smallCycle.back() == cycle.back()) break;
    int nxt = cur;
    for(int v : g[cur]) {
      if(cur == cycle[0] && v == cycle.back()) continue;
      if(idx[v] > idx[nxt]) nxt = v;
    }
    // D(nxt + 1);
    cur = nxt;
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  flag[0] = 0;
  dfs(0, -1);
  if(!found) {
    int need = (k + 1) / 2;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
      if(flag[i]) a.push_back(i);
      else b.push_back(i);
    }
    if(sz(a) < sz(b)) swap(a, b);
    cout << 1 << endl;
    for(int i = 0; i < need;i ++)
      cout << a[i] + 1 << " ";
    cout << endl;
    return 0;
  }
  reduceCycle();
  if(sz(smallCycle) <= k) {
    cout << "2\n" << sz(smallCycle) << endl;
    for(int x : smallCycle)
      cout << x + 1 << " ";
    cout << endl;
  } else {
    cout << 1 << endl;
    if(sz(smallCycle) & 1) smallCycle.pop_back();
    int need = (k + 1) / 2;
    for(int i = 0; need > 0; i += 2)
      cout << smallCycle[i] + 1 << " ", need--;
    cout << endl;
  }
  return 0;
}
