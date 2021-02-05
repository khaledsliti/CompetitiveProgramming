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

int n, m, e;
int head[N], nxt[N], to[N], deg[N];
int art[N];
int low[N], idx[N], cur_idx, root, child;
int par[N], s[N];

int fs(int x) {
  return par[x] == x ? x : par[x] = fs(par[x]);
}

void unite(int a, int b) {
  a = fs(a), b = fs(b);
  if(a == b) return;
  par[a] = b;
  s[b] += s[a];
}

void init() {
  e = 0;
  cur_idx = 0;
  memset(head, -1, n * sizeof(head[0]));
  memset(art, 0, n * sizeof(art[0]));
  memset(idx, -1, n * sizeof(idx[0]));
  memset(deg, 0, n * sizeof(deg[0]));
}

void addEdge(int f, int t) {
  nxt[e] = head[f];
  head[f] = e;
  to[e++] = t;
  deg[f]++;
}

void dfs(int u, int prv) {
  low[u] = idx[u] = cur_idx++;
  for(int k = head[u]; ~k; k = nxt[k]) {
    int v = to[k];
    if(idx[v] == -1) {
      dfs(v, k ^ 1);
      if(u == root) child++;
      low[u] = min(low[u], low[v]);
      if(low[v] >= idx[u]) {
        art[u] = 1;
      }
    } else if(k != prv) {
      low[u] = min(low[u], idx[v]);
    }
  }
}

unordered_set<int> b;
int dfs(int u) {
  if(art[u]) {
    b.insert(u);
    return 0;
  }
  idx[u] = 1;
  int r = 1;
  for(int k = head[u]; ~k; k = nxt[k]) {
    int v = to[k];
    if(idx[v] == 0) {
      r += dfs(v);
    }
  }
  return r;
}

void solve() {
  n = 0;
  vector<pair<int, int>> edge;
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    n = max(n, max(a, b));
    --a, --b;
    edge.push_back({a, b});
  }
  init();
  for(auto ed: edge) {
    if(ed.first != ed.second) {
      addEdge(ed.first, ed.second);
      addEdge(ed.second, ed.first);
    }
  }
  for(int i = 0; i < n; i++) {
    if(idx[i] == -1) {
      root = i;
      child = 0;
      dfs(i, -1);
      art[root] = child > 1;
    }
  }
  memset(idx, 0, n * sizeof(idx[0]));
  int tot = 0;
  long long cnt = 1;
  for(int i = 0; i < n; i++) {
    if(!art[i] && idx[i] == 0) {
      b.clear();
      auto s = dfs(i);
      if(sz(b) == 1) {
        tot++;
        cnt *= s;
      } else if(sz(b) == 0) {
        if(s > 1) {
          tot += 2;
          cnt *= s * (s - 1) / 2;
        } else {
          tot += 1;
        }
      }
    }
  }
  cout << tot << " " << cnt << endl;
}

int main()
{
  int tc = 1;
  while(scanf("%d", &m) && m) {
    printf("Case %d: ", tc++);
    solve();
  }
  return 0;
}
