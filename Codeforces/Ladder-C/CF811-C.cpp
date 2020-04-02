// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5003;

int n;
int arr[N];
int L[N], R[N];
int dp[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  for(int i = 0 ; i < n ; i++)
    R[arr[i]] = i, L[arr[n - 1 - i]] = n - 1 - i;
  for(int i = n - 1 ; i >= 0 ; i--) {
    dp[i] = dp[i + 1];
    int mx = -1;
    int sum = 0;
    for(int j = i ; j < n ; j++) {
      if(L[arr[j]] < i)
        break;
      if(L[arr[j]] == j) sum ^= arr[j];
      mx = max(mx, R[arr[j]]);
      if(mx <= j) {
        dp[i] = max(dp[i], sum + dp[j + 1]);
      }
    }
  }
  cout << dp[0] << endl;
  return 0;
}
