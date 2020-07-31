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

int n;
int a[N], b[N], in[N], vis[N];
vector<int> g[N];
ll sub[N];
ll ans;
vector<vector<int>> sol;
vector<int> tmp;

void dfs2(int u, int depth) {
  vis[u] = 1;
  ans += 1LL * depth * a[u];
  for(int v : g[u]) {
    if(!vis[v]) {
      dfs2(v, depth + 1);
    }
  }
  tmp.push_back(u);
}

void dfs(int u) {
  sub[u] = a[u];
  for(int v : g[u]) {
    dfs(v);
    if(sub[v] >= 0){ 
      sub[u] += sub[v];
    }
  }
  if(sub[u] < 0) {
    tmp.clear();
    dfs2(u, 1);
    sol.push_back(tmp);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    if(b[i] == -1) continue;
    --b[i];
    g[b[i]].push_back(i);
    in[i]++;
  }
  for(int i = 0; i < n; i++)
    if(!in[i]) {
      dfs(i);
      if(sub[i] >= 0) {
        tmp.clear();
        dfs2(i, 1);
        sol.push_back(tmp);
      }
    }

  cout << ans << endl;
  for(int i = sz(sol) - 1; i >= 0; i--) {
    for(int v: sol[i])
      cout << v + 1 << " ";
  }
  cout << endl;

  return 0;
}
