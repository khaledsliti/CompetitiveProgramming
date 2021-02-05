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

int h, w, n;
string s[N];
string word;
int dp[N][N][N];

int dfs(int cur, int x, int y) {
  if(cur >= n) {
    return 0;
  }
  int& r = dp[cur][x][y];
  if(r != -1) {
    return r;
  }
  r = 0;
  for(int dx = -1; dx <= 1; dx++) {
    for(int dy = -1; dy <= 1; dy++) {
      if(dx == 0 && dy == 0) continue;
      int nx = dx + x;
      int ny = dy + y;
      if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
        r = max(r, (s[x][y] == word[cur]) + dfs(cur + 1, nx, ny));
      }
    }
  }
  return r;
}

void trace(int cur, int x, int y) {
  if(cur >= n) {
    return;
  }
  cout << x + 1 << " " << y + 1 << endl;
  for(int dx = -1; dx <= 1; dx++) {
    for(int dy = -1; dy <= 1; dy++) {
      if(dx == 0 && dy == 0) continue;
      int nx = dx + x;
      int ny = dy + y;
      if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
        if(dfs(cur, x, y) == (s[x][y] == word[cur]) + dfs(cur + 1, nx, ny)) {
          trace(cur + 1, nx, ny);
          return;
        }
      }
    }
  }
}

int main()
{
  freopen("kingwalk.in", "r", stdin);
  freopen("kingwalk.out", "w", stdout);

  cin >> h >> w;
  for(int i = 0; i < h; i++) {
    cin >> s[i];
  }
  cin >> n >> word;
  int x = 0, y = 0, mx = -1;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      memset(dp, -1, sizeof dp);
      int cur = dfs(0, i, j);
      if(mx < cur) {
        x = i, y = j;
        mx = cur;
      }
    }
  }
  cout << mx << endl;
  trace(0, x, y);

  return 0;
}
