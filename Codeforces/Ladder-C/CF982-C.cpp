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

int n, ans;
vector<int> g[N];

int dfs(int cur, int par) {
  int sub = 1;
  for(int i = 0 ; i < sz(g[cur]) ; i++) {
    int nxt = g[cur][i];
    if(nxt != par)
      sub += dfs(nxt, cur);
  }
  if(par != -1 && (sub & 1) == 0)
    ans++;
  return sub;
}

int main()
{
  cin >> n;
  for(int i = 1 ; i < n ; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].pb(--b);
    g[b].pb(a);
  }
  if(n & 1)
    return cout << -1 << endl, 0;
  dfs(0, -1);
  cout << ans << endl;
  return 0;
}
