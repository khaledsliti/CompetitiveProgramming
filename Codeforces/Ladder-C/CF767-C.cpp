// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1000005;

int n, root;
int par[N], t[N];
vector<int> g[N];
int st[N], en[N], val[N], cur_idx, sub[N], node[N];
int dp[N];

void dfs(int u) {
  st[u] = cur_idx++;
  sub[u] = t[u];
  for(int v : g[u]) {
    dfs(v);
    sub[u] += sub[v];
  }
  en[u] = cur_idx - 1;
}

// Check s = 0
int main()
{
  scanf("%d", &n);
  int s = 0;
  for(int i = 0 ; i < n ; i++) {
    scanf("%d%d", &par[i], &t[i]);
    --par[i];
    if(~par[i])
      g[par[i]].pb(i);
    else
      root = i;
    s += t[i];
  }
  if(s % 3)
    return cout << -1 << endl, 0;

  dfs(root);
  for(int i = 0 ; i < n ; i++) {
    val[st[i]] = sub[i];
    node[st[i]] = i;
  }

  dp[n] = n;
  for(int i = n - 1 ; i >= 0 ; i--) {
    if(val[i] == s / 3)
      dp[i] = i;
    else
      dp[i] = dp[i + 1];
  }


  for(int i = 0 ; i < n ; i++) {
    if(i == root) continue;
    if(sub[i] == s / 3) {
      int b = en[i] + 1;
      if(dp[b] < n) {
        int j = node[dp[b]];
        cout << i + 1 << "  " << j + 1 << endl;
        return 0;
      }
    } else if (sub[i] == s / 3 * 2 && st[i] != en[i]) {
      if(dp[st[i] + 1] <= en[i]) {
        cout << i + 1 << " " << node[dp[st[i] + 1]] + 1 << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
  return 0;
}
