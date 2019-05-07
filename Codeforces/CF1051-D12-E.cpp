/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1051/problem/E

  Idea:
    Let dp[i] be the solution for suffix starting from index i.
    dp[i] is the sum dp[k] such that number a[i, k - 1] >= l and <= r.
    If L = k - i < len(r) and > len(l) then k is valid because a number with fewer number of digits is always smaller.
    We will take k for L = len(l) if number a[i, k - 1] >= l (same for L = len(r))
    To check if a[i, k - 1] is less than or equal to l we can use Z-algorithm to get the longuest commun prefix
    and then compare with the next digit.

  Compexity:
    Time: O(N)
    Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 998244353;
const int N = 2e6 + 5;

string a, l, r;
int larr[N], rarr[N];
int Z[N];
int dp[N], suff[N];

void build(string pat, int* arr, int fr)
{
  int L = 0, R = 0;
  for(int i = 1 ; i < sz(pat) ; i++){
    if(i > R){
      L = R = i;
      while(R < sz(pat) && pat[R] == pat[R - L]) R++;
      Z[i] = R - L;
      --R;
    }else{
      int k = i - L;
      if(Z[k] < R - i + 1) Z[i] = Z[k];
      else{
        L = i;
        while(R < sz(pat) && pat[R] == pat[R - L]) R++;
        Z[i] = R - L;
        --R;
      }
    }
    if(i >= fr)
      arr[i - fr] = Z[i];
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> a >> l >> r;
  build(l + "#" + a, larr, sz(l) + 1);
  build(r + "#" + a, rarr, sz(r) + 1);
  for(int i = 0 ; i <= sz(a) - sz(l) ; i++)
    larr[i] = (larr[i] >= sz(l) || a[i + larr[i]] > l[larr[i]]);
  for(int i = 0 ; i <= sz(a) - sz(r) ; i++)
    rarr[i] = (rarr[i] >= sz(r) || a[i + rarr[i]] < r[rarr[i]]);
  for(int i = sz(a) - sz(l) + 1 ; i < sz(a) ; i++)
    larr[i] = 0;
  for(int i = sz(a) - sz(r) + 1 ; i < sz(a) ; i++)
    rarr[i] = 1;
  dp[sz(a)] = suff[sz(a)] = 1;
  for(int i = sz(a) - 1 ; i >= 0 ; i--){
    if(a[i] == '0'){
      dp[i] = l == "0" ? dp[i + 1] : 0;
    }else{
      int mn = i + sz(l) + 1 - larr[i];
      int mx = min(i + sz(r) - 1 + rarr[i], sz(a));
      if(mn <= mx)
        dp[i] = ((suff[mn] - suff[mx + 1]) % mod + mod) % mod;
    }
    suff[i] = (dp[i] + suff[i + 1]) % mod;
  }
  cout << dp[0] << endl;
  return 0;
}
