#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 2;

int n;
vector<int> g[N];
int h[N], par[N], in[N], out[N];
int max_child[N][3];
int max_sub[N][2];
long long ans;

void DFS(int u, int p){
  par[u] = p;
  h[u] = 0;
  in[u] = 0;
  int mx1 = -1, mx2 = -1, mx3 = -1;
  int mx_sub1 = 0, mx_sub2 = 0;
  for(int i = 0 ; i < sz(g[u]) ; i++){
    int v = g[u][i];
    if(v != p){
      DFS(v, u);
      h[u] = max(h[u], 1 + h[v]);
      if(h[v] > mx1){
        mx3 = mx2;
        mx2 = mx1;
        mx1 = h[v];
      }else if(h[v] > mx2){
        mx3 = mx2;
        mx2 = h[v];
      }else if(h[v] > mx3){
        mx3 = h[v];
      }
      if(in[v] > mx_sub1){
        mx_sub2 = mx_sub1;
        mx_sub1 = in[v];
      }else if(in[v] > mx_sub2){
        mx_sub2 = in[v];
      }
      in[u] = max(in[u], in[v]);
    }
  }
  in[u] = max(in[u], 2 + mx1 + mx2);
  
  max_child[u][0] = mx1;
  max_child[u][1] = mx2;
  max_child[u][2] = mx3;

  max_sub[u][0] = mx_sub1;
  max_sub[u][1] = mx_sub2;
}

void CleanTree(){
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < sz(g[i]) ; j++)
      if(g[i][j] == par[i]){
        for(int k = j ; k < sz(g[i]) - 1 ; k++)
          g[i][k] = g[i][k + 1];
        g[i].pop_back();
        break;
      }
  }
}

void Solve(int u, int so_far){
  ans = max(ans, 1LL * so_far * in[u]);
  out[u] = 0;
  if(par[u] != -1){
    int p = par[u];
    out[u] = max(out[p] + 1, out[u]);
    int mx = (max_child[p][0] == h[u] ? max_child[p][1] : max_child[p][0]);
    out[u] = max(out[u], 2 + mx);
  }
  for(int i = 0 ; i < sz(g[u]) ; i++){
    int v = g[u][i];
    int mx_in = (max_sub[u][0] == in[v] ? max_sub[u][1] : max_sub[u][0]);
    int new_so_far = max(so_far, mx_in);
    vector<int> val = { max_child[u][0], max_child[u][1], max_child[u][2] };
    for(int it = 0 ; it < 2 ; it++)
      if(val[it] == h[v]){
        swap(val[it], val[2]);
        break;
      }
    val.pop_back();
    sort(val.begin(), val.end());
    int mx1_sib = val[1];
    int mx2_sib = val[0];
    new_so_far = max(new_so_far, 2 + mx1_sib + mx2_sib);
    new_so_far = max(new_so_far, out[u] + 1 + mx1_sib);
    Solve(v, new_so_far);
  }
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n - 1 ; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  h[0] = -1;
  DFS(0, -1);
  CleanTree();
  ans = 0;
  Solve(0, 0);
  cout << ans << endl;
  return 0;
}