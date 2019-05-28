#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;
const int N = 205, E = 3e5;

int n, m, ID = 5, e;
int head[N], nxt[E], to[E], cap[E];
int up[N], down[N];
int vis[N], prv[N];

void init()
{
  e = 0;
  for(int i = 0 ; i < n ; i++)
    head[i] = -1;
}

void addEdge(int f, int t, int c)
{
  nxt[e] = head[f];
  head[f] = e;
  to[e] = t;
  cap[e] = c;
  e++;
}

int dfs(int cur, int MX, int lowerFlow)
{
  if(vis[cur] == ID || MX == 0)
    return 0;
  vis[cur] = ID;
  if(cur == n - 1)
    return MX;
  for(int k = head[cur] ; k != -1 ; k = nxt[k]){
    int nxt = to[k];
    if(cap[k] < lowerFlow) continue;
    int flow = dfs(nxt, min(MX, cap[k]), lowerFlow);
    if(!flow) continue;
    cap[k] -= flow;
    cap[k ^ 1] += flow;
    return flow;
  }
  return 0;
}

long long solve()
{
  long long ret = 0;
  int flow;
  int low = (1<<30);
  while(low){
    for(ID++; (flow = dfs(0, 1e9, low)); ID++)
      ret += flow;
    low >>= 1;
  }
  return ret;
}

void reverseGraph()
{
  for(int i = 0 ; i < n ; i++){
    vector<pair<int, int>> adj;
    for(int k = head[i] ; ~k ; k = nxt[k])
      adj.push_back({ to[k], cap[k] });
    for(int k = head[i], j = adj.size() - 1 ; ~k ; k = nxt[k], j--)
      to[k] = adj[j].first, cap[k] = adj[j].second;
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &n, &m);
    n += 2;
    init();
    for(int i = 1 ; i < n - 1 ; i++)
      scanf("%d", &up[i]);
    for(int i = 1 ; i < n - 1 ; i++)
      scanf("%d", &down[i]);
    for(int i = 1 ; i < n - 1 ; i++){
      int t;
      scanf("%d", &t);
      up[i] = t >= 0 ? up[i] : oo;
      down[i] = t <= 0 ? down[i] : oo;
      addEdge(0, i, up[i]);
      addEdge(i, 0, 0);
      addEdge(i, n - 1, down[i]);
      addEdge(n - 1, i, 0);
    }
    while(m--){
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      addEdge(a, b, c);
      addEdge(b, a, c);
    }
    reverseGraph();
    cout << solve() << endl;
  }
  return 0;
}