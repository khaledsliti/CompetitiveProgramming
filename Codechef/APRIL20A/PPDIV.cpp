// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int Mod = 1e9 + 7;
long long inv[10];

long long get_sum(long long n) {
  return n * (n + 1) % Mod * (2 * n + 1) % Mod * inv[6] % Mod;
}

long long solve(long long n) {
  long long st = 2;
  long long res = 0;
  while(st * st <= n) {
    // D(st);
    long long k = n / (st * st);
    // D(k);
    long long en = sqrt(1.0 * n / k);
    res = (res + k * (get_sum(en) - get_sum(st - 1)) % Mod) % Mod;
    // D(en);
    st = en + 1;
  }
  return (res + Mod) % Mod;
}

int main()
{
  set<long long> nums;
  for(long long i = 2 ; i * i * i <= 1e18 ; i++) {
    long long a = i * i;
    while(true) {
      nums.insert(a);
      if(a > 1e18 / i) break;
      a *= i;
    }
  }
  vector<long long> vals;
  for(auto x : nums)
    vals.pb(x);

  inv[1] = 1;
  for(int i = 2 ; i < 10 ; i++)
    inv[i] = Mod - Mod / i * 1LL * inv[Mod % i] % Mod;
  
  int t = 100;
  scanf("%d", &t);
  for(int it = 0 ; it < t ; it++) {
    long long n = 1e18;
    scanf("%lld", &n);
    long long ans = n;
    for(int i = 0 ; i < sz(vals) && vals[i] <= n ; i++) {
      ans = (ans + n / vals[i] * vals[i]) % Mod;
    }
    // D(ans);
    ans = (ans + solve(n)) % Mod;
    cout << ans << endl;
  }
  
  return 0;
}
