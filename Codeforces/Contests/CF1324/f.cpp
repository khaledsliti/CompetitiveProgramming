// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5, E = 4e5 + 5;

int n, e;
int col[N];
int nxt[E], head[N], to[E];
int sub[N], ans[N];

void init() {
  e = 0;
  memset(head, -1, n * sizeof (head[0]));
}

void addEdge(int f, int t) {
  nxt[e] = head[f];
  head[f] = e;
  to[e++] = t;
}

int dfs0(int u, int p) {
  sub[u] = col[u];
  for(int k = head[u] ; ~k ; k = nxt[k]) {
    int v = to[k];
    if(v == p) continue;
    sub[u] += dfs0(v, u);
  }
  sub[u] = max(0, sub[u]);
  return sub[u];
}

void dfs(int u, int par, int parValue) {
  int sum = 0;
  for(int k = head[u] ; ~k ; k = nxt[k]) {
    int v = to[k];
    if(v == par) continue;
    sum += sub[v];
  }
  ans[u] = sum + col[u] + parValue;
  for(int k = head[u] ; ~k ; k = nxt[k]) {
    int v = to[k];
    if(v == par) continue;
    int nxt = max(0, parValue + col[u] + sum - sub[v]);
    dfs(v, u, nxt);
  }
}

int main()
{
  scanf("%d", &n);
  init();
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", col + i);
    if(!col[i]) col[i] = -1;
  }
  for(int i = 1 ; i < n ;i++) {
    int a, b; scanf("%d%d", &a, &b);
    addEdge(--a, --b);
    addEdge(b, a);
  }
  dfs0(0, -1);
  dfs(0, -1, 0);
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
