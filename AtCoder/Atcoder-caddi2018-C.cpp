/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://atcoder.jp/contests/caddi2018/tasks/caddi2018_c

  Idea:
    https://img.atcoder.jp/caddi2018/editorial.pdf

  Complexity:
    Time: O(N lg N)
    Memory: O(N lg N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int oo = 1e9;
const int N = 2e5 + 6;
const int LOG = 16;

int n;
int arr[N][2];
long long dp[2][N][LOG];

long long solve(int t, int i, int taken)
{
  if (i >= n)
    return 0;
  long long& r = dp[t][i][taken];
  if(r != -1)
    return r;
  int p = 0;
  long long tmp = arr[i][t];
  long long prv = arr[i - 1][t] * (1LL << (2 * taken));
  while(tmp * (1LL << (2 * p)) < prv)
    p++;
  int rem = max(0, p - 15);
  return r = rem * (n - i - 1) + p + solve(t, i + 1, p - rem);
}

long long solve(int t, int i)
{
  if(i >= n)
    return 0;
  return solve(t, i + 1, 0);
}

int main()
{
  while(~scanf("%d", &n) && n){
    for(int i = 0 ; i < n ; i++){
      int a;
      scanf("%d", &a);
      arr[i][0] = a;
      arr[n - 1 - i][1] = a;
    }
    memset(dp, -1, sizeof dp);
    long long ans = solve(0, 0) * 2;
    for(int i = 0 ; i < n ; i++){
      long long cur = (solve(0, i + 1) + solve(1, n - i - 1)) * 2 + i + 1;
      ans = min(ans, cur);
    }
    cout << ans << endl;
  }
  return 0;
}
