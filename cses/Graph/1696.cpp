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

const int N = 501;

int n, m;
vector<int> g[N];
int match[N], vis[N], visId;

bool can_match(int u) {
  vis[u] = visId;
  for(int v: g[u]) {
    if(match[v] == -1 || vis[match[v]] != visId && can_match(match[v])) {
      match[v] = u;
      return true;
    }
  }
  return false;
}

int max_matching() {
  int res = 0;
  memset(match, -1, sizeof match);
  for(int i = 0; i < n; i++) {
    visId++;
    if(can_match(i)) {
      res++;
    }
  }
  return res;
}

int main()
{
  int e;
  cin >> n >> m >> e;
  for(int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
  }
  cout << max_matching() << endl;
  for(int i = 0; i < m; i++) {
    if(match[i] != -1)
      cout << match[i] + 1 << " " << i + 1 << endl;
  }
  return 0;
}
