/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/problemset/problem/815/C

  Idea:
    
    
  Compexity:
    Time: O(N * N lg N)
    Memory: O(N * N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int N = 5001;
const long long MAX = 5e13;

int n, e, b;
int head[N], nxt[N], to[N], fr[N];
int c[N], d[N], p[N], sub[N];
vector<long long> nodes[N];
long long dp[N][N];
bool done[N][N];

void AddEdge(int f, int t){
  nxt[e] = head[f];
  head[f] = e;
  fr[e] = f;
  to[e++] = t;
}

long long SolveSubtree(int cur, int rem);

long long SolveAsRoot(int u, int rem){
  if(sub[u] < rem)
    return MAX;
  if(rem == 0)
    return 0;
  long long res = nodes[u][rem - 1];
  res = min(res, c[u] - d[u] + SolveSubtree(head[u], rem - 1));
  return res;
}

long long SolveSubtree(int cur, int rem){
  if(cur == -1)
    return rem == 0 ? 0 : MAX;
  if(done[cur][rem])
    return dp[cur][rem];
  done[cur][rem] = 1;
  int u = fr[cur], v = to[cur];
  if(nxt[cur] == -1)
    return dp[cur][rem] = SolveAsRoot(v, rem);
  long long res = MAX;
  for(int i = 0 ; i <= min(rem, sub[v]) ; i++)
    res = min(res, SolveAsRoot(v, i) + SolveSubtree(nxt[cur], rem - i));
  return dp[cur][rem] = res;
}

int main()
{
  cin >> n >> b;
  memset(head, -1, sizeof head);
  for(int i = 0 ; i < n ; i++){
    cin >> c[i] >> d[i];
    if(i){
      cin >> p[i];
      AddEdge(--p[i], i);
    }
    sub[i] = 1;
    nodes[i].push_back(i);
  }
  for(int i = n - 1 ; i > 0 ; i--){
    sub[p[i]] += sub[i];
    for(auto x : nodes[i])
      nodes[p[i]].push_back(x);
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < (int)nodes[i].size(); j++)
      nodes[i][j] = c[nodes[i][j]];
    sort(nodes[i].begin(), nodes[i].end());
    for(int j = 1 ; j < (int)nodes[i].size(); j++)
      nodes[i][j] += nodes[i][j - 1];
  }
  for(int i = 0 ; i < n ; i++){
    int edge_index = 0, mx = 0;
    int last_edge = -1;
    for(int k = head[i] ; ~k ; k = nxt[k]){
      int v = to[k];
      if(sub[v] > mx){
        mx = sub[v];
        edge_index = k;
      }
      last_edge = k;
    }
    if(~last_edge)
      swap(to[last_edge], to[edge_index]);
  }
  memset(dp, -1, sizeof dp);
  for(int i = n ; i >= 0 ; i--)
    if(SolveAsRoot(0, i) <= b){
      cout << i << endl;
      return 0;
    }
  return 0;
}