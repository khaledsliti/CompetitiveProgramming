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

const int N = 1007;

int n;
int m;
string s[N];
int dist[4][N][N];

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int t = 0; t < 4; t++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        dist[t][i][j] = -1;
      }
    }
  }
  auto in = [&](int x, int n) {
    return x >= 0 && x < n;
  };
  auto go = [&](int t, int x, int y, int dx, int dy) {
    for(int i = x; in(i, n); i += dx) {
      for(int j = y; in(j, m); j += dy) {
        if(s[i][j] == 'B') {
          dist[t][i][j] = 0;
        }
        if(in(i - dx, n) && dist[t][i - dx][j] != -1) {
          dist[t][i][j] = max(dist[t][i][j], 1 + dist[t][i - dx][j]);
        }
        if(in(j - dy, m) && dist[t][i][j - dy] != -1) {
          dist[t][i][j] = max(dist[t][i][j], 1 + dist[t][i][j - dy]);
        }
      }
    }
    // cout << t << ": " << endl;
    // for(int i = 0; i < n; i++) {
    //   for(int j = 0; j < m; j++) {
    //     cout << dist[t][i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << "-------" << endl;
  };
  go(0, 0, 0, 1, 1);
  go(1, 0, m - 1, 1, -1);
  go(2, n - 1, 0, -1, 1);
  go(3, n - 1, m - 1, -1, -1);
  int ans = INT_MAX;
  int x, y;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int cur = -1;
      for(int t = 0; t < 4; t++) {
        cur = max(cur, dist[t][i][j]);
      }
      if(ans > cur) {
        ans = cur;
        x = i + 1, y = j + 1;
      }
      ans = min(ans, cur);
    }
  }
  cout << x << " " << y << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
