// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 8;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int ans[N][N];

bool inGrid(int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < N;
}

int get_neighbors(int x, int y) {
  int res = 0;
  for(int k = 0; k < 8; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    res += inGrid(nx, ny) && ans[nx][ny] == 0;
  }
  return res;
}

bool solve(int cur, int x, int y) {
  if(cur == N * N + 1) return true;
  vector<array<int, 3>> neighbors;
  for(int k = 0; k < 8; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if(inGrid(nx, ny) && ans[nx][ny] == 0) {
      neighbors.push_back({get_neighbors(nx, ny), nx, ny});
    }
  }
  sort(all(neighbors));
  for(int k = 0; k < sz(neighbors); k++) {
    int nx = neighbors[k][1];
    int ny = neighbors[k][2];
    ans[nx][ny] = cur;
    if(solve(cur + 1, nx, ny))
      return true;
    ans[nx][ny] = 0;
  }
  return false;
}

int main()
{
  int x, y;
  cin >> y >> x;
  memset(ans, 0, sizeof ans);
  ans[--x][--y] = 1;
  solve(2, x, y);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
