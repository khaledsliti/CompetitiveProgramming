/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1159/problem/E

  Idea:
    First Solution: If we say that next[i] = j, it means that p[next[i]] > p[i] > p[k] for all k between i + 1 and next[i] - 1.
      Let's construct a directed graph as follows:
        The nodes of the graph are numbers in the permutation.
        If p[i] > p[j] we add edge from node i to node j
      For each node i we have to add an edge from next[i] to i and for each node k between i + 1 and next[i] - 1 we add an edge from i to k.
      Since the number of edge can be very large, we will use a segment tree to represent the graph. We add an edge from each node to it two children
      and an edge from node segment [i, i] to all nodes covering the range [i + 1, next[i] - 1] (if it is not empty) - like if we are performing a range update.
      So total number of edges will be O(N log N) in this case - for each i we have O(1) edge from next[i] to i and O(log N) from i to "segment nodes" of range [i + 1, next[i] - 1].
    
    Second Solution: https://codeforces.com/blog/entry/66993

  Compexity:
    Time: First Solution O(N log N), Second Solution O(N)
    Memory: First Solution O(N log N), Second Solution O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 5e5 + 5;

int n;
int nxt[N];

int in[4 * N], node[N], cntNodes = 0;
vector<int> adj[4 * N];
int isLeaf[4 * N], idx[4 * N];
int ans[N];

void build(int cur, int s, int e)
{
  in[cur] = 0;
  adj[cur].clear();
  cntNodes++;
  isLeaf[cur] = 0;
  if(s == e){
    node[s] = cur;
    idx[cur] = s;
    isLeaf[cur] = 1;
    return;
  }
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  in[l]++;
  in[r]++;
  adj[cur].push_back(l);
  adj[cur].push_back(r);
}

void addEdge(int cur, int s, int e, int i, int j, int u)
{
  if(s > j || e < i)
    return;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  if(s >= i && e <= j){
    adj[u].push_back(cur);
    in[cur]++;
    return;
  }
  addEdge(l, s, mid, i, j, u);
  addEdge(r, mid + 1, e, i, j, u);
}

void solve()
{
  scanf("%d", &n);
  cntNodes = 0;
  build(0, 0, n - 1);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", nxt + i);
    if(nxt[i] != -1)
      --nxt[i];
    if(nxt[i] != -1){
      if(nxt[i] < n){
        in[node[i]]++;
        adj[node[nxt[i]]].push_back(node[i]);
      }
      if(nxt[i] > i + 1)
        addEdge(0, 0, n - 1, i + 1, nxt[i] - 1, node[i]);
    }
  }
  queue<int> q;
  q.push(0);
  int cnt = n;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    if(isLeaf[u])
      ans[idx[u]] = cnt--;
    for(int i = 0 ; i < sz(adj[u]) ; i++){
      int v = adj[u][i];
      if(!--in[v])
        q.push(v);
    }
  }
  if(cnt == 0)
    for(int i = 0 ; i < n ; i++)
      printf("%d ", ans[i]);
  else
    printf("-1");
  printf("\n");
}

//------------------------ Second Solution
vector<int> g[N];

void solve2()
{
  scanf("%d", &n);
  int cnt = n;
  for(int i = 0 ; i < n ; i++){
    g[i].clear();
  }
  queue<int> q;
  for(int i = 0 ; i < n ; i++){
    scanf("%d", nxt + i);
    if(nxt[i] != -1)
      nxt[i]--;
    else
      nxt[i] = i + 1;
    if(nxt[i] == n)
      q.push(i);
    else
      g[nxt[i]].push_back(i);
  }
  while(!q.empty()){
    int u = q.front();
    q.pop();
    ans[u] = cnt--;
    for(int i = 0 ; i < sz(g[u]); i++){
      int v = g[u][i];
      q.push(v);
    }
  }
  stack<int> st;
  st.push(n);
  bool good = true;
  for(int i = n - 1 ; i >= 0 ; i--){
    while(st.top() < nxt[i])
      st.pop();
    if(st.top() != nxt[i]){
      good = false;
      break;
    }
    st.push(i);
  }
  if(good){
    for(int i = 0 ; i < n ; i++)
      printf("%d ", ans[i]);
    printf("\n");
  }else{
    printf("-1\n");
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve2();
  return 0;
}