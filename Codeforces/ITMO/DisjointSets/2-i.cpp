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
  
  cin >> n >> m;
  iota(par, par + n, 0);

  int shift = 0;
  while(m--) {
    int t, a, b;
    cin >> t >> a >> b;
    --a, --b;
    int x = (a + shift) % n;
    int y = (b + shift) % n;
    // cout << x << " " << y << endl;
    // for(int i = 0; i < n; i++) {
    //   find(i);
    //   cout << dist[i] << " ";
    // }
    // cout << endl;
    if(t == 0) {
      unite(x, y);
    } else {
      int px = find(x), py = find(y);
      if(dist[x] == dist[y]) {
        cout << "YES" << endl;
        shift = (shift + 1) % n;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
