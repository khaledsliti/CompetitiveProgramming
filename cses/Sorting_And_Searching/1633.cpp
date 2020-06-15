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

const int Mod = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    dp[i] = 0;
    for(int j = i - 1; j >= max(0, i - 6); j--)
      dp[i] = (dp[i] + dp[j]) % Mod;
  }
  cout << dp[n] << endl;
  return 0;
}
