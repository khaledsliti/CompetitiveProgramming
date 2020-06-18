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

const int N = 1001;
const int Mod = 1e9 + 7;

int n;
string s[N];
int dp[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(s[i][j] == '*') {
        dp[j] = 0;
      } else {
        if(i == 0 && j == 0) dp[j] = 1;
        else if(j > 0) dp[j] = (dp[j] + dp[j - 1]) % Mod;
      }
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}
