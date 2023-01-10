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

const int N = 1e3 + 5;

int n;
int a[N], b[N];
map<int, set<pair<int, int>>> edges;
vector<int> g[N];
int vis[N], match[N];

bool findPath(int u) {
  vis[u] = 1;
  for(int v: g[u]) {
    if(match[v] == -1 || !vis[match[v]] && findPath(match[v])) {
      match[v] = u;
      return true;
    }
  }
  return false;
}

int maxMatching() {
  int res = 0;
  for(int i = 0; i < n; i++) {
    memset(vis, 0, n * sizeof(vis[0]));
    if(findPath(i)) {
      res++;
    }
  }
  return res;
}


void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  edges.clear();
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int x = a[i], y = b[j];
      if(x < y) {
        swap(x, y);
      }
      edges[x - y].insert({i, j});
      edges[x + y].insert({i, j});
    }
  }
  for(auto& entry : edges) {
    for(int i = 0; i < n; i++) {
      g[i].clear();
    }
    for(auto& e : entry.second) {
      g[e.first].push_back(e.second);
    }
    memset(match, -1, n * sizeof(match[0]));
    if(maxMatching() == n) {
      cout << "YES" << endl;
      vector<int> h(n + 2);
      vector<int> to(n);
      for(int i = 0; i < n; i++) {
        int ai = match[i], bi = i;
        if(a[ai] + b[bi] == entry.first) {
          h[i] = a[ai];
        } else if(a[ai] > b[bi]) {
          h[i] = a[ai];
        } else {
          h[i] = -a[ai];
        }
      }
      h[n] = 0;
      h[n + 1] = entry.first;
      int mn = INT_MAX;
      for(int i = 0; i < n + 2; i++) {
        mn = min(mn, h[i]);
      }
      for(int i = 0; i < n + 2; i++) {
        h[i] -= mn;
      }
      for(int i = 0; i < n; i++) {
        cout << h[i] << " ";
      }
      cout << endl << h[n] << " " << h[n + 1] << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
