#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 20;
const int INF = 1e9;

int n;
int sum[N], mn[N];
map<int, int> pref[N];
int dp[1 << N];

int solve(int mask, int cur_sum) {
  int& r = dp[mask];
  if(r != -1) {
    return r;
  }
  r = 0;
  for(int i = 0; i < n; i++) {
    if(!(mask & (1 << i))) {
      int cur = pref[i][-cur_sum];
      if(cur_sum + mn[i] >= 0) {
        cur += solve(mask | (1 << i), cur_sum + sum[i]);
      }
      r = max(r, cur);
    }
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    mn[i] = INT_MAX;
    sum[i] = 0;
    for(int j = 0; j < sz(s); j++) {
      sum[i] += s[j] == '(' ? 1 : -1;
      mn[i] = min(sum[i], mn[i]);
      if(mn[i] == sum[i]) {
        pref[i][sum[i]]++;
      }
    }
  }

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0) << endl;

  return 0;
}
