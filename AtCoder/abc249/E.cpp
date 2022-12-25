// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) #x << " = " << (x) << " "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 3007;

int n, mod;
int dp[N][N];
int pref[N][N];

int getLen(int x) {
  return sz(to_string(x));
}

int get(int new_len, int i, int j) {
  cerr << D(new_len) << D(i) << D(j) << endl;
  int ans = pref[new_len][j];
  if(i > 0) {
    ans = ans - pref[new_len][i - 1];
  }
  ans %= mod;
}

int main()
{
  cin >> n >> mod;
  for(int i = 0; i < N; i++) {
    dp[i][0] = 1;
  }
  for(int j = 0; j < N; j++) {
    pref[0][j] = 1;
  }
  for(int new_len = 1; new_len < n; new_len++) {
    for(int it = 1; it <= n; it++) {
      dp[new_len][it] = 0;
      for(int st = 1, seg_len = 1; st <= it; st *= 10, seg_len++) {
        int en = min(it, st * 10 - 1);
        cout << D(st) << D(en) << endl;
        // sum dp[new_len - seg_len - 1][it - k]
        // dp[new_len - seg_len - 1][it - st] + ... + dp[new_len - seg_len - 1][it - en]
        int fact = new_len == n - 1 ? 26 : 25;
        if (new_len - seg_len - 1 >= 0) {
          dp[new_len][it] += 1LL * fact * get(new_len - seg_len - 1, it - en, it - st) % mod;
          dp[new_len][it] %= mod;
          cout << D(get(new_len - seg_len - 1, it - en, it - st)) << endl;
        }
      }
    }
    for(int j = 0; j <= n; j++) {
      pref[new_len][j] = dp[new_len][j];
      if(j > 0) {
        pref[new_len][j] = (pref[new_len][j] + pref[new_len][j - 1]) % mod;
      }
    }
  }
  cout << (dp[n - 1][n] + mod) % mod << endl;
  return 0;
}
