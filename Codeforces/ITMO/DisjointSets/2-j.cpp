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

const int N = 3e5 + 5;

int n, m;
int par[N];
int dist[N];

int find(int x) {
  int p = par[x];
  if(p == x) return p;
  int nw = find(p);
  dist[x] ^= dist[p];
  par[x] = nw;
  return nw;
}

void unite(int a, int b) {
  int pa = find(a), pb = find(b);
  par[pa] = pb;
  dist[pa] = dist[a] ^ 1 ^ dist[b];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  iota(par, par + n, 0);

  for(int idx = 1; idx <= m; idx++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if(find(a) == find(b)) {
      if(dist[a] == dist[b]) {
        cout << idx << endl;
        return 0;
      }
    } else {
      unite(a, b);
    }
  }
  cout << -1 << endl;
  return 0;
}
