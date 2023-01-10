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

template <int N>
struct DSU {
  int n;
  int par[N], size[N];
  int comp;
  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) {
      par[i] = i;
      size[i] = 1;
    }
    comp = n;
  }
  int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
  int getSize(int x) { return size[find(x)]; }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      par[x] = y;
      size[y] += size[x];
      comp--;
      return true;
    }
    return false;
  }
};

const int N = 1e6 + 5;

int n, m;
vector<string> s;
DSU<N> d;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool in(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

int get(int i, int j) { return i * m + j; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  d.init(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '.') continue;
      if (i + 1 < n && s[i + 1][j] == '.') {
        d.unite(get(i, j), get(i + 1, j));
      }
      if (j + 1 < m && s[i][j + 1] == '.') {
        d.unite(get(i, j), get(i, j + 1));
      }
    }
  }

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < m; j++) {
  //     cout << d.find(get(i, j)) << " ";
  //   }
  //   cout << endl;
  // }

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (s[x][y] != 'S') continue;
      for (int d1 = 0; d1 < 4; d1++) {
        int x1 = x + dx[d1];
        int y1 = y + dy[d1];
        if (!in(x1, y1) || s[x1][y1] != '.') continue;
        for (int d2 = 0; d2 < 4; d2++) {
          if(d1 == d2) continue;
          int x2 = x + dx[d2];
          int y2 = y + dy[d2];
          if (!in(x2, y2) || s[x2][y2] != '.') continue;
          if(d.find(get(x1, y1)) == d.find(get(x2, y2))) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
