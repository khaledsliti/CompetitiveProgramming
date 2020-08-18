#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5, E = 8e5 + 5;
const long long oo = 1e18;

int n, e;
int head[N];
int nxt[E], cost[E], isFixed[E], to[E], fr[E];
long long dist[N];
int cnt[N];

void init()
{
  e = 0;
  memset(head, -1, n * sizeof(head[0]));
}

void addEdge(int f, int t, int c, bool fix)
{
  nxt[e] = head[f];
  head[f] = e;
  to[e] = t;
  fr[e] = f;
  isFixed[e] = fix;
  cost[e++] = c;
}

void addBiEdge(int a, int b, int c, bool fix)
{
  addEdge(a, b, c, fix);
  addEdge(b, a, c, fix);
}

void dij()
{
  for(int i = 1 ; i < n ; i++)
    dist[i] = oo;
  priority_queue<pair<long long, int>> pq;
  pq.push({0, 0});
  while(!pq.empty()){
    int cur = pq.top().second;
    long long sh = -pq.top().first;
    pq.pop();
    if(sh > dist[cur])
      continue;
    for(int k = head[cur] ; ~k ; k = nxt[k]){
      int adj = to[k];
      int c = cost[k];
      if(dist[adj] > dist[cur] + c){
        dist[adj] = dist[cur] + c;
        pq.push({-dist[adj], adj});
      }
    }
  }
}

int solve(int cur)
{
  if(!cnt[cur])
    return 0;
  for(int k = head[cur] ; ~k ; k = nxt[k]){
    if(!isFixed[k])
      continue;
    int t = to[k];
    int c = cost[k];
    if(dist[cur] == dist[t] + c)
      return cnt[cur];
  }
  return cnt[cur] - 1;
}

int main()
{
  int m, k;
  scanf("%d%d%d", &n, &m, &k);
  init();
  while(m--){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    addBiEdge(--a, --b, c, true);
  }
  while(k--){
    int t, c;
    scanf("%d%d", &t, &c);
    addBiEdge(0, --t, c, false);
    cnt[t]++;
  }
  dij();
  int ans = 0;
  for(int i = 0 ; i < n ; i++)
    ans += solve(i);
  cout << ans << endl;
  return 0;
}
