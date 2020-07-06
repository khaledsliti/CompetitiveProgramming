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

template <typename T>
class segmentTree {
private:
  int n;
  vector<T> st;
  inline int L(int cur) const { return 2 * cur + 1; }
  inline int R(int cur) const { return 2 * cur + 2; }
  void update(int cur, int s, int e, int index, T newValue) {
    if(s > index || e < index) return;
    if(s == e) return void(st[cur] = newValue);
    int mid = (s + e) / 2;
    update(L(cur), s, mid, index, newValue);
    update(R(cur), mid + 1, e, index, newValue);
    st[cur] = merge(st[L(cur)], st[R(cur)]);
  }
  T query(int cur, int s, int e, int i, int j) {
    if(s > j || e < i) return T::identity();
    if(s >= i && e <= j) return st[cur];
    int mid = (s + e) / 2;
    auto left = query(L(cur), s, mid, i, j);
    auto right = query(R(cur), mid + 1, e, i, j);
    return merge(left, right);
  }
public:
  segmentTree(): n(0) {}
  segmentTree(int n): n(n) { st.resize(n << 2, T::identity()); }
  void resize(int n, T defaultValue) { this->n = n; st.clear(); st.resize(n << 2, defaultValue); }
  void resize(int n) { this->n = n; st.clear(); st.resize(n << 2, T::identity()); }
  void update(int index, T newValue) { update(0, 0, n - 1, index, newValue); }
  T query(int l, int r) { return query(0, 0, n - 1, l, r); }
  friend ostream& operator<< (ostream& cout, const segmentTree& s) {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, s.n - 1});
    while(!q.empty()) {
      int cur = get<0>(q.front());
      int l = get<1>(q.front()), r = get<2>(q.front());
      q.pop();
      cout << cur << " - [" << l << " - " << r << "] = " << s.st[cur] << endl;
      if(l != r) {
        int mid = (l + r) / 2;
        q.push({s.L(cur), l, mid});
        q.push({s.R(cur), mid + 1, r});
      }
    }
    return cout;
  }
};

struct Node {
  ll val;
  Node() = default;
  Node(ll val): val(val) {}
  static Node identity() { return Node(0LL); }
  friend Node merge(const Node& a, const Node& b) {
    return Node(a.val + b.val);
  }
  friend ostream& operator<< (ostream& cout, const Node& a) {
    return cout;
  }
};

const int N = 2e5 + 5;
const int L = 18;

int n;
int val[N];
vector<int> g[N];
int par[N], lev[N], subsz[N];

int chainNo = 0;
int chainHead[N], chainPos[N] , chainInd[N] , chainSize[N];
vector<vector<int>> chain;
segmentTree<Node> chainData[N];

void dfs_lca(int u, int p) {
  par[u] = p;
  subsz[u] = 1;
  for(int v: g[u]) {
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs_lca(v, u);
      subsz[u] += subsz[v];
    }
  }
}

void hld(int u, int p) {
  if(chainHead[chainNo] == -1) {
    chainHead[chainNo] = u;
    chain.push_back(vector<int>());
  }
  chainInd[u] = chainNo;
  chainPos[u] = chainSize[chainNo]++;
  chain.back().push_back(u);
  int M = 0 , At = -1;
  for(int v: g[u])
    if(v != p && subsz[v] > M) {
      M = subsz[v];
      At = v;
    }
  if(At != -1) hld(At, u);
	for(int v: g[u]) {
    if(v != p && v != At) {
      chainNo++;
      hld(v, u);
    }
  }
}

int main()
{
  int q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> val[i];
  }
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs_lca(0, -1);

  memset(chainHead, -1, n * sizeof(chainHead[0]));
  hld(0, -1);
  for(int i = 0; i <= chainNo; i++) {
    chainData[i].resize(chainSize[i]);
    for(int j = 0; j < sz(chain[i]); j++) {
      int node = chain[i][j];
      chainData[i].update(j, Node(val[node]));
    }
  }

  while(q--) {
    int t;
    cin >> t;
    if(t == 1) { // update
      int node, x;
      cin >> node >> x; --node;
      int ch = chainInd[node];
      chainData[ch].update(chainPos[node], Node(x));
    } else {
      int node;
      cin >> node; node--;
      ll ans = 0;
      while(~node) {
        int ch = chainInd[node];
        ans += chainData[ch].query(0, chainPos[node]).val;
        node = chainHead[ch];
        node = par[node];
      }
      cout << ans << endl;
    }
  }
  
  return 0;
}
