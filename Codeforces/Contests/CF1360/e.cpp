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

const int N = 50;

int n;
string s[N];
int dp[N][N];

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> s[i];
      for(int j = 0; j < n; j++)
        dp[i][j] = 0;
    }
    bool good = true;
    for(int i = n - 1; i >= 0; i--) {
      for(int j = n - 1; j >= 0; j--) {
        if(s[i][j] == '1') {
          if(i == n - 1) dp[i][j] = 1;
          else if(j == n - 1) dp[i][j] = 1;
          else if(dp[i + 1][j] || dp[i][j + 1]) dp[i][j] = 1;
          if(!dp[i][j])
            good = false;
        }
      }
    }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
