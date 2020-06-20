// We only fail when we stop trying
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

const int N = 2e5 + 5;

int n, m;
int col[N];
vector<int> g[N];

bool dfs(int u, int p) {
  for(int v : g[u]) {
    if(v == p) continue;
    if(col[v] == -1) {
      col[v] = !col[u];
      if(!dfs(v, u))
        return false;
    } else if(col[u] == col[v])
      return false;
  }
  return true;
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  memset(col, -1, sizeof col);
  for(int i = 0; i < n; i++) {
    if(col[i] == -1) {
      col[i] = 0;
      if(!dfs(i, i)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }
  for(int i = 0; i < n; i++)
    cout << col[i] + 1 << " ";
  cout << endl;
  return 0;
}
