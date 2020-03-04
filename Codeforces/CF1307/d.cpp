#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, m, k;
vector<int> g[N];
int dist[2][N];
vector<int> nodes;
int arr[N];
int L[N], R[N];

void add_edge(int a, int b)
{
  g[a].pb(b);
  swap(a, b);
  g[a].pb(b);
}

void bfs(int src, int idx)
{
  dist[idx][src] = 0;
  queue<int> q;
  q.push(src);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0 ; i < sz(g[u]) ; i++){
      int v = g[u][i];
      if(dist[idx][v] == -1){
        dist[idx][v] = 1 + dist[idx][u];
        q.push(v);
      }
    }
  }
}

void print()
{
  for(int i = 0 ; i < k ; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  for(int i = 0 ; i < k ; i++){
    cout << L[i] << " ";
  }
  cout << endl;
  for(int i = 0 ; i < k ; i++){
    cout << R[i] << " ";
  }
  cout << endl;
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0 ; i < k ; i++){
    int a; scanf("%d", &a);
    nodes.pb(--a);
  }
  for(int i = 0 ; i < m ; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(--u, --v);
  }
  memset(dist, -1, sizeof dist);
  bfs(0, 0);
  bfs(n - 1, 1);
  sort(all(nodes), [&](int a, int b){
    return dist[0][a] < dist[0][b];
  });
  for(int i = 0 ; i < k ; i++){
    arr[i] = dist[1][nodes[i]];
  }
  L[0] = arr[0];
  for(int i = 1 ; i < k ; i++)
    L[i] = max(L[i - 1], arr[i]);
  R[k - 1] = arr[k - 1];
  for(int i = k - 2 ; i >= 0 ; i--)
    R[i] = max(R[i + 1], arr[i]);
  int best = 0;
  for(int i = 0 ; i < k - 1 ; i++){
    int cur = dist[0][nodes[i]] + 1 + R[i + 1];
    // D(nodes[i]);
    // D(dist[0][nodes[i]]);
    // D(cur);
    best = max(best, cur);
  }
  cout << min(best, dist[0][n - 1]) << endl;
  return 0;
}
