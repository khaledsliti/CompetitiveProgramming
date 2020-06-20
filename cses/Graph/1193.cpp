// We only fail when we stop trying
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

const int N = 1001;

int n, m;
string s[N];
int vis[N][N], dir[N][N];
int rooms;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string direction = "UDLR";

bool good(int nx, int ny) {
  return nx >= 0 && nx < n && ny >= 0 && ny < m;
}

int main()
{
  cin >> n >> m;
  int xs, ys, xd, yd;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'A') {
        s[i][j] = '.';
        xs = i, ys = j;
      } else if(s[i][j] == 'B') {
        s[i][j] = '.';
        xd = i, yd = j;
      }
      vis[i][j] = -1;
    }
  }
  queue<pair<int, int>> q;
  q.push({xs, ys});
  vis[xs][ys] = 0;
  dir[xs][ys] = -1;
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(good(nx, ny) && vis[nx][ny] == -1 && s[nx][ny] == '.') {
        q.push({nx, ny});
        vis[nx][ny] = 1 + vis[x][y];
        dir[nx][ny] = k;
      }
    }
  }
  if(vis[xd][yd] == -1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    string sol;
    int x = xd, y = yd;
    cout << vis[x][y] << endl;
    while(x != xs || y != ys) {
      int d = dir[x][y];
      sol += direction[d];
      x -= dx[d];
      y -= dy[d];
    }
    reverse(all(sol));
    cout << sol << endl;
  }
  return 0; 
}
