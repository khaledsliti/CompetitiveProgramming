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

int n, m;
vector<int> g[N];
int vis[N];

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
  priority_queue<int> pq;
  pq.push(0);
  vis[0] = 1;
  while(!pq.empty()) {
    int u = -pq.top();
    pq.pop();
    cout << u + 1 << " ";
    for(int v : g[u]) {
      if(!vis[v]) {
        vis[v] = 1;
        pq.push(-v);
      }
    }
  }
  return 0;
}
