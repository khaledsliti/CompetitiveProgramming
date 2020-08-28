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

const int N = 51;

int n, m;
string s[N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int vis[N][N];

bool good(int nx, int ny) {
  return nx >= 0 && nx < n && ny >= 0 && ny < m;
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'B') {
        for(int d = 0; d < 4; d++) {
          int ni = i + dx[d];
          int nj = j + dy[d];
          if(good(ni, nj) && s[ni][nj] == '.') {
            s[ni][nj] = '#';
          }
        }
      }
    }
  }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      vis[i][j] = 0;
  if(s[n - 1][m - 1] != '#') {
    queue<pair<int, int>> q;
    q.push({n - 1, m - 1});
    vis[n - 1][m - 1] = 1;
    while(!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(good(nx, ny) && !vis[nx][ny] && s[nx][ny] != '#') {
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
    }
  }
  bool good = true;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(s[i][j] == 'G' && !vis[i][j]) good = false;
      else if(s[i][j] == 'B' && vis[i][j]) good = false;
  cout << (good ? "Yes" : "No") << endl;
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
