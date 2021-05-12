// Guess Who's Back
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

int n, centroid;
int siz[N];
vector<int> g[N];

void dfs(int u, int p) {
  siz[u] = 1;
  for(int v: g[u]) {
    if(v != p) {
      dfs(v, u);
      siz[u] += siz[v];
    }
  }
  int mx = n - siz[u];
  for(int v: g[u]) {
    if(v != p) {
      mx = max(mx, siz[v]);
    }
  }
  if(2 * mx <= n)
    centroid = u;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  cout << centroid + 1 << endl;
  return 0;
}
