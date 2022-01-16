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



void solve() {
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  --r, --c;
  vector<string> s(n);
  bool found = false;
  bool b = false;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'B') {
        b = true;
        if(i == r || j == c) {
          found = true;
        }
      }
    }
  }
  if (!b) cout << -1 << endl;
  else if(s[r][c] == 'B') {
    cout << 0 << endl;
  } else if(found) {
    cout << 1 << endl;
  } else {
    cout << 2 << endl;
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
