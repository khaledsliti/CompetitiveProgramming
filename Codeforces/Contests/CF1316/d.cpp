// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second

const int N = 1005;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, comp;
pair<int, int> arr[N][N];
int vis[N][N];
pair<int, int> par[N][N];
char sol[N][N];

bool good(int nx, int ny)
{
  return nx >= 0 && nx < n && ny >= 0 && ny < n;
}

void print_sol(int nx, int ny, int x, int y)
{
  assert(abs(nx - x) + abs(ny - y) <= 1);
  if(nx == x && ny == y) sol[nx][ny] = 'X';
  if(nx == x - 1) sol[nx][ny] = 'D';
  if(nx == x + 1) sol[nx][ny] = 'U';
  if(ny == y - 1) sol[nx][ny] = 'R';
  if(ny == y + 1) sol[nx][ny] = 'L';
}

void bfs(vector<pair<int,int>> src, pair<int, int> val)
{
  comp++;
  queue<pair<int, int>> q;
  for(int i = 0 ; i < sz(src) ; i++) {
    vis[src[i].X][src[i].Y] = comp;
    q.push(src[i]);
  }
  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();
    for(int k = 0 ; k < 4 ; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(good(nx, ny) && !vis[nx][ny] && arr[nx][ny] == val) {
        print_sol(nx, ny, x, y);
        vis[nx][ny] = comp;
        q.push({nx, ny});
      }
    }
  }
}

bool invalid()
{
  for(int i = 0 ; i < n; i++) {
    for(int j = 0 ; j < n ; j++) {
      if(!vis[i][j]) {
        return true;
      }
    }
  }
  return false;
}

bool has_good_nei(int x, int y, int& out_x, int& out_y)
{
  for(int k = 0 ; k < 4 ; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if(good(nx, ny) && arr[nx][ny] == arr[x][y] && !vis[nx][ny]){
      out_x = nx;
      out_y = ny;
      return true;
    }
  }
  return false;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++) {
      scanf("%d%d", &arr[i][j].X, &arr[i][j].Y);
      if(arr[i][j].X != -1) {
        --arr[i][j].X; --arr[i][j].Y;
      }
      sol[i][j] = '.';
    }
  }
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++) {
      if(arr[i][j].X == i && arr[i][j].Y == j && !vis[i][j]) {
        print_sol(i, j, i, j);
        bfs({{i, j}}, arr[i][j]);
      }
    }
  }
  // for(int i = 0 ; i < n  ; i++) {
  //   for(int j = 0 ; j < n ; j++)
  //     cout << arr[i][j].X << " " << arr[i][j].Y << " ";
  //   cout << endl;
  // }
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++) {
      int nx, ny;
      if(arr[i][j].X == -1 && !vis[i][j] && has_good_nei(i, j, nx, ny)) {
        print_sol(i, j, nx, ny);
        print_sol(nx, ny, i, j);
        bfs({ {i, j}, {nx, ny} }, {-1, -1});
      }
    }
  }
  // for(int i = 0 ; i < n ; i++) {
  //   for(int j = 0 ; j < n ; j++)
  //     cout << vis[i][j] << " ";
  //   cout << endl;
  // } 
  // for(int i = 0 ; i < n ; i++) {
  //   for(int j = 0 ; j < n ; j++)
  //     cout << sol[i][j] << " ";
  //     cout << endl;
  // } 
  if(invalid())
    return cout << "INVALID" << endl, 0;
  printf("VALID\n");
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++)
      printf("%c", sol[i][j]);
    printf("\n");
  }
  return 0;
}
