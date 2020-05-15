// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3007;

int n;
int arr[N];
long long dp[N][N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  for(int i = 0 ; i < n ; i++)
    dp[i][i] = arr[i];
  for(int len = 2; len <= n; len++) {
    for(int i = 0; i + len <= n; i++) {
      int j = i + len - 1;
      dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
    }
  }
  cout << dp[0][n - 1] << endl;
  return 0;
}
