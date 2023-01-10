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

const int N = 51;

int n, m, d;
char s[N][N][N];
int vis[N][N][N];

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int in(int x, int y, int z) {
  vector<int> p {x, y, z};
  vector<int> lim {n, m, d};
  for(int i = 0; i < 3; i++) {
    if(p[i] < 0 || p[i] >= lim[i]) {
      return false;
    }
  }
  return true;
}

int dfs(int x, int y, int z) {
  int ret = s[x][y][z] == 'o' ? 2 : 3;
  vis[x][y][z] = 1;
  for(int dir = 0; dir < 6; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    int nz = z + dz[dir];
    if(in(nx, ny, nz) && s[nx][ny][nz] != '#' && !vis[nx][ny][nz]) {
      ret += dfs(nx, ny, nz);
    }
  }
  return ret;
}

void solve() {
  cin >> n >> m >> d;
  for(int k = 0; k < d; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> s[i][j][k];
        vis[i][j][k] = 0;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      for(int k = 0; k < d; k++) {
        if(vis[i][j][k] == 0 && s[i][j][k] != '#') {
          int cur = dfs(i, j, k);
          // cout << i << " " << j << " " << k << " " << cur << endl;
          if (cur & 1) {
            cout << "NO" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "YES" << endl;
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
