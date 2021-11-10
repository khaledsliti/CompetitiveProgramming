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

int solve(int n, vector<int>& a) {
  int mn = 0, mx = 0;
  int cur = 0, st = 0;
  for(int i = 0; i < sz(a); i++) {
    cur += a[i];
    mn = min(mn, cur);
    mx = max(mx, cur);
    if(mx - mn + 1 <= n) {
      st = -mn;
    }
  }
  return st + 1;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a, b;
  string s; cin >> s;
  for(char c: s) {
    if(c == 'L') b.push_back(-1);
    else if(c == 'R') b.push_back(1);
    else if(c == 'U') a.push_back(-1);
    else a.push_back(1);
  }
  cout << solve(n, a) << " " << solve(m, b) << endl;
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