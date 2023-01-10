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

const int N = 503;

int n, k, r, c;

void solve() {
  cin >> n >> k >> r >> c;
  --r, --c;
  vector<vector<char>> sol(n, vector<char>(n, '.'));
  while(r > 0) {
    r--, c--;
    if (c < 0) {
      c = n - 1;
    }
  }
  while(r < n) {
    for(int j = 0; j < n; j++) {
      if(abs(j - c) % k == 0) {
        sol[r][j] = 'X';
      }
    }
    r++;
    c = (c + 1) % n;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << sol[i][j];
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
