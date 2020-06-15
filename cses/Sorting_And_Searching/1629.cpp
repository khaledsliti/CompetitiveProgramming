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

const int N = 2e5 + 5;

int n;
pair<int, int> arr[N];
int dp[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr[i] = {a, b};
  }
  sort(arr, arr + n);
  dp[n] = 0;
  for(int i = n - 1; i >= 0; i --) {
    dp[i] = dp[i + 1];
    int nxt = lower_bound(arr + i, arr + n, make_pair(arr[i].second, arr[i].second)) - arr;
    dp[i] = max(dp[i], 1 + dp[nxt]);
  }
  cout << dp[0] << endl;
  return 0;
}
