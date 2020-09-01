// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 5;

int n;
vector<int> leaves, g[N];
vector<pair<int, int>> sol;

int dfs(int u, int p) {
  if(sz(g[u]) == 1) {
    return u;
  }
  vector<int> cur;
  for(int v: g[u]) {
    if(v != p) {
      cur.push_back(dfs(v, u));
    }
  }
  for(int i = 0; i < sz(cur) - 1; i += 2) {
    sol.push_back({cur[i], cur[i + 1]});
  }
  if(sz(cur) & 1) {
    sol.push_back({cur[0], cur[sz(cur) - 1]});
  }
  return cur.back();
}

int main()
{
  cin >> n;
  int root;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
    for(int u: {a, b}) {
      if(sz(g[u]) > 1) {
        root = u;
      }
    }
  }
  cout << root + 1 << endl;
  dfs(root, -1);
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    cout << sol[i].first + 1 << " " << sol[i].second + 1 << endl;
  }
  return 0;
}
