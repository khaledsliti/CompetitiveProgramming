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
int arr[N][N];

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n ;i++) {
    for(int j = 0; j < m; j++) {
      char c; cin >> c;
      arr[i][j] = c == '1';
    }
  }
  if(arr[0][0] == 1) {
    cout << -1 << endl;
    return;
  }
  vector<array<int, 4>> sol;
  for(int i = n - 1; i > 0; i--) {
    for(int j = 0; j < m; j++) {
      if(arr[i][j]) {
        sol.push_back({i - 1, j, i, j});
      }
    }
  }
  for(int j = m - 1; j > 0; j--) {
    if(arr[0][j]) {
      sol.push_back({0, j - 1, 0, j});
    }
  }
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    for(int x: sol[i]) cout << x + 1 << " ";
    cout << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T; cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
/*
0 0 1 0 0
1 1 0 1 1
0 0 1 0 0
0 0 0 0 1


*/