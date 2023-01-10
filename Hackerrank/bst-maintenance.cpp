// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 250003;
const int INF = 1e9;
const int L = 18;

int n, dfs_num;
int ind[N], arr[N];
int str[N << 2];
set<int> g[N];
int sub[N], ok[N], par[N];
int st[N], en[N], lev[N];
pair<int, int> sparce[N << 1][L + 1];
long long sum[N], cnt[N], contrib[N];

void build(int cur, int s, int e) {
  if(s == e) {
    str[cur] = ind[s];
    return;
  }
  int mid = s + (e - s) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  str[cur] = min(str[l], str[r]);
}

int query(int cur, int s, int e, int i, int j) {
  if(i > j) return INF;
  if(s > j || e < i) return INF;
  if(s >= i && e <= j) return str[cur];
  int mid = s + (e - s) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  return min(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve(int idx, int lo, int hi) {
  if(lo > hi)
    return;
  int left = query(0, 0, n - 1, lo, arr[idx] - 1);
  if(left < INF) {
    g[idx].insert(left);
    g[left].insert(idx);
    solve(left, lo, arr[idx] - 1);
  }
  int right = query(0, 0, n - 1, arr[idx] + 1, hi);
  if(right < INF) {
    g[idx].insert(right);
    g[right].insert(idx);
    solve(right, arr[idx] + 1, hi);
  }
}

void get_sz(int u, int p) {
  sub[u] = 1;
  for(int v : g[u]) {
    if(v != p && ok[v]) {
      get_sz(v, u);
      sub[u] += sub[v];
    }
  }
}

int find_centroid(int u, int p, int tot) {
  for(int v : g[u])
    if(v != p && ok[v] && sub[v] > tot / 2)
      return find_centroid(v, u, tot);
  return u;
}

void decompose(int u, int p) {
  get_sz(u, -1);
  int c = find_centroid(u, -1, sub[u]);
  par[c] = p;
  ok[c] = 0;
  for(int v : g[c]) {
    g[v].erase(c);
    decompose(v, c);
  }
}

void centroid_decomp() {
  for(int i = 0 ; i < n ; i++)
    ok[i] = 1;
  decompose(0, -1);
}

void add_node(int u) {
  sparce[dfs_num][0] = { lev[u], u };
  for(int j = 1 ; dfs_num - (1 << j) >= -1 ; j++)
    sparce[dfs_num][j] = min(sparce[dfs_num][j - 1], sparce[dfs_num - (1 << (j - 1))][j - 1]);
  dfs_num++;
}

void dfs1(int u, int p) {
  add_node(u);
  st[u] = dfs_num - 1;
  for(int v : g[u]){
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs1(v, u);
      add_node(u);
    }
  }
  en[u] = dfs_num - 1;
}

int get_lca(int a, int b) {
  if(st[a] > st[b]) swap(a, b);
  int i = st[a], j = st[b];
  int lg = 31 - __builtin_clz(j - i + 1);
  return min(sparce[j][lg], sparce[i + (1 << lg) - 1][lg]).second;
}

int get_distance(int a, int b) {
  int lca = get_lca(a, b);
  return lev[a] + lev[b] - 2 * lev[lca];
}

long long calc(int u) {
  long long tot = sum[u];
  for(int cur = u ; ~par[cur] ; cur = par[cur]) {
    tot += 1LL * get_distance(u, par[cur]) * (cnt[par[cur]] - cnt[cur]);
    tot += sum[par[cur]] - contrib[cur];
  }
  return tot;
}

void update(int u) {
  for(int cur = u ; ~cur ; cur = par[cur]) {
    cnt[cur]++;
    sum[cur] += get_distance(cur, u);
    if(~par[cur])
      contrib[cur] += get_distance(par[cur], u);
  }
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    int a; scanf("%d", &a); --a;
    ind[a] = i; arr[i] = a;
  }
  build(0, 0, n - 1);
  solve(0, 0, n - 1);
  dfs1(0, -1);
  centroid_decomp();
  long long ans = 0;
  for(int i = 0 ; i < n ; i++) {
    ans += calc(i);
    update(i);
    printf("%lld\n", ans);
  }
  return 0;
}
