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

const int N = 201;

int n, idx;
string s[N];
int arr[N][N];
int dx[] = {-1, 1, 0 ,0};
int dy[] = {0, 0, -1, 1};

bool in(int x, int y) {
  return min(x, y) >= 0 && max(x, y) < n;
}

void dfs(int x, int y) {
  arr[x][y] = idx;
  for(int k = 0; k < 4; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if(in(nx, ny) && arr[nx][ny] == 0 && s[x][y] == s[nx][ny]) {
      dfs(nx, ny);
    }
  }
}

bool ok(int x, int y) {
  return arr[x][y] == arr[0][1] || arr[x][y] == arr[1][0];
}

bool check() {
  for(int k = 0; k < 2; k++) {
    s[0][0] = s[n - 1][n - 1] = char('0' + k);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        arr[i][j] = 0;
      }
    }
    idx = 1;
    dfs(0, 0);
    if(arr[n - 1][n - 1] == arr[0][0]) {
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < n; j++) {
      arr[i][j] = 0;
    }
  }
  vector<pair<int, int>> pos = {
    {0, 1}, {0, 2},
    {1, 0}, {1, 1},
    {2, 0}
  };

  for(int msk = 0; msk < (1 << 5); msk++) {
    if(__builtin_popcount(msk) > 2) continue;
    for(int i = 0; i < 5; i++) {
      if(msk & (1 << i)) {
        int cur = s[pos[i].first][pos[i].second] - '0';
        cur ^= 1;
        s[pos[i].first][pos[i].second] = char('0' + cur);
      }
    }

    if(check()) {
      cout << __builtin_popcount(msk) << endl;
      for(int i = 0; i < 5; i++) {
        if(msk & (1 << i)) {
          cout << pos[i].first + 1 << " " << pos[i].second + 1 << endl;
        }
      }
      return;
    }
    for(int i = 0; i < 5; i++) {
      if(msk & (1 << i)) {
        int cur = s[pos[i].first][pos[i].second] - '0';
        cur ^= 1;
        s[pos[i].first][pos[i].second] = char('0' + cur);
      }
    }
  }

  cout << -1 << endl;
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

/*
S000
1000
1000
110F


*/