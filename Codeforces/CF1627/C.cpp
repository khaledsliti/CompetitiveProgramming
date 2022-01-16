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

int n, e;
int head[N], to[N], nxt[N];
int deg[N];
int ans[N];

void init() {
  e = 0;
  memset(head, -1, n * sizeof(head[0]));
  memset(deg, 0, n * sizeof(deg[0]));
}

void addEdge(int a, int b) {
  nxt[e] = head[a];
  head[a] = e;
  to[e] = b;
  e++;
}

void dfs(int u, int p, int t) {
  for(int k = head[u]; ~k; k = nxt[k]) {
    int v = to[k];
    if(v != p) {
      ans[k] = ans[k ^ 1] = t;
      dfs(v, u, t ^ 1);
    }
  }
}

void solve() {
  cin >> n;
  init();
  for(int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v; --u, --v;
    addEdge(u, v);
    addEdge(v, u);
    deg[u] += 1;
    deg[v] += 1;
  }
  for(int i = 0; i < n ;i++) {
    if(deg[i] > 2) {
      cout << -1 << endl;
      return;
    }
  }
  for(int i = 0; i < n; i++) {
    if(deg[i] == 1) {
      dfs(i, -1, 0);
      break;
    }
  }
  for(int i = 0; i < e; i += 2) {
    cout << (ans[i] ? 2 : 5) << " ";
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
