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

int n;
long long pref[N];
long long dp[N];
map<long long, long long> mem;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> pref[i];
    if(i > 0) {
      pref[i] += pref[i - 1];
    }
  }

  dp[1] = 1;
  for(int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] * 2 % Mod;
    dp[i] -= mem[pref[i - 1]];
    dp[i] %= Mod;
    mem[pref[i - 1]] = dp[i - 1];
  }

  cout << (dp[n] + Mod) % Mod << endl;

  return 0;
}
