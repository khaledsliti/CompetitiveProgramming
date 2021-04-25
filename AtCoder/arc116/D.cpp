// RedStone
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

const int N = 5007;
const int Mod = 998244353;

int n, m, l;
vector<int> power;
int dp1[N][N];
int dp2[15][N];

int calc(int i, int rem) {
  if(i == 0) return rem == 0;
  int& r = dp1[i][rem];
  if(r != -1) return r;
  r = calc(i - 1, rem);
  if(rem > 0)
    r = (r + calc(i - 1, rem - 1)) % Mod;
  return r;
}

int solve(int i, int rem) {
  if(i == l) return rem == 0;
  int& r = dp2[i][rem];
  if(r != -1) return r;
  r = 0;
  for(int cur = 0, fr = 0; cur <= rem; cur += power[i], fr++) {
    if(fr & 1) continue;
    r = (r + 1LL * calc(n, fr) * solve(i + 1, rem - cur)) % Mod;
  }
  return r;
}

int main()
{
  cin >> n >> m;
  for(int i = 1; i <= m; i <<= 1) {
    power.pb(i);
  }
  l = sz(power);
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);

  cout << solve(0, m) << endl;

  return 0;
}
