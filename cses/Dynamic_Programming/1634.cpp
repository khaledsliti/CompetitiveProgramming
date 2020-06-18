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

const int N = 1000005, V = 105;

int n, x;
int dp[N];

int main()
{
  cin >> n >> x;
  for(int i = 1; i <= x; i++)
    dp[i] = 1e9;
  dp[0] = 0;
  for(int i = 0; i < n; i++) {
    int c;
    cin >> c;
    for(int j = 1; j <= x; j++) {
      if(j - c >= 0)
        dp[j] = min(dp[j], 1 + dp[j - c]);
    }
  }
  cout << (dp[x] >= 1e9 ? -1 : dp[x]) << endl;
  return 0;
}
