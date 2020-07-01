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
int idx[N], low[N], dfs_idx;
int comp[N], comp_cnt;

void dfs(int cur) {
  st.push_back(cur);
  idx[cur] = low[cur] = dfs_idx++;
  for(int nxt: g[cur]) {
    if(idx[nxt] == -1) {
      dfs(nxt);
      low[cur] = min(low[cur], low[nxt]);
    } else if(comp[nxt] == -1) {
      low[cur] = min(low[cur], low[nxt]);
    }
  }
  if(low[cur] == idx[cur]) {
    while(true) {
      int t = st.back();
      st.pop_back();
      comp[t] = comp_cnt;
      if(t == cur) break;
    }
    comp_cnt++;
  }
}

int main()
{
  int m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    g[--a].pb(--b);
  }
  memset(idx, -1, sizeof idx);
  memset(comp, -1, sizeof comp);
  for(int i = 0; i < n; i++)
    if(idx[i] == -1)
      dfs(i);
  cout << comp_cnt << endl;
  for(int i = 0; i < n; i++)
    cout << comp[i] + 1 << " ";
  cout << endl;
  return 0;
}
