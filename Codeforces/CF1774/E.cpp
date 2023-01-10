// RedStone
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

const int N = 2e5 + 4;
const int L = 18;

int n, d;
vector<int> g[N];
int anc[N][L], lev[N];
int need[2][N];

void dfs1(int u, int p) {
  anc[u][0] = p;
  for (int j = 1; j < L; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v != p) {
      lev[v] = 1 + lev[u];
      dfs1(v, u);
    }
  }
}

int getLCA(int a, int b) {
  if (lev[a] < lev[b]) swap(a, b);
  int lg = 0;
  for (; (1 << lg) <= lev[a]; lg++)
    ;
  lg--;
  for (int i = lg; i >= 0; i--)
    if (lev[a] - (1 << i) >= lev[b]) a = anc[a][i];
  if (a == b) return a;
  for (int i = lg; i >= 0; i--)
    if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
  return anc[a][0];
}

int kthAnc(int u, int k) {
  for (int j = L - 1; j >= 0 && u > -1; j--) {
    if (k & (1 << j)) {
      u = anc[u][j];
    }
  }
  return u;
}

void calcNeed(int u, int p) {
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v != p) {
      calcNeed(v, u);
      need[0][u] |= need[0][v];
      need[1][u] |= need[1][v];
    }
  }
}

int calcAns(int u, int p, int t) {
  int ret = 0;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v == p || !need[t][v]) continue;
    ret++;
    ret += calcAns(v, u, t);
    ret++;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> d;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }

  for (int i = 0; i < 2; i++) {
    int m;
    cin >> m;
    while (m--) {
      int u;
      cin >> u;
      need[i][--u] = 1;
    }
  }

  dfs1(0, -1);
  for (int p = 0; p < 2; p++) {
    for (int i = 0; i < n; i++) {
      if (need[p][i] && !need[p ^ 1][i]) {
        int par = kthAnc(i, d);
        if (par != -1) {
          need[p ^ 1][par] = 1;
        }
      }
    }
  }

  calcNeed(0, -1);

  // for (int p = 0; p < 2; p++) {
  //   for (int i = 0; i < n; i++) {
  //     cout << need[p][i] << " ";
  //   }
  //   cout << endl;
  // }

  // cout << calcAns(0, -1, 0) << endl;

  cout << calcAns(0, -1, 0) + calcAns(0, -1, 1) << endl;
  return 0;
}
