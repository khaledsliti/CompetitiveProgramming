// Guess Who's Back
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
const int L = 20;

inline int getL(int cur) { return cur * 2 + 1; }
inline int getR(int cur) { return cur * 2 + 2; }
inline int mid(int s, int e) { return s + (e - s) / 2; }

struct segmentTree {
  int n;
  vector<int> st;
  void init(const vector<int>& arr) {
    n = arr.size();
    st.clear();
    st.resize(n << 2);
    build(0, 0, n - 1, arr);
  }
  void build(int cur, int s, int e, const vector<int>& arr) {
    if(s == e) {
      st[cur] = arr[s];
      return;
    }
    build(getL(cur), s, mid(s, e), arr);
    build(getR(cur), mid(s, e) + 1, e, arr);
    st[cur] = max(st[getL(cur)], st[getR(cur)]);
  }
  void update(int cur, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == e) {
      st[cur] = val;
      return;
    }
    update(getL(cur), s, mid(s, e), idx, val);
    update(getR(cur), mid(s, e) + 1, e, idx, val);
    st[cur] = max(st[getL(cur)], st[getR(cur)]);
  }
  int query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return -1;
    if(s >= i && e <= j) return st[cur];
    return max(query(getL(cur), s, mid(s, e), i, j),
      query(getR(cur), mid(s, e) + 1, e, i, j));
  }
};

int n, q;
int v[N], anc[N][L], siz[N], lev[N];
vector<int> g[N];

int chainNo;
int chainIdx[N], chainOrd[N], chainHead[N];
segmentTree chainData[N];
vector<int> chain[N];

void dfs(int u, int p) {
  anc[u][0] = p;
  for(int i = 1; i < L; i++) {
    if(anc[u][i - 1] != -1) {
      anc[u][i] = anc[anc[u][i - 1]][i - 1];
    } else {
      anc[u][i] = -1;
    }
  }
  siz[u] = 1;
  for(int v: g[u]) {
    if(v == p) continue;
    lev[v] = 1 + lev[u];
    dfs(v, u);
    siz[u] += siz[v];
  }
}

void hld(int u, int p, int cur_idx) {
  if(cur_idx == 0) {
    chainNo++;
    chainHead[chainNo - 1] = u;
  }
  chainIdx[u] = chainNo - 1;
  chain[chainNo - 1].push_back(v[u]);
  chainOrd[u] = cur_idx;

  int child = -1;
  for(int v: g[u]) {
    if(v != p && (child == -1 || siz[child] < siz[v])) {
      child = v;
    }
  }
  if(child != -1) {
    hld(child, u, cur_idx + 1);
  }
  for(int v: g[u]) {
    if(v != p && v != child) {
      hld(v, u, 0);
    }
  }
}

int find_lca(int a, int b) {
  if(lev[a] < lev[b]) swap(a, b);
  for(int i = L - 1; i >= 0; i--)
    if(anc[a][i] != -1 && lev[anc[a][i]] >= lev[b])
      a = anc[a][i];
  if(a == b) return a;
  for(int i = L - 1; i >= 0; i--)
    if(anc[a][i] != anc[b][i])
      a = anc[a][i], b = anc[b][i];
  return anc[a][0];
}

void update(int u, int x) {
  int ch = chainIdx[u];
  int pos = chainOrd[u];
  chainData[ch].update(0, 0, sz(chain[ch]) - 1, pos, x);
}

int get(int ch, int i, int j) {
  return chainData[ch].query(0, 0, sz(chain[ch]) - 1, i, j);
}

int get(int a, int b) {
  int res = -1;
  while(chainIdx[a] != chainIdx[b]) {
    res = max(res, get(chainIdx[a], 0, chainOrd[a]));
    a = anc[chainHead[chainIdx[a]]][0];
  }
  res = max(res, get(chainIdx[a], chainOrd[b], chainOrd[a]));
  return res;
}

int main()
{
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }

  lev[0] = 0;
  dfs(0, -1);
  chainNo = 0;
  hld(0, -1, 0);
  for(int i = 0; i < chainNo; i++) {
    chainData[i].init(chain[i]);
  }

  while(q--) {
    int t; scanf("%d", &t);
    if(t == 1) {
      int s, x;
      scanf("%d%d", &s, &x);
      --s;
      update(s, x);
    } else {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      int lca = find_lca(a, b);
      printf("%d\n", max(get(a, lca), get(b, lca)));
    }
  }
  return 0;
}
