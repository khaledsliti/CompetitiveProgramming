/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1107/problem/F

  Idea:
    If we take an offer the first day, then we have two choices: either take another offer the next day or by the car.
    So we have to buy the offers for successive days.
    The problem become as follows: Given the set of offers select an offer to take in each days so that you can maximize the profit.
    This is a min cost flow problem in which we have to match the offers with the days with a cost equal to the profit

  Complexity:
    Time: O(N^3 lg N)
    Memory: O(N^2)
********************************************************************************************************/
#include <bits/stdc++.h>
#define DEB(x) cout << #x << " = " << x << endl;
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const long long oo = 1e18;

const int V = 500;
const int N = 2 * V + 2 + 5;
const int E = 2 * (V * V) + 2 * 2 * V + 5;

int n, m, e;
int head[N], nxt[E], to[E], fr[E], cap[E];
long long cost[E];
int source, sink;

long long dist[N];
int prv[N];
bool inq[N];

void init()
{
  e = 0;
  memset(head, -1, n * (sizeof head[0]));
}

void addEdge(int f, int t, int c, long long w)
{
  nxt[e] = head[f];
  head[f] = e;
  fr[e] = f;
  to[e] = t;
  cap[e] = c;
  cost[e] = w;
  e++;
}

void addAugEdge(int a, int b, int c, long long w)
{
  addEdge(a, b, c, w);
  addEdge(b, a, 0, -w);
}

bool shortest()
{
  for(int i = 0 ; i < n ; i++){
    dist[i] = oo;
    prv[i] = -1;
  }
  dist[source] = 0;
  for(int i = 0 ; i < n ; i++){
    if(dist[i] == oo)
      continue;
    for(int k = head[i] ; ~k ; k = nxt[k]){
      int j = to[k];
      if(cap[k] > 0 && dist[j] > dist[i] + cost[k]){
        dist[j] = dist[i] + cost[k];
        prv[j] = k;
      }
    }
  }
  return prv[sink] != -1;
}

struct dijState{
  int node;
  long long cost;

  bool operator<(const dijState& rhs) const{
    return cost > rhs.cost;
  }
};

bool dijkstra()
{
  for(int i = 0 ; i < n ; i++){
    dist[i] = oo;
    prv[i] = -1;
  }
  dist[source] = 0;
  priority_queue<dijState> pq;
  pq.push({0LL, source});
  while(!pq.empty()){
    int u = pq.top().node;
    long long c = pq.top().cost;
    pq.pop();
    if(c > dist[u])
      continue;
    for(int k = head[u] ; ~k ; k = nxt[k]){
      int v = to[k];
      if(cap[k] > 0 && dist[v] > dist[u] + cost[k]){
        dist[v] = dist[u] + cost[k];
        prv[v] = k;
        pq.push({v, dist[v]});
      }
    }
  }
  return prv[sink] != -1;
}

void reduceCost()
{
  for(int k = 0 ; k < e ; k++){
    int u = fr[k];
    int v = to[k];
    cost[k] += dist[u] - dist[v];
  }
}

long long minCostFlow()
{
  assert(shortest());
  long long reduceSum = 0;
  long long totalCost = 0;
  do{
    reduceCost();
    reduceSum += dist[sink];
    int maxCap = 1e9;
    for(int cur = sink ; cur != source ; cur = to[prv[cur] ^ 1]){
      int edge = prv[cur];
      maxCap = min(maxCap, cap[edge]);
    }
    for(int cur = sink ; cur != source ; cur = to[prv[cur] ^ 1]){
      int edge = prv[cur];
      cap[edge] -= maxCap;
      cap[edge ^ 1] += maxCap;
    }
    totalCost += reduceSum;
  }while(dijkstra());
  return totalCost * -1;
}

int main()
{
  scanf("%d", &m);
  n = 2 * (1 + m);
  init();
  source = 0;
  sink = n - 1;
  for(int i = 1 ; i <= m ; i++){
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    for(int j = m - 1 ; j >= 0 ; j--){
      long long c = max(a - 1LL * b * min(k, j), 0LL);
      addAugEdge(i, m + j + 1, 1, -c);
    }
  }
  for(int i = 1 ; i <= m ; i++){
    addAugEdge(source, i, 1, 0);
    addAugEdge(m + i, sink, 1, 0);
  }
  cout << minCostFlow() << endl;
  return 0;
}