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

const int N = 1000000;
map<ll, int> dp;

int main()
{
  dp[1] = 1;
  int best = 1, At = -1;
  for(ll i = 2; i <= N; i++) {
    if(!dp.count(i)) {
      vector<int> val;
      ll j = i;
      while(!dp.count(j)) {
        val.push_back(j);
        if(j & 1) j = 3 * j + 1;
        else j >>= 1;
      }
      int cur = dp[j] + 1;
      for(int k = sz(val) - 1; k >= 0; k--) {
        dp[val[k]] = cur++;
      }
    }
    if(best < dp[i]) {
      best = dp[i];
      At = i;
    }
  }
  cout << At << endl;
  return 0;
}
