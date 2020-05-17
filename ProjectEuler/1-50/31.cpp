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

int coins[] {1, 2, 5, 10, 20, 50, 100, 200};
int dp[201];

int main()
{
  dp[0] = 1;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j <= 200; j++) {
      if(j - coins[i] >= 0)
        dp[j] += dp[j - coins[i]];
    }
  }
  cout << dp[200] << endl;
  return 0;
}
