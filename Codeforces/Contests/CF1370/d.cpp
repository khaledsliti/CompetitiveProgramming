// We only fail when we stop trying
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

const int N = 2e5 + 5;

int n, k;
int arr[N];
int dp[N], dp1[N];

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  int l = 0, r = 1e9, ans = 0;
  while(l <= r) {
    int mid = (l + r) / 2;
    dp[n] = dp[n + 1] = 0;
    dp1[n] = dp1[n + 1] = dp1[n - 1] = 0;
    for(int i = n - 1; i >= 0; i--) {
      dp[i] = max(dp[i + 1], (arr[i] <= mid) + dp[i + 2]);
      if(i < n - 1)
        dp1[i] = max(dp1[i + 1], (arr[i] <= mid) + dp1[i + 2]);
    }
    bool good = false;
    if(k & 1) {
      for(int i = 0; i < n; i++)
        if(dp[i] >= (k + 1) / 2)
          good = true;
      for(int i = 1; i < n; i++)
        if(dp1[i] >= k / 2)
          good = true;
    } else {
      for(int i = 0; i < n; i++)
        if(dp1[i] >= k / 2)
          good = true;
      for(int i = 1; i < n; i++)
        if(dp[i] >= k / 2)
          good = true;
    }

    if(good) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
