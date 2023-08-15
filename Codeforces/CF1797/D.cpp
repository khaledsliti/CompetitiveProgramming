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

const int N = 1e5 + 5;

struct Son {
  int index;
  int size;

  bool operator<(const Son& other) const {
    if (size != other.size) {
      return size > other.size;
    }
    return index < other.index;
  }
};

int n, m;
vector<int> g[N];
int sub[N];
long long sum[N];
set<Son> sons[N];
int par[N];

void dfs(int u, int p) {
  par[u] = p;
  sub[u] = 1;
  for (int v : g[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    sum[u] += sum[v];
    sub[u] += sub[v];
    sons[u].insert({v, sub[v]});
  }
}

int getSon(int u) {
  if (sons[u].size() == 0) {
    return -1;
  }
  return sons[u].begin()->index;
}

void printSons(int u) {
  cout << "Sons of " << u + 1 << endl;
  for (auto x: sons[u]) {
    cout << x.index + 1 << " " << x.size << endl;
  }
}

void printNode(int u) {
  cout << "debug " << u + 1 << endl;
  cout << u + 1 << " " << par[u] + 1 << " " << sub[u] << " " << sum[u] << endl;
  printSons(u);
}

void rot(int u) {
  int p = par[u];
  if (sons[u].size() == 0) {
    return;
  }
  int s = sons[u].begin()->index;
  // update subtree sizes and sums
  int newSubU = sub[u] - sub[s];
  int newSubS = sub[u];

  // update sons
  sons[u].erase({s, sub[s]});
  sons[s].insert({u, newSubU});
  sons[p].erase({u, sub[u]});
  sons[p].insert({s, newSubS});
  
  par[u] = s;
  par[s] = p;
  
  sub[u] = newSubU;
  sub[s] = newSubS;

  long long newSumU = sum[u] - sum[s];
  long long newSumS = sum[u];
  sum[u] = newSumU;
  sum[s] = newSumS;

  // debug
  // printNode(u);
  // printNode(s);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> sum[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0, -1);

  while(q--) {
    int t, x;
    cin >> t >> x;
    --x;
    if (t == 1) {
      cout << sum[x] << endl;
      continue;
    }
    rot(x);
  }
  return 0;
}
