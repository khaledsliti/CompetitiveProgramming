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

const int N = 107;

int n;
string s[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<int>> vis(n, vector<int>(n, 0));
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(vis[i][j]) continue;
      int x = i, y = j;
      // rot(x, y) = (y, n - 1 - x)
      int ones = 0;
      for(int it = 0; it < 4; it++) {
        vis[x][y] = 1;
        ones += s[x][y] == '1';
        tie(x, y) = mp(y, n - 1 - x);
      }
      ans += min(ones, 4 - ones);
    }
  }
  cout << ans << endl;
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
