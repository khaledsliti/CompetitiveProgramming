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

const int N = 1007;

int x, y;
string s;
int dp[N][2][2], vis[N][2][2];

int solve(int i, int isC, int isJ) {
  if(i >= sz(s)) return 0;
  int& r = dp[i][isC][isJ];
  if(vis[i][isC][isJ]) return r;
  vis[i][isC][isJ] = 1;
  if(s[i] == 'C') {
    r = isJ * y + solve(i + 1, 1, 0);
  } else if(s[i] == 'J') {
    r = isC * x + solve(i + 1, 0, 1);
  } else {
    r = min(isJ * y + solve(i + 1, 1, 0), isC * x + solve(i + 1, 0, 1));
  }
  return r;
}

void solve(int& tc) {
  cout << "Case #" << tc++ << ": ";
  cin >> x >> y >> s;
  for(int i = 0; i < sz(s); i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        vis[i][j][k] = 0;
      }
    }
  }
  cout << solve(0, 0, 0) << endl;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--) {
    solve(tc);
  }
  return 0;
}
