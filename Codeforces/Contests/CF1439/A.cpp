// RedStone
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

const int N = 105;

int n, m;
int a[N][N];
vector<array<int, 6>> sol;

void add(array<int, 6> pos) {
  sol.pb(pos);
  for(int i = 0; i < 6; i += 2) {
    int x = pos[i], y = pos[i + 1];
    a[x][y] ^= 1;
  }
}

void print() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    char c;
    for(int j = 0; j < m; j++) {
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  sol.clear();
  for(int i = n - 1; i >= 2; i--) {
    for(int j = 0; j < m; j++) {
      if(a[i][j]) {
        add({i, j, i - 1, j, i - 1, j > 0 ? j - 1 : j + 1});
      }
    }
  }

  for(int j = m - 1; j >= 2; j--) {
    if(a[0][j]) {
      add({0, j, 0, j - 1, 1, j - 1});
    }
    if(a[1][j]) {
      add({1, j, 0, j - 1, 1, j - 1});
    }
  }

  for(int it = 0; ; it++) {
    vector<array<int, 2>> one, zero;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        if(a[i][j]) one.push_back({i, j});
        else zero.pb({i, j});
      }
    }
    if(!sz(one)) {
      break;
    }
    if(one.size() == 4) {
      add({one[3][0], one[3][1], one[2][0], one[2][1], one[1][0], one[1][1]});
    } else if(one.size() == 3) {
      add({one[0][0], one[0][1], one[1][0], one[1][1], one[2][0], one[2][1]});
    } else {
      add({one[0][0], one[0][1], zero[0][0], zero[0][1], zero[1][0], zero[1][1]});
    }
  }
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    for(int j = 0; j < 6; j++) {
      cout << sol[i][j] + 1 << " ";
    }
    cout << endl;
  }
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
