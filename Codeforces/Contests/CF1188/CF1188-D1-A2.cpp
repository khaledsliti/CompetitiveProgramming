/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1188/problem/A2

  Idea:
    If we have a node with degree equal to 2 then there is no solution.
    Suppose that we need to add x to an edge (u, v). We get two leaves from the subtree of u not containing v. let's call them u1 and u2
    We do the same for v to get v1 and v2 (v1 = v2 = v if v is a leaf, and same for u)
    We add at most 4 paths:
      - from u1 to v1 with cost x / 2
      - from u2 to v2 with cost x / 2
      - from u1 to u2 with cost -x / 2
      - from v1 to v2 with cost -x / 2

  Complexity:
    Time: O(N ^ 2)
    Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
using namespace std;
 
const int N = 1e5 + 5;
const int E = 2e5 + 2;
 
int n, e;
vector<pair<int, int>> g[N];
vector<pair<pair<int, int>, int>> sol;

int dfs(int u, int p)
{
  for(int i = 0 ; i < sz(g[u]) ; i++){
    int v = g[u][i].first;
    if(v != p)
      return dfs(v, u);
  }
  return u;
}

pair<int, int> get_leaves(int u, int p)
{
  pair<int, int> res = {u, u};
  for(int i = 0 ; i < sz(g[u]) && res.second == u ; i++){
    int v = g[u][i].first;
    if(v != p){
      if(res.first == u)
        res.first = dfs(v, u);
      else
        res.second = dfs(v, u);
    }
  }
  return res;
}

void solve(int u, int v, int c)
{
  pair<int, int> a = get_leaves(u, v);
  pair<int, int> b = get_leaves(v, u);
  sol.pb({{a.first, b.first}, c / 2});
  sol.pb({{a.second, b.second}, c / 2});
  if(a.first != a.second)
    sol.pb({{a.first, a.second}, -c / 2});
  if(b.first != b.second)
    sol.pb({{b.first, b.second}, -c / 2});
}

void solve()
{
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < sz(g[i]) ; j++){
      int u = i, v = g[i][j].first;
      int c = g[i][j].second;
      if(u < v){
        solve(u, v, c);
      }
    }
  }
}

int main()
{
  cin >> n;
  for(int i = 1 ; i < n ; i++){
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].pb({b, c});
    g[b].pb({a, c});
  }
  for(int i = 0 ; i < n ; i++)
    if(sz(g[i]) == 2)
      return cout << "NO" << endl, 0;
  solve();
  cout << "YES" << endl;
  cout << sz(sol) << endl;
  for(auto e : sol)
    cout << e.first.first + 1 << " " << e.first.second + 1 << " " << e.second << endl;
  return 0;
}
