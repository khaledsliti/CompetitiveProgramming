// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e3 + 6;

int n;
int sol[N];
int dist[N];
vector<int> g[N];

void add(int x) {
  if (x < 2 || x > 2 * n) {
    return;
  }
  cout << "+ " << x << endl;
  int r;
  cin >> r;
  if (r != 1) {
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    int j = x - i;
    if (j < 1 || j > n || j >= i) {
      continue;
    }
    g[i].push_back(j);
    g[j].push_back(i);
  }
}

int ask(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int r;
  cin >> r;
  if (r < -1) {
    exit(0);
  }
  return r;
}

void dfs(int u, int p, vector<int>& nodes) {
  nodes.push_back(u);
  for (int v : g[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u, nodes);
  }
}

void Solve() {
  cin >> n;
  if (n == 2) {
    cout << "! 1 2 2 1" << endl;
    int r;
    cin >> r;
    if (r != 1) {
      exit(0);
    }
    return;
  }

  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  if (n & 1) {
    add(n + 1);
    add(n);
  } else {
    add(n + 1);
    add(n - 1);
  }

  int far = 1;
  dist[1] = 0;
  for (int i = 2; i <= n; i++) {
    dist[i] = ask(1, i);
    if (dist[far] < dist[i]) {
      far = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i == far) {
      dist[i] = 0;
      continue;
    }
    dist[i] = ask(far, i);
  }
  
  vector<int> nodes;
  dfs(n, -1, nodes);

  vector<int> idx(n + 1);
  for (int i = 1; i <= n; i++) {
    idx[dist[i] + 1] = i;
  }

  cout << "!";
  for (int i = 1; i <= n; i++) {
    sol[idx[i]] = nodes[i-1];
  }
  for (int i = 1; i <= n; i++) {
    cout << " " << sol[i];
  }

  reverse(all(nodes));
  for (int i = 1; i <= n; i++) {
    sol[idx[i]] = nodes[i-1];
  }
  for (int i = 1; i <= n; i++) {
    cout << " " << sol[i];
  }
  cout << endl;
  int r;
  cin >> r;
  if (r != 1) {
    exit(0);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
  return 0;
}
