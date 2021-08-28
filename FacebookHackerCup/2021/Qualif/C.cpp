#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

struct Edge {
  int from, to, cost;
  friend ostream& operator<<(ostream& cout, const Edge& e) {
    cout << "(" << e.from << ", " << e.to << ", " << e.cost << ")"; 
    return cout;
  }
};

template<typename T>
struct Graph {
  int n, e;
  vector<int> head, nxt;
  vector<T> edgeData;
  Graph(int _n): n(_n), e(0) {
    head.resize(n, -1);
  }
  void addEdge(T e) {
    nxt.push_back(head[e.from]);
    head[e.from] = nxt.size() - 1;
    edgeData.push_back(e);
  }
  vector<T> getNeighbors(int u) {
    vector<T> adj;
    for(int k = head[u]; ~k; k = nxt[k]) {
      adj.push_back(edgeData[k]);
    }
    return adj;
  }
  void print() {
    for(int i = 0; i < n; i++) {
      cout << i << ": ";
      for(T e: getNeighbors(i)) {
        cout << e << " ";
      }
      cout << endl;
    }
  }
};

const int N = 51;
const int E = 101;

int n, k, e;
int g[N][N];
int cst[N], nxt[E], head[N], to[E];
int dp[E][N][2];

void init() {
  e = 0;
  memset(head, -1, n * sizeof(head[0]));
}

void addEdge(int f, int t) {
  nxt[e] = head[f];
  head[f] = e;
  to[e] = t;
  e++;
}

void dfs(int u, int p) {
  for(int t = 0; t < n; t++) {
    if(t != p && g[u][t]) {
      dfs(t, u);
      addEdge(u, t);
    }
  }
}

int solve(int edge, int rem, int par) {
  if(edge == -1 || rem == 0 && par == 0) return 0;
  int& r = dp[edge][rem][par];
  if(r != -1) return r;
  r = 0;

  if(par == 0) {
    for(int take = 0; take <= rem; take++) {
      // ignore edge
      r = max(r, solve(head[to[edge]], take, 0) + solve(nxt[edge], rem - take, 0));
      // take edge
      if(take > 0) {
        r = max(r, cst[to[edge]] + solve(head[to[edge]], take - 1, 1) + solve(nxt[edge], rem - take, 0));
      }
    }
  } else {
    r = max(r, solve(edge, rem, 0));
    for(int take = 0; take <= rem; take++) {
      r = max(r, cst[to[edge]] + solve(head[to[edge]], take, 1) + solve(nxt[edge], rem - take, 0));
      if(take > 0) {
        r = max(r, cst[to[edge]] + solve(head[to[edge]], take - 1, 1) + solve(nxt[edge], rem - take, 1));
      }
      r = max(r, solve(head[to[edge]], take, 0) + solve(nxt[edge], rem - take, 1));
    }
  }

  return r;
}

void solve() {
  cin >> n;
  cin >> k;
  for(int i = 1; i <= n; i++) {
    cin >> cst[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      g[i][j] = 0;
    }
  }
  g[0][1] = 1;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a][b] = g[b][a] = 1;
  }

  if(k == 0) {
    cout << cst[1] << endl;
    return;
  }

  n++;
  init();
  dfs(0, -1);

  memset(dp, -1, sizeof dp);
  cout << cst[1] + solve(head[1], k, 1) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
