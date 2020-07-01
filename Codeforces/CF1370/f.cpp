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

const int N = 1006;

int n, root, path, mxlev = 0;
set<int> g[N];
vector<int> lev[N];

void dfs(int u, int p, int l = 0) {
  lev[l].pb(u);
  mxlev = max(mxlev, l);
  for(int v : g[u]) {
    if(v != p) {
      dfs(v, u, l + 1);
    }
  }
}

void dfs2(int u, int dist, int p, vector<int>& nodes) {
  if(dist == path) {
    nodes.push_back(u);
  }
  for(int v : g[u]) {
    if(v != p) {
      dfs2(v, dist + 1, u, nodes);
    }
  }
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    g[i].clear();
  }
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].insert(b);
    swap(a, b);
    g[a].insert(b);
  }
  cout << "? " << n;
  for(int i = 1; i <= n; i++)
    cout << " " << i;
  cout << endl;
  cout.flush();
  cin >> root >> path;
  --root;
  for(int i = 0; i < n; i++) {
    lev[i].clear();
  }
  mxlev = 0;
  dfs(root, -1);
  int l = 1, r = mxlev, a = -1;
  while(l <= r) {
    int mid = (l + r) / 2;
    cout << "? " << sz(lev[mid]);
    for(int u : lev[mid])
      cout << " " << u + 1;
    cout << endl;
    cout.flush();
    int d, x;
    cin >> x >> d; --x;
    if(d == path) {
      a = x;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  vector<int> nodes;
  dfs2(a, 0, -1, nodes);
  cout << "? " << sz(nodes);
  for(int i = 0; i < sz(nodes); i++)
    cout << " " << nodes[i] + 1;
  cout << endl;
  cout.flush();
  int b, d;
  cin >> b >> d;
  cout << "! " << a + 1 << " " << b << endl;
  string s;
  cin >> s;
  if(s != "Correct")
    exit(0);
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
