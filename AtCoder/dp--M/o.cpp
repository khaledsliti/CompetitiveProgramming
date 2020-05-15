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

const int N = 21;
const int Mod = 1e9 + 7;

int n;
int a[N][N];
int dp[1 << N], lg[1 << N];
int main()
{
  cin >> n;
  lg[1] = 0;
  for(int i = 2 ; i < (1 << n) ; i++)
    lg[i] = 1 + lg[i >> 1];

  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++)
      cin >> a[i][j];

  dp[0] = 1;
  for(int i = 0; i < n; i++) {
    for(int msk = (1 << n) - 1; msk >= 0; msk--) {
      dp[msk] = 0;
      if(__builtin_popcount(msk) != i + 1) continue;
      for(int cur = msk; cur > 0; cur -= cur & -cur) {
        int j = lg[cur & -cur];
        if(a[i][j]) {
          dp[msk] += dp[msk ^ (1 << j)];
          if(dp[msk] > Mod) dp[msk] -= Mod;
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
  return 0;
}
