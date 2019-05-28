/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2865&mosmsg=Submission+received+with+ID+23410278

  Idea:
    Let's a build a graph in which the nodes are the components and edges are the interconnections.
    The weight of an edge is the cost of the interconnection.
    We add a "src" node representing the top layer and a "sink" node representing the down layer.
    We add edges between each node and the src with wight equal to the cost of placing the component in the top layer.
    The same thing for the sink.
    The solution of the problem is the min cut to seperate the src from the sink.

  Compexity:
    Time: O(F * (N + M))
    Memory: O(N + M)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void printTime(clock_t start, clock_t end)
{
  long long time_taken = double(end - start) * 1000.0 / double(CLOCKS_PER_SEC);
  cout << "Time = " << time_taken << endl;
}

const int oo = 1e9;
const int N = 205, E = 3e5;

int n, m, ID = 5, e;
int head[N], nxt[E], to[E], cap[E];
int up[N], down[N];
int vis[N], prv[N], edge[N];

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

void addAugEdge(int f, int t, int c, int r)
{
  addEdge(f, t, c);
  addEdge(t, f, r);
}

int dfs(int cur, int MX, int lowerFlow)
{
  if(vis[cur] == ID || MX == 0)
    return 0;
  vis[cur] = ID;
  if(cur == n - 1)
    return MX;
  for(int k = head[cur] ; ~k ; k = nxt[k]){
    if(cap[k] < lowerFlow) continue;
    int flow = dfs(to[k], min(MX, cap[k]), lowerFlow);
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
    for(ID++; (flow = dfs(0, low)); ID++)
      ret += flow;
    low >>= 1;
  }
  return ret;
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
    }
    while(m--){
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      addAugEdge(a, b, c, c);
    }
    for(int i = 1 ; i < n - 1 ; i++){
      addAugEdge(0, i, up[i], 0);
      addAugEdge(i, n - 1, down[i], 0);
    }
    cout << solve() << endl;
  }
  return 0;
}
