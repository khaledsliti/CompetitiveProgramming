// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3005;
const int Mod = 998244353;

int n, s;
int arr[N];
int dp[N][N];

int solve(int i, int rem) {
  if(rem == 0) return n - i + 1;
  if(i >= n) return 0;
  int& r = dp[i][rem];
  if(r != -1) return r;
  r = solve(i + 1, rem);
  if(arr[i] <= rem)
    r = (r + solve(i + 1, rem - arr[i])) % Mod;
  return r;
}

int solve() {
  int ans = 0;
  memset(dp, -1, sizeof dp);
  for(int i = 0 ; i < n ; i++) {
    if(arr[i] <= s) {
      int cur = solve(i + 1, s - arr[i]);
      ans = (ans + 1LL * (i + 1) * cur % Mod) % Mod;
    }
  }
  return ans;
}

int main()
{
  cin >> n >> s;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  cout << solve() << endl;
  return 0;
}
