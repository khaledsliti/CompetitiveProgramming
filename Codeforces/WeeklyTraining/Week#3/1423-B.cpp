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

const int N = 1e5 + 2;

int n;
vector<array<int, 3>> roads;

class MaxMatching {
  static const int INF = 1e9;
  int n, m;
  vector<vector<int>> g;
  vector<int> used, matching, vis, dist;
  void fill(vector<int>& arr, int val) {
    for(int i = 0; i < arr.size(); i++)
      arr[i] = val;
  }
  void init(vector<int>& arr, int s, int val) {
    arr.resize(s);
    fill(arr, val);
  }
  void bfs() {
    queue<int> q;
    fill(dist, -1);
    for(int i = 0; i < n; i++) {
      if(!used[i]) {
        q.push(i);
        dist[i] = 0;
      }
    }
    while(q.empty() == false) {
      int u = q.front();
      q.pop();
      for(int v: g[u]) {
        int w = matching[v];
        if(w >= 0 && dist[w] < 0) {
          dist[w] = 1 + dist[u];
          q.push(w);
        }
      }
    }
  }
  bool dfs(int u) {
    vis[u] = 1;
    for(int v: g[u]) {
      int w = matching[v];
      if(w < 0 || !used[w] && dist[w] == 1 + dist[u] && dfs(w)) {
        matching[v] = u;
        used[u] = 1;
        return true;
      }
    }
    return false;
  }
public:
  MaxMatching(int n, int m) {
    this->n = n;
    this->m = m;
    g.resize(n);
    init(used, n, 0);
    init(matching, m, -1);
    init(vis, n, 0);
    init(dist, n, 0);
  }
  void addEdge(int a, int b) {
    g[a].push_back(b);
  }
  int maxMatching() {
    fill(used, 0);
    fill(matching, -1);
    while(true) {
      int res = 0;
      bfs();
      fill(vis, 0);
      int nw = 0;
      for(int i = 0; i < n; i++) {
        if(!used[i] && dfs(i)) {
          nw++;
        }
      }
      if(!nw) return res;
      res += nw;
    }
  }
};

bool check(int max_cost) {
  MaxMatching matching(n, n);
  for(int i = 0; i < sz(roads); i++) {
    int a = roads[i][0], b = roads[i][1], c = roads[i][2];
    if(c <= max_cost) {
      matching.addEdge(a, b);
    }
  }
  return matching.maxMatching() == n;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    roads.push_back({--a, --b, c});
  }

  int lo = 0, hi = 1e9 + 1, ans = -1;

  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans << endl;

  return 0;
}
