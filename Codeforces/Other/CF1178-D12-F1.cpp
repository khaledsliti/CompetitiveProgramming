#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
const int N = 505;
const int mod = 998244353;
 
int n, m;
int arr[N];
int dp[N][N];
 
int solve(int l, int r)
{
  if(l > r)
    return 1;
  int& res = dp[l][r];
  if(res != -1)
    return res;
  int mx = 0, mn = n + 1;
  for(int i = l ; i <= r ; i++){
    mx = max(mx, arr[i]);
    mn = min(mn, arr[i]);
  }
  if(mn == mx)
    return res = 1;
  vector<int> pos;
  for(int i = l ; i <= r ; i++)
    if(arr[i] == mn)
      pos.push_back(i);
  int left = 0;
  for(int i = l; i <= pos.front(); i++){
    int cur = (1LL * solve(l, i - 1) * solve(i, pos.front() - 1)) % mod;
    left = (left + cur) % mod;
  }
  // cout << left << endl;
  // exit(0);
  int right = 0;
  for(int i = r; i >= pos.back(); i--){
    int cur = (1LL * solve(pos.back() + 1, i) * solve(i + 1, r)) % mod;
    right = (right + cur) % mod;
  }
  res = (1LL * left * right) % mod;
  for(int i = 0 ; i + 1 < sz(pos) ; i++)
    if(pos[i] + 1 < pos[i])
      res = (1LL * res * solve(pos[i] + 1, pos[i + 1] - 1)) % mod;
  return res;
}
 
int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, n - 1) << endl;
  return 0;
}