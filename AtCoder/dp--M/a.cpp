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

int n;
int arr[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  vector<int> dp(n + 1);
  dp[0] = 0;
  for(int i = 1; i < n; i++) {
    dp[i] = abs(arr[i] - arr[i - 1]) + dp[i - 1];
    if(i > 1) dp[i] = min(dp[i], abs(arr[i] - arr[i - 2]) + dp[i - 2]);
  }
  cout << dp[n - 1] << endl;
  return 0;
}
