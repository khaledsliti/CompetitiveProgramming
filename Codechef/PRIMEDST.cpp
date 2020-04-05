// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 50003;

int n;
vector<int> g[N];
int sub[N], ok[N];

int dist[N], isp[N];
vector<int> pr;

void get_sz(int u, int p) {
  sub[u] = 1;
  for(int v : g[u]) {
    if(v != p && ok[v]) {
      get_sz(v, u);
      sub[u] += sub[v];
    }
  }
}

int find_centroid(int u, int p, int tot) {
  for(int v : g[u])
    if(v != p && ok[v] && sub[v] > tot / 2)
      return find_centroid(v, u, tot);
  return u;
}

void dfs(int u, int p, int d, int val) {
  dist[d] += val;
  for(int v : g[u]) {
    if(v != p && ok[v]) {
      dfs(v, u, d + 1, val);
    }
  }
}

long long dfs2(int u, int p, int d) {
  long long res = 0;
  for(int p : pr) {
    if(p >= d) {
      res += dist[p - d];
    }
  }
  for(int v : g[u])
    if(v != p && ok[v]) {
      res += dfs2(v, u, d + 1);
    }
  return res;
}

long long decompose(int u) {
  get_sz(u, -1);
  int c = find_centroid(u, -1, sub[u]);
  for(int i = 0 ; i < sub[u] ; i++)
    dist[i] = 0;
  dfs(c, -1, 0, 1);
  long long res = 0;
  ok[c] = 0;
  for(int v : g[c])
    if(ok[v]) {
      dfs(v, c, 1, -1);
      res += dfs2(v, c, 1);
    }
  for(int v : g[c]) {
    if(ok[v]) {
      res += decompose(v);
    }
  }
  return res;
}

long long centroid_decomp() {
  for(int i = 0 ; i < n ; i++)
    ok[i] = 1;
  return decompose(0);
}

int main()
{
  for(int i = 2 ; i < N ; i++) {
    if(!isp[i]) {
      pr.pb(i);
      for(int j = 2 * i ; j < N ; j += i)
        isp[j] = 1;
    }
  }
  scanf("%d", &n);
  for(int i = 0 ; i < n - 1 ; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, b--;
    g[a].pb(b);
    swap(a, b);
    g[a].pb(b);
  }
  long long sum = centroid_decomp();
  long long tot = 1LL * n * (n - 1) / 2;
  cout << fixed << setprecision(10) << 1.0 * sum / tot << endl; 
  return 0;
}
