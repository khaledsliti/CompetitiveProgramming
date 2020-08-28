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

const int N = 1e5 + 5;

int n, m, d;
vector<array<int, 3>> edges;
vector<pair<int, int>> g[N];
int dist[N], fr[N];

bool check(int maxValue) {
  for(int i = 0; i < n; i++) {
    g[i].clear();
    dist[i] = -1;
  }
  for(int i = 0; i < m; i++) {
    int a = edges[i][0], b = edges[i][1], c = edges[i][2];
    if(c <= maxValue)
      g[a].push_back({b, c});
  }
  dist[0] = 0;
  fr[0] = -1;
  queue<int> q;
  q.push(0);
  while(q.empty() == false) {
    int u = q.front();
    q.pop();
    for(auto ed: g[u]) {
      int v = ed.first;
      if(dist[v] == -1) {
        dist[v] = 1 + dist[u];
        fr[v] = u;
        q.push(v);
      }
    }
  }
  if(dist[n - 1] == -1 || dist[n - 1] > d) {
    return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> d;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({--a, --b, c});
  }
  int lo = 0, hi = 1e9, best = -1;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      best = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  if(best == -1) {
    cout << -1 << endl;
    return 0;
  }

  check(best);
  cout << dist[n - 1] << endl;
  vector<int> path;
  for(int i = n - 1; i != -1; i = fr[i])
    path.push_back(i);
  reverse(all(path));
  for(int i = 0; i < sz(path); i++)
    cout << path[i] + 1 << " ";
  cout << endl;
  return 0;
}
