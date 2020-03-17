// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;

int n, k;
vector<int> g[N];
int dist[N];

int bfs(queue<int>& q) {
  int cnt = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    cnt++;
    if(dist[u] == k) continue;
    for(int v : g[u]) {
      if(dist[v] == -1) {
        dist[v] = 1 + dist[u];
        q.push(v);
      }
    }
  }
  return n - cnt;
}

int solveOdd() {
  int best = n;
  for(int i = 0 ; i < n ; i++) {
    for(int j : g[i]) {
      queue<int> q; q.push(i); q.push(j);
      for(int m = 0 ; m < n ; m++) dist[m] = -1;
      dist[i] = dist[j] = (k + 1) / 2;
      best = min(best, bfs(q));
    }
  }
  return best;
}

int solveEven() {
  int best = n;
  for(int src = 0 ; src < n ; src++) {
    for(int i = 0 ; i < n ; i++)
      dist[i] = -1;
    dist[src] = k / 2;
    queue<int> q;
    q.push(src);
    best = min(best, bfs(q));
  }
  return best;
}

int solve() {
  if(k & 1) return solveOdd();
  return solveEven();
}

int main()
{
  cin >> n >> k;
  for(int i = 1 ; i < n ; i++) { 
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if(k == 0) {
    cout << n - 1 << endl;
    return 0;
  }
  if(k == 1) {
    cout << n - 2 << endl;
    return 0;
  }
  cout << solve() << endl;
  return 0;
}
