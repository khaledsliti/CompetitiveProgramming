#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
vector<int> g[N];

double dfs(int cur, int p)
{
  if(sz(g[cur]) - (p != -1) == 0)
    return 0;
  double pr = 1.0 / (sz(g[cur]) - (p != -1));
  double res = 0.0;
  for(int i = 0 ; i < sz(g[cur]) ; i++){
    int v = g[cur][i];
    if(v != p){
      res += pr * (1 + dfs(v, cur));
    }
  }
  return res;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n - 1 ; i ++){
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  cout << fixed << setprecision(10) << dfs(0, -1) << endl;
  return 0;
}
