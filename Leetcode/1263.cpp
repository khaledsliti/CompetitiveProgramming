#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using P = pair<int, int>;
using node = pair<P, P>;
#define F first
#define S second
#define get(vis, x) vis[x.first.first][x.first.second][x.second.first][x.second.second]
#define print(cur) cout << cur.F.F << " " << cur.F.S << " " << cur.S.F << " " << cur.S.S << endl

const int N = 21;

int n, m;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<char>> grid;
P target;
int vis[N][N][N][N];
vector<queue<node>> q;

bool inGrid(int nx, int ny)
{
  return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}

int bfs(pair<P, P> src)
{
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < m ; j++)
      for(int k = 0 ; k < n ; k++)
        for(int l = 0 ; l < m ; l++)
          vis[i][j][k][l] = 0;
  get(vis, src) = 1;
  q.clear();
  q.push_back(queue<node>());
  q[0].push(src);
  for(int lev = 0 ; lev < sz(q) ; lev++){
    while(!q[lev].empty()){
      node cur = q[lev].front();
      q[lev].pop();
      if(cur.second == target)
        return lev;
      for(int k = 0 ; k < 4 ; k++){
        int nx = cur.first.first + dx[k];
        int ny = cur.first.second + dy[k];
        if(!inGrid(nx, ny)) continue;
        if(cur.second == mp(nx, ny)){
          int nxb = nx + dx[k];
          int nyb = ny + dy[k];
          if(inGrid(nxb, nyb) && grid[nxb][nyb] != '#'){
            node nxt = {{nx, ny}, {nxb, nyb}};
            if(!get(vis, nxt)){
              while(sz(q) <= lev + 1)
                q.push_back(queue<node>());
              q[lev + 1].push(nxt);
              get(vis, nxt) = 1;
            }
          }
        }else if(grid[nx][ny] != '#'){
          node nxt = {{nx, ny}, cur.second};
          if(!get(vis, nxt)){
            q[lev].push(nxt);
            get(vis, nxt) = 1;
          }
        }
      }
    }
  }
  return -1;
}

int solve()
{
  P source, box;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < m ; j++){
      if(grid[i][j] == 'S')
        source = {i, j};
      if(grid[i][j] == 'T')
        target = {i, j};
      if(grid[i][j] == 'B')
        box = {i, j};
    }
  return bfs({source, box});
}

class Solution {
public:
  int minPushBox(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    ::grid = grid;
    return solve();
  }
};

int main()
{
  vector<vector<char>> grid = {
    {'#','#','#','#','#','#'},
    {'#','T','#','#','#','#'},
    {'#','.','.','B','.','#'},
    {'#','.','#','#','.','#'},
    {'#','.','.','.','S','#'},
    {'#','#','#','#','#','#'}
  };
  Solution sol;
  cout << sol.minPushBox(grid) << endl;
  return 0;
}
