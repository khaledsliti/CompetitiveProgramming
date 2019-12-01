#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n, m, k;
int arr[N];
long long dp[N][11];

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", arr + i);
  }
  long long ans = 0LL;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      dp[i][j] = max(0LL, arr[i] + (j == 0 ? -k : 0) + (i > 0 ? dp[i - 1][(j + 1) % m] : 0LL));
    }
    ans = max(ans, dp[i][0]);
  }
  cout << ans << endl;
  return 0;
}
