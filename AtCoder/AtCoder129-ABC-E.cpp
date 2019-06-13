#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

string s;
int dp[N][2];

int solve(int i, int lt)
{
  if(i >= sz(s))
    return 1;
  int& r = dp[i][lt];
  if(r != -1) return r;
  r = 0;
  if(s[i] == '1'){
    r = (r + 2LL * solve(i + 1, lt)) % mod;
    r = (r + solve(i + 1, 1)) % mod;
  }else{
    if(lt)
      r = (r + 2LL * solve(i + 1, lt)) % mod;
    r = (r + solve(i + 1, lt)) % mod;
  }
  return r;
}

int main()
{
  cin >> s;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
  return 0;
}
