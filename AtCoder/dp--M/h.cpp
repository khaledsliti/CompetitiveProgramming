// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1010;
const int Mod = 1e9 + 7;

int n, m;
string s[N];
int dp[N];

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    cin >> s[i];
  for(int i = 0 ; i < m && s[0][i] != '#' ; i++)
    dp[i] = 1;
  for(int i = 1 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(s[i][j] == '#') dp[j] = 0;
      else if(j > 0) dp[j] = (dp[j] + dp[j - 1]) % Mod;
    }
  }
  cout << dp[m - 1] << endl;
  return 0;
}
