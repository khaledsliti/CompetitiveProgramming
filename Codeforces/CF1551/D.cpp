// Guess Who's Back
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

const int N = 101;

int n, m, k;
vector<vector<char>> sol;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<char>> rotate(vector<vector<char>> sol) {
  vector<vector<char>> res(sol[0].size(), vector<char>(sol.size()));
  for(int i = 0; i < sol.size(); i++)
    for(int j = 0; j < sol[0].size(); j++)
      res[j][n - 1 - i] = sol[i][j];
  return res;
}

bool in(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void colorate(pair<int, int> a, pair<int, int> b) {
  k--;
  set<char> ex;
  for(auto p : {a, b}) {
    for(int k = 0; k < 4; k++) {
      int x = p.first + dx[k];
      int y = p.second + dy[k];
      if(in(x, y) && sol[x][y] != 0) {
        ex.insert(sol[x][y]);
      }
    }
  }
  char candidate;
  for(char c = 'a'; c <= 'z'; c++) {
    if(ex.count(c) == 0) {
      candidate = c;
      break;
    }
  }
  for(auto p: {a, b}) {
    sol[p.first][p.second] = candidate;
  }
}

void finish() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(sol[i][j] == 0) {
        colorate({i, j}, {i, j + 1});
      }
    }
  }
}

void solve() {
  cin >> n >> m >> k;
  swap(n, m);
  sol.clear();
  sol.resize(n, vector<char>(m, 0));
  if(m & 1) {
    if(n / 2 > k) {
      cout << "NO" << endl;
      return;
    }
    if((k - n / 2) & 1) {
      cout << "NO" << endl;
      return;
    }
    for(int i = 0; i < n; i += 2) {
      colorate({i, 0}, {i + 1, 0});
    }
    for(int i = 0; i < n && k > 0; i += 2) {
      for(int j = 1; j < m && k > 0; j++) {
        colorate({i, j}, {i + 1, j});
      }
    }
    finish();
  } else {
    int cap = n / 2 * m;
    if(cap < k) {
      cout << "NO" << endl;
      return;
    }
    if(k & 1) {
      cout << "NO" << endl;
      return;
    }
    for(int i = 0; i < n && k > 0; i += 2) {
      for(int j = 0; j < m && k > 0; j += 2) {
        colorate({i, j}, {i + 1, j});
        colorate({i, j + 1}, {i + 1, j + 1});
      }
    }
    finish();
  }
  sol = rotate(sol);
  cout << "YES" << endl;
  for(int i = 0; i < sol.size(); i++) {
    for(int j = 0; j < sol[i].size(); j++) {
      cout << sol[i][j];
    }
    cout << endl;
  }
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
