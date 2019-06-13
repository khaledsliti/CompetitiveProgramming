#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m;
int br[N];
int dp[N];

int main()
{
  cin >> n >> m;
  while(m--){
    int a;
    cin >> a;
    br[a] = 1;
  }
  dp[n] = 1;
  for(int i = n - 1 ; i >= 0 ; i--){
    if(br[i]){
      dp[i] = 0;
    }else{
      if(!br[i + 1])
        dp[i] = (dp[i + 1] + dp[i]) % mod;
      if(!br[i + 2])
        dp[i] = (dp[i] + dp[i + 2]) % mod;
    }
  }
  cout << dp[0] << endl;
  return 0;
}
