// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 505;

int n;
int arr[N];
int good[N][N];
int dp[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  for(int i = 0 ; i < n ; i++)
    good[i][i] = arr[i];
  for(int i = n - 1 ; i >= 0 ; i--)
    for(int j = i + 1 ; j < n ; j++) {
      good[i][j] = 0;
      for(int k = i ; k < j ; k++)
        if(good[i][k] && good[i][k] == good[k + 1][j])
          good[i][j] = good[i][k] + 1;
    }
  dp[n] = 0;
  for(int i = n - 1 ; i >= 0 ; i--) {
    dp[i] = n;
    for(int j = i ; j < n ; j++) {
      if(good[i][j])
        dp[i] = min(dp[i], 1 + dp[j + 1]);
    }
  }
  cout << dp[0] << endl;
  return 0;
}
