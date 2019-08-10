#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int oo = 1e9;
const int N = 2505, E = 5005;

int n, e, m;
int nxt[E], head[N], to[E], cost[E];
int reach[N][N];
int dist[N];

void add_edge(int f, int t, int c)
{
  nxt[e] = head[f];
  head[f] = e;
  to[e] = t;
  cost[e++] = c;
}

void bfs(int src)
{
  for(int i = 0 ; i < n ; i++){
    reach[src][i] = 0;
  }
  queue<int> q;
  q.push(src);
  vector<int> vis(n, 0);
  vis[src] = 1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    reach[src][cur] = 1;
    for(int k = head[cur] ; ~k ; k = nxt[k]){
      int v = to[k];
      if(!vis[v]){
        vis[v] = 1;
        q.push(v);
      }
    }
  }
}

void bellman()
{
  for(int i = 0 ; i < n ; i++)
    dist[i] = oo;
  dist[0] = 0;
  for(int it = 0 ; it < n - 1 ; it++){
    for(int i = 0 ; i < n ; i++){
      for(int k = head[i] ; ~k ; k = nxt[k]){
        int j = to[k];
        int c = cost[k];
        if(dist[i] < oo && dist[i] + c < dist[j]){
          dist[j] = dist[i] + c;
        }
      }
    }
  }
}

int main()
{
  int p;
  e = 0;
  memset(head, -1, sizeof head);
  cin >> n >> m >> p;
  for(int i = 0 ; i < m ; i++){
    int u, v, c;
    cin >> u >> v >> c;
    add_edge(--u, --v, p - c);
  }
  // for(int i = 0 ; i < n ; i++){
  //   for(int k = head[i] ; ~k ; k = nxt[k])
  //     cout << to[k] << " ";
  //   cout << endl;
  // }
  for(int i = 0 ; i < n ; i++)
    bfs(i);
  // for(int i = 0 ; i < n ; i++){
  //   for(int j = 0 ; j < n ; j++)
  //     cout << reach[i][j] << " ";
  //   cout << endl;
  // }
  bellman();
  for(int i = 0 ; i < n ; i++){
    for(int k = head[i] ; ~k ; k = nxt[k]){
      int j = to[k];
      int c = cost[k];
      if(dist[j] > dist[i] + c && reach[0][i] && reach[j][n - 1]){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << max(0, -dist[n - 1]) << endl;
  return 0;
}
