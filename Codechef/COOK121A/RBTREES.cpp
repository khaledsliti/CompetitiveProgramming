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

const int N = 1e5 + 5;
const long long Inf = 1e18;

int n;
vector<int> g[N];
char col[N];
int lev[N], cur[N], sub[N];

void dfs(int u, int p) {
  for(int v: g[u]) {
    if(v != p) {
      lev[v] = !lev[u];
      dfs(v, u);
    }
  }
}

void dfs2(int u, int p) {
  sub[u] = col[u];
  for(int v: g[u]) {
    if(v != p) {
      dfs2(v, u);
      sub[u] += sub[v];
    }
  }
}

long long solve(int u, int p) {
  long long r = 0;
  for(int v: g[u])
    if(v != p) {
      r += solve(v, u);
      cur[u] += cur[v];
    }
  r += abs(sub[u] - cur[u]);
  return r;
}

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    g[i].clear();
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%s", col);
  for(int i = 0; i < n; i++)
    col[i] -= '0';
  lev[0] = 0;
  dfs(0, -1);
  dfs2(0, -1);
  int a = 0, b = 0, ones = 0;
  for(int i = 0; i < n; i++) {
    if(!lev[i]) a++;
    else b++;
    ones += col[i];
  }
  int zeros = n - ones;
  long long best = Inf;

  if(zeros == a) {
    for(int i = 0; i < n; i++) {
      cur[i] = lev[i];
    }
    best = min(best, solve(0, -1));
  }

  if(zeros == b) {
    for(int i = 0; i < n; i++) {
      cur[i] = !lev[i];
    }
    best = min(best, solve(0, -1));
  }

  if(best >= Inf) 
    best = -1;

  printf("%lld\n", best);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
