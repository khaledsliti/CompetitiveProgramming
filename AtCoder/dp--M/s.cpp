// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 10005, D = 100;
const int Mod = 1e9 + 7;

string s;
int d, n;
int dp[2][D][2];

int main()
{
  cin >> s >> d;
  n = sz(s);
  dp[0][0][0] = 1;
  int cur = 0;
  for(int i = 0; i < n; i++) {
    int nxt = cur ^ 1;
    int c = s[i] - '0';
    for(int r = 0; r < d; r++)
      dp[nxt][r][0] = dp[nxt][r][1] = 0;
    for(int r = 0; r < d; r++) {
      dp[nxt][r][0] = dp[cur][((r - c) % d + d) % d][0];
      dp[nxt][r][1] = 0;
      for(int di = 0; di < 10; di++) {
        int p = ((r - di) % d + d) % d;
        dp[nxt][r][1] = (dp[nxt][r][1] + dp[cur][p][1]) % Mod;
        if(c > di)
          dp[nxt][r][1] = (dp[nxt][r][1] + dp[cur][p][0]) % Mod;
      }
    }
    cur ^= 1, nxt ^= 1;
  }
  int ans = (dp[cur][0][0] + dp[cur][0][1] + Mod - 1) % Mod;
  cout << ans << endl;
  return 0;
}
