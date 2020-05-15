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

const int N = 1e5 + 5;

int n, mod;
vector<int> g[N];
int ans[N], par[N], sub[N];

void dfs(int u, int p) {
  par[u] = p;
  sub[u] = 1;
  for(auto v : g[u]) {
    if(v != p) {
      dfs(v, u);
      sub[u] = (1LL * sub[u] * (1 + sub[v])) % mod;
    }
  }
}

void dfs2(int u, int p) {
  int len = sz(g[u]);
  if(len == 0) {
    ans[u] = (1 + p) % mod;
    return;
  }
  vector<int> left(len, 0), right(len, 0);
  for(int i = 0; i < len; i++) {
    int v = g[u][i], j = len - i - 1;
    int w = g[u][j];
    left[i] = (1 + sub[v]) % mod;
    right[j] = (1 + sub[w]) % mod;
    if(i > 0) {
      left[i] = (1LL * left[i] * left[i - 1]) % mod;
      right[j] = (1LL * right[j] * right[j + 1]) % mod;
    }
  }
  ans[u] = ((1LL + p) * left[len - 1]) % mod;
  for(int i = 0; i < len; i++) {
    int v = g[u][i];
    int nxt = (1 + p) % mod;
    if(i > 0) nxt = (1LL * nxt * left[i - 1]) % mod;
    if(i < len - 1) nxt = (1LL * nxt * right[i + 1]) % mod;
    dfs2(v, nxt);
  }
}

int main()
{
  cin >> n >> mod;
  for(int i = 0; i + 1 < n; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0, -1);
  for(int i = 0 ; i < n ; i++)
    if(~par[i]) {
      for(auto it = g[i].begin(); it != g[i].end(); it++)
        if(*it == par[i]) {
          g[i].erase(it);
          break;
        }
    }
  dfs2(0, 0);
  for(int i = 0; i < n; i++)
    cout << ans[i] << endl;
  return 0;
}
