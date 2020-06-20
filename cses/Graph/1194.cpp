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
int step[N][N];
int vis[N][N], fr[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string direction = "UDLR";

bool good(int nx, int ny) {
  return nx >= 0 && nx < n && ny >= 0 && ny < m;
}

int main()
{
  cin >> n >> m;
  queue<pair<int, int>> q;
  pair<int, int> src;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++) {
      step[i][j] = vis[i][j] = -1;
      if(s[i][j] == 'M') {
        q.push({i, j});
        step[i][j] = 0;
      }
      if(s[i][j] == 'A') {
        src = {i, j};
      }
    }
  }
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(good(nx, ny) && step[nx][ny] == -1 && s[nx][ny] != '#') {
        step[nx][ny] = 1 + step[x][y];
        q.push({nx, ny});
      }
    }
  }
  q.push(src);
  vis[src.first][src.second] = 0;
  fr[src.first][src.second] = -1;
  int xx = -1, yy = -1;
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if(x == 0 || y == 0 || x == n - 1 || y == m - 1) {
      xx = x, yy = y;
      break;
    }
    for(int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(good(nx, ny) && vis[nx][ny] == -1 && s[nx][ny] != '#' && (step[nx][ny] == -1 || vis[x][y] + 1 < step[nx][ny])) {
        vis[nx][ny] = 1 + vis[x][y];
        fr[nx][ny] = k;
        q.push({nx, ny});
      }
    }
  }
  if(xx == -1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    string s;
    while(fr[xx][yy] != -1) {
      int d = fr[xx][yy];
      s += direction[d];
      xx -= dx[d];
      yy -= dy[d];
    }
    reverse(all(s));
    cout << sz(s) << endl;
    cout << s << endl;
  }
  return 0;
}
