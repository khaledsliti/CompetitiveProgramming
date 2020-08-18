#include <bits/stdc++.h>
using namespace std;

int const maxN = 300010;

int n, m;
int a[3];
vector<int> g[maxN];
long long p[maxN];
int dist[3][maxN];

void bfs(int idx) {
  for(int i = 0 ; i < n ; i++)
    dist[idx][i] = -1;
  dist[idx][a[idx]] = 0;
  queue<int> q;
  q.push(a[idx]);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v : g[u]) {
      if(dist[idx][v] == -1) {
        dist[idx][v] = 1 + dist[idx][u];
        q.push(v);
      }
    }
  }
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < 3 ; i++)
      scanf("%d", &a[i]), --a[i];
    for(int i = 0 ; i < m ; i++)
      scanf("%d", &p[i]);
    sort(p, p + m);
    for(int i = 1 ; i < m ; i++)
      p[i] += p[i - 1];
    for(int i = 0 ; i < n ; i++)
      g[i].clear();
    for(int i = 0 ; i < m ; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for(int i = 0 ; i < 3 ; i++)
      bfs(i);
    long long best = 1e18;
    for(int i = 0 ; i < n ; i++) {
      int tot = dist[0][i] + dist[1][i] + dist[2][i];
      int add = dist[1][i];
      if(tot <= m) {
        best = min(best, (tot > 0 ? p[tot - 1] : 0) + (add > 0 ? p[add - 1] : 0));
      }
    }
    cout << best << endl;
  }
  return 0;
}
