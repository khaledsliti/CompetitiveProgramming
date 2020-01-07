#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5;

int n;
int arr[N][3];
long long dp[N][4];

long long solve(int cur, int last)
{
  if(cur >= n)
    return 0;
  long long& r = dp[cur][last];
  if(r != -1)
    return r;
  r = 0;
  for(int j = 0 ; j < 3 ; j++){
    if(j != last)
      r = max(r, arr[cur][j] + solve(cur + 1, j));
  }
  return r;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < 3 ; j++)
      scanf("%d", &arr[i][j]);
  memset(dp, -1, sizeof dp);
  cout << solve(0, 3) << endl;
  return 0;
}
