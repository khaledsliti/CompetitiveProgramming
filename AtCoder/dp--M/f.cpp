// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3005;

string s, t;
int dp[N][N];

int main()
{
  cin >> s >> t;
  for(int i = 1 ; i <= sz(s) ; i++) {
    for(int j = 1 ; j <= sz(t); j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if(s[i - 1] == t[j - 1])
        dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
    }
  }
  int i = sz(s), j = sz(t);
  string r;
  while(i > 0 && j > 0) {
    if(s[i - 1] == t[j - 1]) {
      r += s[i - 1];
      i--, j--;
    } else if(dp[i][j] == dp[i - 1][j]) {
      i--;
    } else {
      j--;
    }
  }
  reverse(all(r));
  cout << r << endl;
  return 0;
}
