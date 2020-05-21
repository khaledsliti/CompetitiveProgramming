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

long long sum(long long target) {
  if(target < 1) return 0;
  long long a = 1, b = 2, len = 1, t = 0;
  long long res = 0;
  while(target >= 1) {
    long long cnt = min(target, len);
    long long c = cnt % Mod;
    if(t == 0) res += c * (a + c - 1) % Mod, a = (a + 2 * c % Mod) % Mod;
    else res += c * (b + c - 1) % Mod, b = (b + 2 * c % Mod) % Mod;
    res %= Mod;
    t ^= 1;
    target -= cnt;
    len <<= 1;
  }
  return res;
}

int main()
{
  long long l, r;
  cin >> l >> r;
  // cout << sum(r) << endl;
  cout << (sum(r) - sum(l - 1) + Mod) % Mod;
  return 0;
}
