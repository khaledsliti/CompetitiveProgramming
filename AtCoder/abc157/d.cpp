// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, m, k;
vector<int> g[N];
int par[N], comp[N], deg[N];

int fs(int x) {
  return par[x] == x ? x : par[x] = fs(par[x]);
}

int main()
{
  cin >> n >> m >> k;
  for(int i = 0 ; i < n ; i++)
    par[i] = i, comp[i] = 1;
  for(int i = 0 ; i < m ; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ++deg[a], ++deg[b];
    a = fs(a);
    b = fs(b);
    if(a != b) {
      par[a] = b;
      comp[b] += comp[a];
    }
  }
  for(int i = 0 ; i < k ; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    swap(a, b);
    g[a].pb(b);
  }
  for(int i = 0 ; i < n ; i++) {
    int ans = comp[fs(i)] - 1 - deg[i];
    for(int j : g[i])
      if(fs(i) == fs(j))
        ans--;
    cout << ans << " ";
  }
  return 0;
}
