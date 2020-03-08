// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
  int n, m;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  bool in(int nx, int ny) {
    return nx >= 0 && nx < n && ny >= 0 && ny < m;
  }
public:
  int minCost(vector<vector<int>>& grid) {
    n = (int)grid.size();
    m = (int)grid[0].size();
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    pq.push({0, {0, 0}});
    while(!pq.empty()) {
      int x = pq.top().second.first;
      int y = pq.top().second.second;
      int c = -pq.top().first;
      pq.pop();
      if(x == n - 1 && y == m - 1)
        return c;
      for(int k = 0 ; k < 4 ; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        int cost = grid[x][y] - 1 != k;
        if(in(nx, ny) && dist[nx][ny] > c + cost) {
          dist[nx][ny] = c + cost;
          pq.push({- (cost + c), {nx, ny}});
        }
      }
    }
    return -1;
  }
};

int main()
{
  
  return 0;
}
