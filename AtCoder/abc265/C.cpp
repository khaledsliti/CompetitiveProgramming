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

const int N = 507;

int n, m;
string g[N];
int vis[N][N];
string c = "UDLR";
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> g[i];
  }
  auto in = [&](int x, int y) -> bool {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  auto get = [&](int x, int y) -> pair<int, int> {
    for(int k = 0; k < 4; k++) {
      if(g[x][y] == c[k]) {
        return {x + dx[k], y + dy[k]};
      }
    }
    return {-1, -1};
  };
  int x = 0, y = 0;
  vis[0][0] = 1;
  while(true) {
    int nx, ny;
    tie(nx, ny) = get(x, y);
    if(!in(nx, ny)) {
      cout << x + 1 << " " << y + 1 << endl;
      break;
    }
    if(vis[nx][ny]) {
      cout << -1 << endl;
      break;
    }
    vis[nx][ny] = 1;
    tie(x, y) = {nx, ny};
  }
  return 0;
}
