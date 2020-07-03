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

int n, m;
vector<int> g[N], st;
int gold[N];
int idx[N], low[N], dfs_num;
int compof[N], ncomp;
ll cost[N], ans[N];
vector<int> dag[N];

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
    while(true) {
      int t = st.back();
      st.pop_back();
      compof[t] = ncomp;
      cost[ncomp] += gold[t];
      if(t == u) break;
    }
    ncomp++;
  }
}

void dfs2(int u) {
  if(ans[u] != -1)
    return;
  ans[u] = cost[u];
  for(int v: dag[u]) {
    dfs2(v);
    ans[u] = max(ans[u], cost[u] + ans[v]);
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> gold[i];
  while(m--) {
    int a, b;
    cin >> a >> b;
    g[--a].pb(--b);
  }
  memset(idx, -1,sizeof idx);
  memset(compof, -1,sizeof compof);
  for(int i = 0; i < n; i++)
    if(idx[i] == -1)
      dfs(i);
  for(int i = 0; i < n; i++) {
    for(int j: g[i]) {
      if(compof[i] != compof[j]) {
        dag[compof[i]].pb(compof[j]);
      }
    }
  }
  memset(ans, -1, sizeof ans);
  for(int i = 0; i < ncomp; i++)
    dfs2(i);
  ll best = 0;
  for(int i = 0; i < ncomp; i++) {
    best = max(best, ans[i]);
  }
  cout << best << endl;
  return 0;
}
