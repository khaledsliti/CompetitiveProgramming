// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 107;

int n, m;
int arr[N][N], vis[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c; cin >> c;
      arr[i][j] = c == '1';
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      vis[i][j] = 0;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!vis[i][j] && arr[i][j]) {
        int cnt = 0;
        int min_i = n, max_i = -1, min_j = m, max_j = -1;
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while(!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          cnt++;
          min_i = min(min_i, x);
          max_i = max(max_i, x);
          min_j = min(min_j, y);
          max_j = max(max_j, y);
          q.pop();
          for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] && !vis[nx][ny]) {
              q.push({nx, ny});
              vis[nx][ny] = 1;
            }
          }
        }
        int xx = max_i - min_i + 1;
        int yy = max_j - min_j + 1;
        if(cnt != xx * yy) {
          cout << "No" << endl;
          return;
        }
      }
    }
  }
  cout << "Yes" << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
