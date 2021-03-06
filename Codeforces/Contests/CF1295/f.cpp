#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;
const int MOD = 998244353;

int n;
int L[N], R[N];
int dp[N][N];
int fact_inv[N];

long long qpow(long long a, long long b)
{
  long long r = 1;
  while(b){
    if(b & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return r;
}

void prep_inv()
{
  fact_inv[0] = 1;
  for(int i = 1 ; i < N ; i++)
    fact_inv[i] = 1LL * fact_inv[i - 1] * qpow(i, MOD - 2) % MOD;
}

int choose(int n, int k)
{
  int res = 1;
  for(int i = 0 ; i < k ; i++){
    res = 1LL * res * (n - i) % MOD;
  }
  return 1LL * res * fact_inv[k] % MOD;
}

int main()
{
  prep_inv();
  cin >> n;
  vector<int> pts;
  for(int i = 0 ; i < n ; i++){
    cin >> L[i] >> R[i];
    pts.emplace_back(L[i]);
    pts.emplace_back(R[i] + 1);
  }
  reverse(L, L + n);
  reverse(R, R + n);
  sort(all(pts));
  pts.erase(unique(begin(pts), end(pts)), end(pts));
  int segs = sz(pts) - 1;
  for(int j = 0 ; j <= segs ; j++)
    dp[0][j] = 1;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= segs ; j++){
      int ls = pts[j - 1], rs = pts[j] - 1;
      int len = rs - ls + 1;
      dp[i][j] = dp[i][j - 1];
      for(int k = i ; k > 0 ; k--){
        if(L[k - 1] > rs || R[k - 1] < ls)
          break;
        int cnt = i - k + 1;
        dp[i][j] = (dp[i][j] + (1LL * choose(len + cnt - 1, cnt) * dp[k - 1][j - 1] % MOD)) % MOD;
      }
    }
  }
  int ans = dp[n][segs];
  for(int i = 0 ; i < n ; i++){
    ans = (ans * qpow(R[i] - L[i] + 1, MOD - 2)) % MOD;
  }
  cout << ans << endl;
  return 0;
}
