// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e3 + 2;

int n;
vector<int> g[N];
int ans[N], vis[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i + 1 < n ; i++)
    g[i].pb(i + 1), g[i + 1].pb(i);
  int x, y;
  cin >> x >> y;
  y--, x--;
  g[x].pb(y);
  g[y].pb(x);
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++)
      vis[j] = -1;
    queue<int> q;
    q.push(i);
    vis[i] = 0;
    while(q.size()) {
      int u = q.front();
      q.pop();
      ans[vis[u]]++;
      for(int v : g[u]) {
        if(vis[v] == -1) {
          vis[v] = 1 + vis[u];
          q.push(v);
        }
      }
    }
  }
  for(int i = 1 ; i < n ; i++)
    cout << ans[i] / 2 << endl;
  return 0;
}
