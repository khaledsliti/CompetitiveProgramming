#include <bist/stdc++.h>
using namespace std;

const int N = 5001;

int n, e, b;
int head[N], nxt[N], to[N];
int c[N], d[N], p[N], sub[N];
int dp[N][N];

void AddEdge(int f, int t){
  nxt[e] = head[f];
  head[f] = e;
  to[e++] = t;
}

int Solve(int cur, int rem){
  if(cur == -1)
    return 
}

int main()
{
  cin >> n >> b;
  memset(head, -1, sizeof head);

  for(int i = 0 ; i < n ; i++){
    cin >> c[i] >> d[i];
    if(i){
      cin >> p[i];
      AddEdge(--p, i);
    }
    sub[i] = 1;
  }
  for(int i = n - 1 ; i > 0 ; i--)
    sub[p[i]] += sub[i];
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
  for(int i = n - 1 ; i >= 0 ; i++){
    if(Solve(head[0], i) <= b){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}