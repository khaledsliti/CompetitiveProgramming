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
#define F first
#define S second

int n, m, k;
pair<int, int> src, dst;
vector<vector<char>> grid;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<vector<pair<int, int>>> nxt[4];
vector<vector<int>> vis;

int dist(int x, int y, int nx, int ny) {
  return abs(x - nx) + abs(y - ny);
}

bool good(int nx, int ny) {
  return nx >= 0 && nx < n && ny >= 0 && ny < m;
}

pair<int, int> find_nxt(int d, int x, int y) {
  if(!good(x, y)) return {x, y};
  if(nxt[d][x][y] == mp(x, y)) return {x, y};
  int nx = nxt[d][x][y].F, ny = nxt[d][x][y].S;
  return nxt[d][x][y] = find_nxt(d, nx, ny);
}

void update_nxt(int x, int y) {
  for(int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    nxt[d][x][y] = {nx, ny};
  }
}

int main()
{
  ios::sync_with_stdio(false);
  
  cin >> n >> m >> k;
  cin >> src.F >> src.S >> dst.F >> dst.S;
  src.F--, src.S--, dst.F--, dst.S--;
  grid.resize(n, vector<char>(m));
  cin.ignore();
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m ;j++)  {
      cin >> grid[i][j];
    }
  }
  for(int i = 0; i < 4; i++)
    nxt[i].resize(n, vector<pair<int, int>>(m));
  for(int d = 0; d < 4; d++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        nxt[d][i][j] = {i, j};
      }
    }
  }
  vis.resize(n, vector<int>(m, -1));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(grid[i][j] == '@') {
        vis[i][j] = 0;
        for(int d = 0; d < 4; d++)
          nxt[d][i][j] = {-1, -1}; // out
      }
    }
  }
  
  queue<pair<int, int>> q;
  q.push(src);
  vis[src.F][src.S] = 0;
  update_nxt(src.F, src.S);

  while(!q.empty()) {
    int x = q.front().F;
    int y = q.front().S;
    q.pop();
    if(mp(x, y) == dst)
      break;
    for(int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      auto cell = find_nxt(d, nx, ny);
      nx = cell.F, ny = cell.S;
      while(good(nx, ny) && dist(x, y, nx, ny) <= k) {
        vis[nx][ny] = 1 + vis[x][y];
        update_nxt(nx, ny);
        q.push({nx, ny});
        cell = find_nxt(d, nx, ny);
        nx = cell.F, ny = cell.S;
      }
    }
  }
  cout << vis[dst.F][dst.S] << endl;
  return 0;
}
