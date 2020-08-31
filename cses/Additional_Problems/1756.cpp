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
int a[N], b[N], ord[N], vis[N], cur_idx;

void dfs(int u, int p) {
  vis[u] = 1;
  ord[u] = cur_idx++;
  for(int v: g[u]) {
    if(v != p && vis[v] == 0) {
      dfs(v, u);
    }
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    g[--a[i]].push_back(--b[i]);
    g[b[i]].push_back(a[i]);
  }
  for(int i = 0; i < n; i++) {
    if(vis[i] == 0) {
      dfs(i, -1);
    }
  }
  for(int i = 0; i < m; i++) {
    int x = a[i], y = b[i];
    if(ord[x] > ord[y]) {
      swap(x, y);
    }
    cout << x + 1 << " " << y + 1 << endl;
  }
  return 0;
}
