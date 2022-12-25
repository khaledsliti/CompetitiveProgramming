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

bool powerOf(ll v, ll k) {
  while(v % k == 0) {
    v /= k;
  }
  return v == 1;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> a;
  for(int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ll p = 1;
    while(x % k == 0) {
      x /= k;
      p *= k;
    }
    a.push_back({x, p});
  }
  vector<pair<ll, ll>> tmp;
  for(int i = 0; i < sz(a); i++) {
    if(tmp.empty() || tmp.back().first != a[i].first) {
      tmp.push_back(a[i]);
    } else {
      tmp.back().second += a[i].second;
    }
  }
  swap(a, tmp);
  int m;
  cin >> m;
  vector<ll> b(m);
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int j = 0;
  for(int i = 0; i < m; i++) {
    if(j >= sz(a)) {
      cout << "NO" << endl;
      return;
    }
    ll sum = 0;
    ll count = 0;
    while(j < sz(a) && sum < b[i]) {
      if (sum + a[j].first * a[j].second < b[i]) {
        cout << "NO" << endl;
        return;
      } else {
        ll need = b[i] - sum;
        if(need % a[j].first != 0) {
          cout << "NO" << endl;
          return;
        }
        ll q = need / a[j].first;
        a[j].second -= q;
        count += q;
        sum += q * a[j].first;
        if(a[j].second == 0) {
          j++;
        }
      }
    }
    if(sum != b[i] || !powerOf(count, k)) {
      cout << "NO" << endl;
      return;
    }
  }
  if (j >= sz(a)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
