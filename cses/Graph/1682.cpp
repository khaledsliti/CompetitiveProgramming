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

const int N = 2e5 + 5;

int n, m;
vector<pair<int, int>> ed;
vector<int> g[N];
int vis[N];

void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = 1;
  for(int nxt: g[cur]) {
    dfs(nxt);
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ed.pb({--a, --b});
  }
  for(int it = 0; it < 2; it++) {
    for(int i = 0; i < n; i++)
      g[i].clear(), vis[i] = 0;
    for(int i = 0; i < m; i++) {
      int a = ed[i].first, b = ed[i].second;
      g[a].pb(b);
    }
    dfs(0);
    int idx = -1;
    for(int i = 0; i < n; i++)
      if(!vis[i]) {
        int a = 1, b = i + 1;
        if(it) swap(a, b);
        cout << "NO" << endl;
        cout << a << " " << b << endl;
        return 0;
      }
    for(int i = 0; i < m; i++)
      swap(ed[i].first, ed[i].second);
  }
  cout << "YES" << endl;
  return 0;
}
