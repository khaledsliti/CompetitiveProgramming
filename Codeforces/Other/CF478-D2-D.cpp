#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int nr, ng;
int dp[N];

int main()
{
  int n;
  cin >> n;
  while(cin >> nr >> ng){
    int h = 0;
    for(; h * (h + 1) / 2 <= (nr + ng) ; h++); --h;
    for(int r = 0 ; r <= nr ; r++)
      dp[r] = 1;
    int sum = 0;
    for(int lev = 1 ; lev <= h ; lev++){
      for(int r = nr ; r >= 0 ; r--){
        int ru = nr - r;
        int gu = sum - ru;
        int g = ng - gu;
        if(r >= lev) dp[r] = (dp[r] + dp[r - lev]) % MOD;
      }
      sum += lev;
      for(int r = 0 ; r <= nr ; r++)
        cout << dp[r] << ", ";
      cout << endl;
    }
    cout << dp[nr] << endl;
    return 0;
  }
  return 0;
}
