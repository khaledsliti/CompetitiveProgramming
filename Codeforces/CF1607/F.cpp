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

struct Edge {
  int from, to;
  friend ostream& operator<<(ostream& cout, const Edge& e) {
    cout << "(" << e.from << ", " << e.to << ")"; 
    return cout;
  }
};

template<int V, int E>
class Graph {
  int n, e;
  int head[V], nxt[E];
  Edge edgeData[E];
  bool initialized = false;
  int col[V], ans[V];
public:
  void init(int n) {
    e = 0;
    this->n = n;
    memset(head, -1, n * sizeof(head[0]));
    memset(col, -1, n * sizeof(col[0]));
    memset(ans, -1, n * sizeof(ans[0]));
    initialized = true;
  }
  void addEdge(Edge edge) {
    assert(initialized);
    nxt[e] = head[edge.from];
    head[edge.from] = e;
    edgeData[e] = edge;
    e++;
  }
  vector<Edge> getNeighbors(int u) {
    vector<Edge> adj;
    for(int k = head[u]; ~k; k = nxt[k]) {
      adj.push_back(edgeData[k]);
    }
    return adj;
  }
  void print() {
    for(int i = 0; i < n; i++) {
      cout << i << ": ";
      for(Edge e: getNeighbors(i)) {
        cout << e << " ";
      }
      cout << endl;
    }
    for(int i = 0; i < n; i++) {
      cout << solve(i) << " ";
    }
    cout << endl;
  }
  int getNext(int u) {
    if(head[u] == -1) return -1;
    return edgeData[head[u]].to;
  }
  void dfs(int u, int step) {
    col[u] = step;
    int v = getNext(u);
    if(v != -1) {
      if(col[v] == -1) {
        dfs(v, step + 1);
      } else if(col[v] != -2) {
        int len = step - col[v] + 1;
        for(int cur = v; ; cur = getNext(cur)) {
          ans[cur] = len;
          if(cur == u) {
            break;
          }
        }
      }
    }
    col[u] = -2;
  }
  int solve(int u) {
    if(u == -1) return 0;
    if(ans[u] != -1) return ans[u];
    return ans[u] = 1 + solve(getNext(u));
  }
  pair<int, int> solve() {
    for(int i = 0; i < n; i++) {
      if(col[i] == -1) {
        dfs(i, 0);
      }
    }
    pair<int, int> ans {-1, 0};
    for(int i = 0; i < n; i++) {
      ans = max(ans, {solve(i), i});
    }
    swap(ans.first, ans.second);
    return ans;
  }
};

const int N = 2004;

int n, m;
string dir[N];
Graph<N*N, N*N> g;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string d = "UDLR";

bool inGrid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int getNode(int x, int y) {
  return x * m + y;
}

pair<int, int> getCell(int node) {
  return { node / m, node % m };
}

int getDir(char c) {
  for(int i = 0; i < 4; i++) {
    if(c == d[i]) {
      return i;
    }
  }
  assert(false);
  return -1;
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> dir[i];
  }
  g.init(n * m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int d = getDir(dir[i][j]);
      int ni = i + dx[d];
      int nj = j + dy[d];
      if(inGrid(ni, nj)) {
        g.addEdge({getNode(i, j), getNode(ni, nj)});
      }
    }
  }
  pair<int, int> ans = g.solve();
  pair<int, int> pos = getCell(ans.first);
  // g.print();
  cout << pos.first + 1 << " " << pos.second + 1 << " " << ans.second << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
