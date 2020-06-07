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

const int N = 2e5 + 4;
const ll Inf = 1e18;

int n;
int a[N], b[N], c[N];
int x[N], y[N];
vector<int> g[N];
ll res = 0;

pair<int, int> solve(int u, int p) {
  int cur_x = x[u], cur_y = y[u];
  for(int v : g[u])
    if(v != p) {
      a[v] = min(a[v], a[u]);
      auto c = solve(v, u);
      cur_x += c.first;
      cur_y += c.second;
    }
  int mn = min(cur_x, cur_y);
  res += 2LL * mn * a[u];
  return {cur_x - mn, cur_y - mn};
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d", a + i, b + i, c + i);
    x[i] = c[i] == 0 && b[i] == 1;
    y[i] = c[i] == 1 && b[i] == 0;
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  auto f = solve(0, -1);
  if(f.first != f.second) cout << -1 << endl;
  else cout << res << endl;
  return 0;
}
