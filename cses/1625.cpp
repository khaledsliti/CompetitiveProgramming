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

const int N = 7;

int vis[N][N], col[N][N], vid;
string path;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string dir = "UDLR";

bool good(int nx, int ny) {
  return nx >= 0 && nx < N && ny >= 0 && ny < N;
}

bool empty(int x, int y) {
  return good(x, y) && !vis[x][y];
}

int dfs(int i, int x, int y) {
  if(x == N - 1 && y == 0) return i == sz(path);
  if((empty(x - 1, y) && empty(x + 1, y) && !empty(x, y - 1) && !empty(x, y + 1)) ||
    (!empty(x - 1, y) && !empty(x + 1, y) && empty(x, y - 1) && empty(x, y + 1)))
      return 0;
  vis[x][y] = 1;
  int res = 0;
  for(int d = 0; d < 4; d++) {
    if(path[i] == '?' || path[i] == dir[d]) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if(good(nx, ny) && !vis[nx][ny]) {
        res += dfs(i + 1, nx, ny);
      }
    }
  }
  vis[x][y] = 0;
  return res;
}

int main()
{
  cin >> path;
  cout << dfs(0, 0, 0) << endl;
  return 0;
}
