// Guess Who's Back
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

const int N = 2e5 + 5;
const int Mod = 998244353;

int n, m;
int L[N], R[N];
int oL[N], oR[N];
int dp[N];
int pref[N];
int divi[N];

void calcPref(int m) {
  pref[0] = dp[0];
  for(int i = 1; i <= m; i++) {
    pref[i] = (dp[i] + pref[i - 1]) % Mod;
  }
}

int getSub(int l, int r) {
  if(l > r) return 0;
  int res = pref[r];
  if(l > 0) res = (res - pref[l - 1]) % Mod;
  if(res < 0) res += Mod;
  return res;
}

int calcDP(int m, int g) {
  for(int i = 0; i < n; i++) {
    L[i] = (oL[i] + g - 1) / g;
    R[i] = oR[i] / g;

    if(L[i] > R[i]) {
      return 0;
    }
  }

  for(int i = 0; i <= m; i++) {
    dp[i] = 1;
  }
  calcPref(m);

  for(int it = 0; it < n; it++) {
    for(int r = m; r >= 0; r--) {
      if(r - L[it] < 0) {
        dp[r] = 0;
      } else {
        int left = max(0, r - R[it]);
        int right = r - L[it];
        dp[r] = getSub(left, right);
      }
    }
    calcPref(m);
  }

  return dp[m];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> oL[i] >> oR[i];
  }

  for(int i = 1; i <= m; i++) {
    for(int j = i; j <= m; j += i) {
      divi[j] ^= 1;
    }
  }

  int ans = 0;

  for(int g = 1; g <= m; g++) {
    int cur = calcDP(m / g, g);
    if(divi[g]) {
      ans = (ans + cur) % Mod;
    } else {
      ans = (ans - cur) % Mod;
    }
  }

  if(ans < 0) ans += Mod;

  cout << ans << endl;

  return 0;
}
