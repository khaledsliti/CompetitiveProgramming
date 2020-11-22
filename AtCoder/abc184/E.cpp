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

const int N = 2007;

int n, m;
string s[N];
int vis[N][N], vis_a[N];
vector<pair<int, int>> pos[26];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool in(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  memset(vis_a, -1, sizeof vis_a);
  memset(vis, -1, sizeof vis);
  queue<pair<int, int>> q;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'S') {
        q.push({i, j});
        vis[i][j] = 0;
      } else if(s[i][j] >= 'a' && s[i][j] <= 'z') {
        pos[s[i][j] - 'a'].pb({i, j});
      }
    }
  }

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if(s[x][y] == 'G') {
      cout << vis[x][y] << endl;
      return 0;
    }
    for(int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(in(nx, ny) && s[nx][ny] != '#' && vis[nx][ny] == -1) {
        vis[nx][ny] = 1 + vis[x][y];
        q.push({nx, ny});
      }
    }
    if(s[x][y] >= 'a' && s[x][y] <= 'z') {
      int c = s[x][y] - 'a';
      if(vis_a[c] == -1) {
        vis_a[c] = 0;
        for(auto c: pos[s[x][y] - 'a']) {
          int nx = c.first, ny = c.second;
          if(vis[nx][ny] == -1) {
            vis[nx][ny] = 1 + vis[x][y];
            q.push({nx, ny});
          }
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
