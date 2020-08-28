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

int n;
vector<int> g[N];
int vis[N], a[N], par[N], ord[N];

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for(int it = 0; it < n - 1; it++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    ord[a[i]] = i;
  }
  queue<int> q;
  q.push(0);
  vis[0] = 1;
  while(q.empty() == false) {
    int u = q.front();
    q.pop();
    for(int v: g[u]) {
      if(!vis[v]) {
        par[v] = u;
        vis[v] = 1 + vis[u];
        q.push(v);
      }
    }
  }
  bool good = true;
  for(int i = 1; i < n; i++) {
    good &= vis[a[i]] >= vis[a[i - 1]];
  }
  for(int i = 1; i < n; i++) {
    int j = i;
    while(j < n && vis[a[j]] == vis[a[i]])
      ++j;
    for(int k = i + 1; k < j; k++) {
      if(ord[par[a[k - 1]]] > ord[par[a[k]]])
        good = false;
    }
    i = j - 1;
  }
  if(good) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}