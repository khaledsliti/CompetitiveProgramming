// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, k;
int arr[N];

int main()
{
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  vector<int> dp(n + 1);
  dp[0] = 0;
  for(int i = 1; i < n; i++) {
    dp[i] = 2e9;
    for(int j = i - 1; j >= max(0, i - k); j--)
      dp[i] = min(dp[i], abs(arr[i] - arr[j]) + dp[j]);
  }
  cout << dp[n - 1] << endl;
  return 0;
}
