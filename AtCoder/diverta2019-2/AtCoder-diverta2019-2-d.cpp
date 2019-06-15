#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 25000000 + 5;

int n;
int ga, gb, sa, sb, ba, bb;
long long dp[N];

long long solve(long long rem)
{
  dp[0] = 0;
  for(int i = 1 ; i <= rem ; i++){
    dp[i] = i;
    for(auto cur : { mp(ga, gb), mp(sa, sb), mp(ba, bb) }){
      if(cur.first <= i){
        dp[i] = max(dp[i], cur.second + dp[i - cur.first]);
      }
    }
  }
  return dp[rem];
}

int main()
{
  cin >> n;
  cin >> ga >> sa >> ba;
  cin >> gb >> sb >> bb;
  long long soFar = n;
  for(int it = 0 ; it < 2 ; ++it){
    soFar = solve(soFar);
    swap(ga, gb);
    swap(sa, sb);
    swap(ba, bb);
  }
  cout << soFar << endl;
  return 0;
}
