/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1073/problem/E

  Idea:
    

  Compexity:
    Time: O(10 * log10(N) * 2 ^ 10)
    Memory: O(10 * log10(N) * 2 ^ 10)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int k;
int lo[19], hi[19];
long long po[19];
int dp[19][1 << 10][2][2][2];
int memo[19][1 << 10][2][2][2];

int solve(int d, int mask, int ls, int gr, int fr)
{
  if(__builtin_popcount(mask) > k)
    return 0;
  if(d < 0)
    return 1;
  int& r = dp[d][mask][ls][gr][fr];
  if(r != -1)
    return r;
  int mx = ls ? 9 : hi[d];
  int mn = gr ? 0 : lo[d];
  r = 0;
  for(int nxt = mn ; nxt <= mx ; nxt++){
    int msk = mask;
    if(nxt || fr)
      msk |= (1 << nxt);
    r = (r + solve(d - 1, msk, ls || nxt < hi[d], gr || nxt > lo[d], fr || nxt > 0)) % mod;
  }
  return r;
}

int calc(int d, int mask, int ls, int gr, int fr)
{
  if(d < 0)
    return 0;
  int& r = memo[d][mask][ls][gr][fr];
  if(r != -1)
    return r;
  int mx = ls ? 9 : hi[d];
  int mn = gr ? 0 : lo[d];
  r = 0;
  for(int nxt = mn ; nxt <= mx ; nxt++){
    int cur = (1LL * nxt * po[d]) % mod;
    int msk = mask;
    if(nxt || fr)
      msk |= (1 << nxt);
    r = (r + 1LL * cur * solve(d - 1, msk, ls || nxt < hi[d], gr || nxt > lo[d], fr || nxt > 0)) % mod;
    r = (r + calc(d - 1, msk, ls || nxt < hi[d], gr || nxt > lo[d], fr || nxt > 0)) % mod;
  }
  return r;
}

int main()
{
  long long l, r;
  cin >> l >> r >> k;
  po[0] = 1;
  for(int i = 0 ; i < 19 ; i++){
    lo[i] = l % 10;
    hi[i] = r % 10;
    l /= 10; r /= 10;
    if(i) po[i] = 10 * po[i - 1];
  }
  memset(dp, -1, sizeof dp);
  memset(memo, -1, sizeof memo);
  cout << calc(18, 0, 0, 0, 0) << endl;
  return 0;
}