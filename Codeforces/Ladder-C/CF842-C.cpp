// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int a[N], ans[N], cnt[N];
vector<int> g[N], dv[N];

void dfs(int u, int p, int cur_gcd, int lev) {
  ans[u] = cur_gcd;
  for(int d : dv[a[u]]) {
    cnt[d]++;
    if(cnt[d] >= lev) {
      ans[u] = max(ans[u], d);
    }
  }
  for(int v : g[u]) {
    if(v != p)
      dfs(v, u, __gcd(cur_gcd, a[u]), lev + 1);
  }
  for(int d : dv[a[u]])
    --cnt[d];
}

int main()
{
  for(int i = 1 ; i < N ; i++)
    for(int j = i ; j < N ; j += i)
      dv[j].push_back(i);
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", a + i);
  for(int i = 1 ; i < n ; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0, -1, 0, 0);
  for(int i = 0 ; i < n ; i++)
    printf("%d ", ans[i]);
  return 0;
}
