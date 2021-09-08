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

const int N = 104;

int n;
string s;
int dp[N][3];

int solve(int i, int last) {
  if(i >= n) return 0;
  int& r = dp[i][last];
  if(r != -1) return r;
  if(s[i] == 'R') {
    r = (last == 1) + solve(i + 1, 1);
  } else if(s[i] == 'B') {
    r = (last == 2) + solve(i + 1, 2);
  } else {
    r = min((last == 1) + solve(i + 1, 1), (last == 2) + solve(i + 1, 2));
  }
  return r;
}

void trace(int i, int last) {
  if(i >= n) return;
  if(s[i] == 'R' || s[i] == 'B') {
    cout << s[i];
    trace(i + 1, (s[i] == 'R') + 2 * (s[i] == 'B'));
  } else {
    if(solve(i, last) == (last == 1) + solve(i + 1, 1)) {
      cout << 'R';
      trace(i + 1, 1);
    } else {
      cout << 'B';
      trace(i + 1, 2);
    }
  }
}

void solve() {
  cin >> n >> s;
  memset(dp, -1, sizeof dp);
  trace(0, 0);
  cout << endl;
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
