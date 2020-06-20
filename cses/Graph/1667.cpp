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
vector<int> g[N];
int vis[N], fr[N];

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
  memset(vis, -1, sizeof vis);
  queue<int> q;
  q.push(0);
  vis[0] = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v : g[u]) {
      if(vis[v] == -1) {
        vis[v] = 1 + vis[u];
        fr[v] = u;
        q.push(v);
      }
    }
  }
  if(vis[n - 1] == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << vis[n - 1] + 1 << endl;
    vector<int> route;
    for(int cur = n - 1; cur != 0; cur = fr[cur])
      route.push_back(cur + 1);
    route.push_back(1);
    reverse(all(route));
    for(int i = 0; i < sz(route); i++)
      cout << route[i] << " ";
    cout << endl;
  }
  return 0;
}
