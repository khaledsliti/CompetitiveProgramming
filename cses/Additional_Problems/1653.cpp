#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 20;

int n, x;
int a[N];
pair<int, int> dp[1 << N];

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = {0, x + 1};
  for(int msk = 1; msk < (1 << n); msk++) {
    dp[msk] = {n + 1, x + 1};
    for(int i = 0; i < n; i++) {
      if(msk & (1 << i)) {
        int r = msk ^ (1 << i);
        if(dp[r].second + a[i] <= x) {
          dp[msk] = min(dp[msk], { dp[r].first, dp[r].second + a[i] });
        } else {
          dp[msk] = min(dp[msk], { dp[r].first + 1, a[i] });
        }
      }
    }
  }
  cout << dp[(1 << n) - 1].first << endl;
  return 0;
}
