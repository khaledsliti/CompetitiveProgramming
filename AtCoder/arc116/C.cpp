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

const int N = 200010;
const int Mod = 998244353;

int n, m;
int smf[N];
int dp[N][100];

void init() {
  for(int i = 0; i <= m; i++)
    smf[i] = i;
  for(int i = 2; i * i <= m; i++) {
    if(smf[i] == i) {
      for(int j = 2 * i; j <= m; j += i) {
        smf[j] = min(smf[j], i);
      }
    }
  }
}

int calc(int it, int rem) {
  if(it == 0) return rem == 0;
  int& r = dp[it][rem];
  if(r != -1) return r;
  r = calc(it - 1, rem);
  if(rem > 0)
    r = (r + calc(it, rem - 1)) % Mod;
  return r;
}

int solve(int m) {
  int ans = 1;
  while(m > 1) {
    int f = smf[m];
    int fr = 0;
    while(m % f == 0) {
      fr++;
      m /= f;
    }
    ans = (ans * 1LL * calc(n, fr)) % Mod;
  }
  return ans;
}

int main()
{
  memset(dp, -1, sizeof dp);
  
  cin >> n >> m;
  init();

  int ans = 1;
  for(int i = 2; i <= m; i++) {
    ans = (ans + solve(i)) % Mod;
  }
  cout << ans << endl;
  return 0;
}
