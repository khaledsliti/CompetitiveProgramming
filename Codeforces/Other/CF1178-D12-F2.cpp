#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2 * 501;
const int mod = 998244353;

int n, m;
vector<int> arr;
int dp[N][N];
int s[N], e[N];
vector<int> pos[N];

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
  if(s[mn] < l || e[mn] > r)
    return res = 0;
  if(mn == mx)
    return res = 1;
  int left = 0;
  for(int i = l; i <= pos[mn].front(); i++){
    int cur = (1LL * solve(l, i - 1) * solve(i, pos[mn].front() - 1)) % mod;
    left = (left + cur) % mod;
  }
  int right = 0;
  for(int i = r; i >= pos[mn].back(); i--){
    int cur = (1LL * solve(pos[mn].back() + 1, i) * solve(i + 1, r)) % mod;
    right = (right + cur) % mod;
  }
  res = (1LL * left * right) % mod;
  for(int i = 0 ; i + 1 < sz(pos[mn]) ; i++)
    res = (1LL * res * solve(pos[mn][i] + 1, pos[mn][i + 1] - 1)) % mod;
  return res;
}

int main()
{
  scanf("%d%d", &n, &m);
  memset(s, -1, sizeof s);
  for(int i = 0 ; i < m ; i++){
    int a;
    scanf("%d", &a);
    if(!sz(arr) || arr.back() != a){
      if(s[a] == -1)
        s[a] = sz(arr);
      e[a] = sz(arr);
      pos[a].push_back(sz(arr));
      arr.push_back(a);
    }
  }
  if(sz(arr) > 2 * n)
    return cout << 0 << endl, 0;
  memset(dp, -1, sizeof dp);
  cout << solve(0, sz(arr) - 1) << endl;
  return 0;
}
