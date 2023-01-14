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

struct Hash {
  const ll MOD1 = 1000000009;
  const ll MODINVERSE1 = 554687505;
  
  const ll MOD2 = 1190494759;
  const ll MODINVERSE2 = 976577732;

  const ll BASE = 128;

  vector<ll> h1, h2;
  vector<ll> bp1, bp2;
  
  Hash(const string& s) {
    bp1.resize(sz(s) + 1);
    bp2.resize(sz(s) + 1);
    for(int i = 0; i <= sz(s); i++) {
      bp1[i] = i == 0 ? 1LL : bp1[i - 1] * BASE % MOD1;
      bp2[i] = i == 0 ? 1LL : bp2[i - 1] * BASE % MOD2;
    }

    h1.resize(sz(s));
    h2.resize(sz(s));

    ll so_far1 = 0, so_far2 = 0;
    for(int i = 0; i < sz(s); i++) {
      so_far1 = (so_far1 * BASE % MOD1 + s[i]) % MOD1;
      h1[i] = so_far1;
      so_far2 = (so_far2 * BASE % MOD2 + s[i]) % MOD2;
      h2[i] = so_far2;
    }
  }

  pair<ll, ll> get(int l, int r) {
    if (l > r) {
      return {0LL, 0LL};
    }
    ll r1 = h1[r];
    ll r2 = h2[r];
    if(l > 0) {
      r1 -= h1[l - 1] * bp1[r - l + 1] % MOD1;
      r1 = (r1 % MOD1 + MOD1) % MOD1;

      r2 -= h2[l - 1] * bp2[r - l + 1] % MOD2;
      r2 = (r2 % MOD2 + MOD2) % MOD2;
    }
    return {r1, r2};
  }

  pair<ll, ll> combine(pair<ll, ll> left, pair<ll, ll> right, int width) {
    return {
      (right.first + left.first * bp1[width] % MOD1) % MOD1,
      (right.second + left.second * bp2[width] % MOD2) % MOD2
    };
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  string t, r;
  cin >> t;
  r = t;
  reverse(all(r));

  Hash ht(t);
  auto get_hs = [&](int i) -> pair<ll, ll> {
    pair<ll, ll> f = ht.get(0, i - 1);
    pair<ll, ll> s = ht.get(i + n, 2 * n - 1);
    return ht.combine(f, s, n - i);
  };

  Hash hr(r);
  auto get_rhs = [&](int i) -> pair<ll, ll> {
    int idx = i + n - 1;
    idx = 2 * n - idx - 1;
    return hr.get(idx, idx + n - 1);
  };

  for(int i = 0; i <= n; i++) {
    if (get_hs(i) == get_rhs(i)) {
      string ans = t.substr(i, n);
      reverse(all(ans));
      cout << ans << endl;
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
