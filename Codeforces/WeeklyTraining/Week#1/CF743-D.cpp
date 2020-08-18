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

const int N = 2e5 + 5;

int n, a[N], st[N], en[N], dfs_num = 0;
vector<int> g[N];
ll sub[N], mx[N];

void dfs(int u, int p) {
  sub[u] = a[u];
  st[u] = dfs_num++;
  for(int v: g[u]) {
    if(v != p) {
      dfs(v, u);
      sub[u] += sub[v];
    }
  }
  mx[st[u]] = sub[u];
  en[u] = dfs_num;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[--x].pb(--y);
    g[y].pb(x);
  }
  dfs(0, -1);
  for(int i = n - 2; i >= 0; i--)
    mx[i] = max(mx[i], mx[i + 1]);
  ll best = LLONG_MIN;
  bool imp = true;
  for(int i = 0; i < n; i++) {
    ll cur = sub[i];
    if(en[i] < n) {
      imp = false;
      cur += mx[en[i]];
      best = max(best, cur);
    }
  }
  if(imp) cout << "Impossible" << endl;
  else cout << best << endl;
  return 0;
}
