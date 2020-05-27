#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 101;

int n;
string s;
int dp[N][N];
int mem[N];

int isPalin(int i, int j)
{
  if(i >= j)
    return 1;
  int& r = dp[i][j];
  if(r != -1)
    return r;
  r = 0;
  if(s[i] == s[j])
    r |= isPalin(i + 1, j - 1);
  return r;
}

int solve(int i)
{
  if(i >= n)
    return 0;
  int& r = mem[i];
  if(r != -1)
    return r;
  r = 1e9;
  for(int j = i ; j < n ; j++)
    if(isPalin(i, j))
      r = min(r, 1 + solve(j + 1));
  return r;
}

int main()
{
  cin >> n >> s;
  memset(dp, -1, sizeof dp);
  memset(mem, -1, sizeof mem);
  cout << solve(0) << endl;
  return 0;
}
