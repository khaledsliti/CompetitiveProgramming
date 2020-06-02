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

const int N = 2020;

int n;
string s, t;
int cnt[26][2][N];
int dp[N][N];

void solve() {
  cin >> n >> s >> t;
  string ta = s, tb = t;
  sort(all(ta));
  sort(all(tb));
  if(ta != tb)
    return void(cout << -1 << endl);
  for(int c = 0; c < 26; c++)
    for(int i = 0; i < 2; i++)
      cnt[c][i][n] = 0;
  for(int i = n - 1; i >= 0; i--) {
    for(int c = 0; c < 26; c++) {
      cnt[c][0][i] = cnt[c][0][i + 1];
      cnt[c][1][i] = cnt[c][1][i + 1];
    }
    cnt[s[i] - 'a'][0][i]++;
    cnt[t[i] - 'a'][1][i]++;
  }
  for(int i = 0; i <= n; i++)
    dp[0][i] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      int c1 = s[i - 1] - 'a';
      int c2 = t[j - 1] - 'a';
      dp[i][j] = 1 + dp[i - 1][j];
      if(c1 == c2) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      if(cnt[c2][0][i] > cnt[c2][1][j]) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
  }
  cout << dp[n][n] << endl;
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
