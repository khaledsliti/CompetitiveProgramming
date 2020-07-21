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

const int N = 1e5 + 5;

int n, x;
int arr[N];
int dp[N];

void solve() {
  scanf("%d%d", &n, &x);
  for(int i = 0; i <n ; i++) {
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  dp[n] = 0;
  for(int i = n - 1; i >= 0; i--) {
    dp[i] = dp[i + 1];
    int need = (x + arr[i] - 1) / arr[i];
    if(i + need <= n) dp[i] = max(dp[i], 1 + dp[i + need]);
  }
  cout << dp[0] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
