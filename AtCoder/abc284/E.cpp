// RedStone
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

const int N = 2e5 + 5;

int n, m;
vector<int> g[N];
int vis[N];
int ans;

void dfs(int u) {
  if (ans >= 1e6) {
    return;
  }
  ans++;
  vis[u] = 1;
  for(int v: g[u]) {
    if(vis[v]) {
      continue;
    }
    dfs(v);
  }
  vis[u] = 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    swap(a, b);
    g[a].pb(b);
  }

  dfs(0);
  cout << ans << endl;
  return 0;
}
