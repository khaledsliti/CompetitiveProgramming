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

const int N = 121;

void solve() {
  int n;
  cin >> n;
  vector<int> line(n);
  for(int i = 0; i < n; i++) {
    cin >> line[i];
  }
  int xs, ys, xd, yd;
  cin >> xs >> ys >> xd >> yd;
  xs--, xd--;
  int vis[n][85];
  memset(vis, -1, sizeof vis);
  queue<pair<int, int>> q;
  q.push({xs, ys});
  vis[xs][ys] = 0;
  while(q.empty() == false) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    { // Left
      if(y > 0 && vis[x][y - 1] == -1) {
        vis[x][y - 1] = 1 + vis[x][y];
        q.push({x, y - 1});
      } else if(x > 0 && y == 0 && vis[x - 1][line[x - 1]] == -1) {
        vis[x - 1][line[x - 1]] = 1 + vis[x][y];
        q.push({x - 1, line[x - 1]});
      }
    }
    { // Right
      if(y < line[x] && vis[x][y + 1] == -1) {
        vis[x][y + 1] = 1 + vis[x][y];
        q.push({x, y + 1});
      } else if(x + 1 < n && y == line[x] && vis[x + 1][0] == -1) {
        vis[x + 1][0] = 1 + vis[x][y];
        q.push({x + 1, 0});
      }
    }
    if(x > 0) { // Up
      int ny = min(line[x - 1], y);
      if(vis[x - 1][ny] == -1) {
        vis[x - 1][ny] = 1 + vis[x][y];
        q.push({x - 1, ny});
      }
    }
    if(x + 1 < n) { // Down
      int ny = min(y, line[x + 1]);
      if(vis[x + 1][ny] == -1) {
        vis[x + 1][ny] = 1 + vis[x][y];
        q.push({x + 1, ny});
      }
    }
  }
  
  cout << vis[xd][yd] << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
