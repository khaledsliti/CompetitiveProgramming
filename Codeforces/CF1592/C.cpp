#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e5 + 5;

int n, k;
vector<vector<int>> g;
int a[N];
int sub[N];

void dfs(int u, int p) {
  sub[u] = a[u];
  for(int v: g[u]) {
    if(v != p) {
      dfs(v, u);
      sub[u] ^= sub[v];
    }
  }
}

bool found;
bool dfs2(int u, int p) {
  int cnt = 0;
  for(int v: g[u]) {
    if(v != p) {
      if(dfs2(v, u)) {
        cnt++;
      }
    }
  }
  if(cnt >= 2) {
    found = true;
  }
  if(cnt >= 1 && sub[u] == 0) {
    found = true;
  }
  return cnt >= 1 || sub[u] == sub[0];
}

void solve() {
  g.clear();

  cin >> n >> k;
  g.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);


  if(!sub[0]) {
    cout << "YES" << endl;
    return;
  }
  if(k == 2) {
    cout << "NO" << endl;
    return;
  }
  found = false;
  dfs2(0, -1);
  if(found) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
