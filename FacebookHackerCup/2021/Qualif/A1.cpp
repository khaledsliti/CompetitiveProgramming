#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 26;
struct Edge {
  int from, to;
  friend ostream& operator<<(ostream& cout, const Edge& e) {
    cout << "(" << e.from << ", " << e.to << ")"; 
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

int occ[N];

bool isVowel(char c) {
  for(char x: {'A', 'E', 'I', 'O', 'U'}) {
    if(x == c) {
      return true;
    }
  }
  return false;
}

void build(Graph<Edge>& g) {
  int k;
  cin >> k;
  while(k--) {
    char a, b;
    cin >> a >> b;
    g.addEdge({a - 'A', b - 'A'});
  }
}


const int INF = 1e6;
vector<vector<int>> floyd(Graph<Edge>& g) {
  vector<vector<int>> dist(N, vector<int>(N, INF));
  for(int i = 0; i < N; i++) {
    for(auto j: g.getNeighbors(i)) {
      dist[i][j.to] = 1;
    }
    dist[i][i] = 0;
  }
  for(int k = 0; k < N; k++) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

int solve(const vector<vector<int>>& dist) {
  int best = INF;
  for(int i = 0; i < N; i++) {
    int cur = 0;
    for(int j = 0; j < N; j++) {
      cur += occ[j] * dist[j][i];
    }
    best = min(best, cur);
  }
  return best >= INF ? -1 : best;
}

int solve() {
  string s; cin >> s;
  for(int i = 0; i < N; i++) {
    occ[i] = 0;
  }
  for(char c: s) {
    occ[c - 'A']++;
  }
  Graph<Edge> g(N);
  build(g);
  // g.print();
  vector<vector<int>> dist = floyd(g);
  return solve(dist);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ": " << solve() << endl;
  }
  return 0;
}
