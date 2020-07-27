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

const int N = 1000007;

struct Tree {
  int pos, height;
  bool operator<(const Tree& other) const {
    return pos < other.pos;
  }
};

int n;
Tree tr[N];
vector<int> g[N];
ll dp[N];
int in[N];

void dfs(int u) {
  assert(dp[u] == -1);
  dp[u] = tr[u].height;
  for(int v: g[u]) {
    dfs(v);
    dp[u] = max(dp[u], tr[u].height + dp[v]);
  }
}

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &tr[i].pos, &tr[i].height);
    g[i].clear();
    in[i] = 0;
  }
  sort(tr, tr + n);
  for(int i = 0; i < n; i++) {
    int par = lower_bound(tr, tr + n, (Tree){tr[i].pos - tr[i].height, 0}) - tr;
    if(par < n && tr[par].pos == tr[i].pos - tr[i].height) {
      g[par].push_back(i);
      in[i] = 1;
    }
  }
  memset(dp, -1, n * sizeof(dp[0]));
  for(int i = 0; i < n; i++)
    if(in[i] == 0)
      dfs(i);
  map<int, ll> left_series;
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, dp[i]);
    left_series[tr[i].pos - tr[i].height] = max(left_series[tr[i].pos - tr[i].height], dp[i]);
  }
  for(int i = n - 1; i >= 0; i--) {
    dp[i] = tr[i].height + left_series[tr[i].pos + tr[i].height];
    int nxt = lower_bound(tr, tr + n, (Tree){tr[i].pos + tr[i].height, 0}) - tr;
    if(nxt < n && tr[nxt].pos == tr[i].pos + tr[i].height) {
      dp[i] = max(dp[i], tr[i].height + dp[nxt]);
    }
    ans = max(ans, dp[i]);
  }
  printf("%lld\n", ans);
}

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--) {
    printf("Case #%d: ", tc++);
    solve();
  }
  return 0;
}
