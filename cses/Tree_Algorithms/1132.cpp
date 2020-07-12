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
int depth[N], dp[N];
vector<int> g[N];

void dfs(int u, int p) {
  depth[u] = 0;
  for(int v: g[u])
    if(v != p) {
      dfs(v, u);
      depth[u] = max(depth[u], 1 + depth[v]);
    }
}

void dfs2(int u, int p, int prv) {
  dp[u] = max(depth[u], prv);
  multiset<int> ch;
  for(int v: g[u])
    if(v != p)
      ch.insert(depth[v] + 1);
  for(int i = 0; i < sz(g[u]); i++) {
    int v = g[u][i];
    if(v == p) continue;
    ch.erase(ch.find(depth[v] + 1));
    int nxt = 1 + max(prv, ch.empty() ? 0 : *ch.rbegin());
    ch.insert(depth[v] + 1);
    dfs2(v, u, nxt);
  }
}

int main()
{
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    swap(a, b);
    g[a].push_back(b);
  }
  dfs(0, -1);
  dfs2(0, -1, 0);
  for(int i = 0; i < n; i++)
    cout << dp[i] << " ";
  cout << endl;
  return 0;
}
