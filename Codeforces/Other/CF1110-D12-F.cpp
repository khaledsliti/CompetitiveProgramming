/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1110/problem/F

  Idea:
    First, we calculate the distance the root and each of the leaves. Let's say that we use an array cost to store theses distances.
    Then, we answer the queries offline. We run DFS from the root and for each node we answer its queries.
    Now suppose that we are in a node u and we need to call dfs from it child v. Before the call we have to update the array cost.
    If the weight of the edge u to v is c, then we add c to all leaves except those located if the subtree of v
    and we substruct c from remaining nodes (located in the subtree of v).
    We can update the array cost using a segment tree.
    Finally, to answer a query we can get the minimum value in the array cost in the range [l, r].

  Compexity:
    Time: O((N + Q) log N)
    Memory: O(N log N + Q)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const long long oo = 1e18;
const int N = 5e5 + 5;

int n, q;
int par[N];
int index[N], L[N], R[N], node_index;
vector<int> g[N], w[N];
long long cost[N];
vector<pair<pair<int, int>, int>> qu[N];
long long st[N * 4], lz[N * 4];
long long ans[N];

void DFS(int u)
{
  index[node_index] = u;
  L[u] = node_index++;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    int c = w[u][i];
    cost[v] = cost[u] + c;
    DFS(v);
  }
  R[u] = node_index - 1;
  if(g[u].size())
    cost[u] = oo;
}

void build(int node, int s, int e)
{
  if(s == e){
    st[node] = cost[index[s]];
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * node + 1;
  int r = 2 * node + 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  st[node] = min(st[l], st[r]);
}

void push_down(int node, int s, int e)
{
  if(lz[node]){
    st[node] += lz[node];
    if(s != e){
      lz[2 * node + 1] += lz[node];
      lz[2 * node + 2] += lz[node];
    }
    lz[node] = 0;
  }
}

void update(int node, int s, int e, int i, int j, long long val)
{
  push_down(node, s, e);
  if(s > j || e < i)
    return;
  int l = 2 * node + 1;
  int r = 2 * node + 2;
  int mid = (s + e) / 2;
  if(s >= i && e <= j){
    st[node] += val;
    if(s != e){
      lz[l] += val;
      lz[r] += val;
    }
    return;
  }
  update(l, s, mid, i, j, val);
  update(r, mid + 1, e, i, j, val);
  st[node] = min(st[l], st[r]);
}

void update(int l, int r, long long val)
{
  update(0, 0, n - 1, l, r, val);
}

long long query(int node, int s, int e, int i, int j)
{
  push_down(node, s, e);
  if(s > j || e < i)
    return oo;
  if(s >= i && e <= j)
    return st[node];
  int mid = (s + e) / 2;
  int l = 2 * node + 1;
  int r = 2 * node + 2;
  return min(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve(int u)
{
  for(int i = 0 ; i < (int)qu[u].size() ; i++){
    int l = qu[u][i].first.first;
    int r = qu[u][i].first.second;
    int idx = qu[u][i].second;
    ans[idx] = query(0, 0, n - 1, l, r);
  }
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    int c = w[u][i];
    update(L[v], R[v], -2LL * c);
    update(0, n - 1, c);
    solve(v);
    update(L[v], R[v], 2LL * c);
    update(0, n - 1, -c);
  }
}

int main()
{
  scanf("%d%d", &n, &q);
  par[0] = -1;
  for(int i = 1 ; i < n ; i++){
    int wi;
    scanf("%d%d", &par[i], &wi);
    g[--par[i]].push_back(i);
    w[par[i]].push_back(wi);
  }
  // Build segment tree
  DFS(0);
  build(0, 0, n - 1);
  for(int i = 0 ; i < q ; i++){
    int v, l, r;
    scanf("%d%d%d", &v, &l, &r);
    assert(v >= 1 && v <= n && l <= r && l >= 1 && r <= n);
    qu[--v].push_back({ { --l, --r }, i });
  }
  // DFS to answer queries
  solve(0);
  // Print result
  for(int i = 0 ; i < q ; i++)
    printf("%I64d\n", ans[i]);
  return 0;
}
