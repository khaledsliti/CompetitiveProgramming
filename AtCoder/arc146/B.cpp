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

const int L = 32;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll n, k, m;
  cin >> n >> m >> k;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto get = [](ll x, int b) -> int {
    return (x >> b) & 1;
  };
  auto calc = [&](ll want, ll have) -> ll {
    for(int b = L - 1; b >= 0; b--) {
      if(get(want, b) == 1 && get(have, b) == 0) {
        return (want & ((1LL << (b + 1)) - 1)) - (have & ((1LL << (b + 1)) - 1));
      }
    }
    return 0;
  };
  ll so_far = 0;
  for(int b = L - 1; b >= 0; b--) {
    ll want = so_far | (1LL << b);
    vector<ll> need;
    for(ll x: a) {
      need.push_back(calc(want, x));
    }
    sort(all(need));
    ll rem = m;
    int i = 0;
    while(i < n && rem >= need[i]) {
      rem -= need[i];
      i++;
    }
    if(i >= k) {
      so_far = want;
    }
  }
  cout << so_far << endl;
  return 0;
}
