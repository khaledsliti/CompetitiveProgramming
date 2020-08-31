#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e3, M = 1e4;
const int L = 1024;

int n, m, s, d;
vector<pair<int, int>> g[N];
int vis[N][L];

void dfs(int u, int cost) {
  vis[u][cost] = 1;
  for(auto e: g[u]) {
    int v = e.first;
    int c = e.second;
    if(!vis[v][cost | c]) {
      dfs(v, cost | c);
    }
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a, --b;
    g[a].pb({b, c});
    g[b].pb({a, c});
  }
  scanf("%d%d", &s, &d);
  --s, --d;
  dfs(s, 0);
  for(int i = 0; i < L; i++) {
    if(vis[d][i]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
