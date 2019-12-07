#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int L = 18;
const int N = (1 << L) + 4;

int n, lg;
int a[N];
long long dp[N][L];
int mxSize[L];

inline bool canSkip(int idx, int taken)
{
  return n - idx <= mxSize[taken];
}

inline bool canTake(int taken)
{
  return taken + 1 <= lg;
}

long long solve(int idx, int taken)
{
  if(idx == 0)
    return taken == lg ? 0 : 1e18;
  long long& r = dp[idx][taken];
  if(r != -1)
    return r;
  r = 1e18;
  if(canTake(taken))
    r = a[idx] + solve(idx - 1, taken + 1);
  if(canSkip(idx, taken))
    r = min(r, solve(idx - 1, taken));
  return r;
}

int main()
{
  scanf("%d", &n);
  lg = log2(n);
  mxSize[0] = 0;
  int val = n / 2;
  for(int i = 1 ; i <= lg ; i++){
    mxSize[i] = mxSize[i - 1] + val;
    val /= 2;
  }
  for(int i = 0 ; i < n ; i++)
    scanf("%d", &a[i]);
  for(int i = 0 ; i < n ; i++)
    if(a[i] == -1){
      while(i >= 0) a[i--] = 0;
      break;
    }
  memset(dp, -1, sizeof dp);
  cout << solve(n - 1, 0) << endl;
  return 0;
}
