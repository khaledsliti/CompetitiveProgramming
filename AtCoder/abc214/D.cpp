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

const int N = 1e5 + 5;

struct Edge {
  int a, b;
  int cost;
  bool operator<(const Edge& rhs) const {
    return cost < rhs.cost;
  }
};

int n;
vector<Edge> edges;
int par[N], siz[N];

int fs(int x) {
  return par[x] == x ? x : par[x] = fs(par[x]);
}

void un(int a, int b) {
  a = fs(a), b = fs(b);
  if(a != b) {
    siz[a] += siz[b];
    par[b] = a;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    edges.push_back({--u, --v, c});
  }

  sort(all(edges));

  for(int i = 0; i < n; i++) {
    par[i] = i;
    siz[i] = 1;
  }

  long long ans = 0;
  for(int i = 0; i < n - 1; i++) {
    int u = edges[i].a, v = edges[i].b;
    u = fs(u), v = fs(v);
    ans += 1LL * edges[i].cost * siz[u] * siz[v];
    un(u, v);
  }
  cout << ans << endl;
  return 0;
}
