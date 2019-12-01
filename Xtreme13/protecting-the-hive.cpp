#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;

int n, m;
int grid[N][N];
int par[N * N], cnt[N * N];

int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[2][6] = {{-1, 0, -1, 1, -1, 0}, {0, 1, -1, 1, 0, 1}};

bool good(int nx, int ny)
{
  return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}

int get_index(int i, int j)
{
  return i * m + j;
}

int fs(int x)
{
  return x == par[x] ? x : par[x] = fs(par[x]);
}

void us(int i, int j)
{
  i = fs(i);
  j = fs(j);
  if(i != j){
    par[i] = j;
    cnt[j] += cnt[i];
  }
}

void init()
{
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < m ; j++){
      int idx = get_index(i, j);
      par[idx] = idx;
      if(grid[i][j])
        for(int k = 0 ; k < 6 ; k++){
          int nx = i + dx[k];
          int ny = j + dy[i & 1][k];
          if(!good(nx, ny) || !grid[nx][ny])
            cnt[idx]++;
        }
    }
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      if(!grid[i][j])
        continue;
      int idx1 = get_index(i, j);
      for(int k = 0 ; k < 6 ; k++){
        int nx = i + dx[k];
        int ny = j + dy[i & 1][k];
        if(!good(nx, ny) || !grid[nx][ny])
          continue;
        int idx2 = get_index(nx, ny);
        us(idx1, idx2);
      }
    }
  }
}

int query(int x, int y)
{
  int idx = get_index(x, y);
  idx = fs(idx);
  return cnt[idx];
}

void update(int x, int y)
{
  if(grid[x][y])
    return;
  grid[x][y] = 1;
  int empty = 0;
  map<int, int> comp;
  set<int> sets;
  for(int k = 0 ; k < 6 ; k++){
    int nx = x + dx[k];
    int ny = y + dy[x & 1][k];
    if(!good(nx, ny) || !grid[nx][ny]){
      empty++;
    }else{
      int idx = get_index(nx, ny);
      comp[fs(idx)]++;
      sets.insert(fs(idx));
    }
  }
  int idx = get_index(x, y);
  assert(fs(idx) == idx);
  for(auto adj : sets){
    par[adj] = idx;
    cnt[idx] += cnt[adj] - comp[adj];
  }
  cnt[idx] += empty;
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m - 1 ; j++)
      scanf("%d", &grid[i][j]);
    if(!(i & 1))
      scanf("%d", &grid[i][m - 1]);
  }
  init();
  int q;
  scanf("%d", &q);
  while(q--){
    char t;
    int x, y;
    scanf(" %c%d%d", &t, &x, &y);
    --x, --y;
    if(t == 'k')
      printf("%d\n", query(x, y));
    else
      update(x, y);
  }
  return 0;
}
