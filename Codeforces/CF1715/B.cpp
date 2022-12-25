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

ll n, k, b, s;

void solve() {
  cin >> n >> k >> b >> s;
  if(s < k * b || s > k * b + n * (k - 1)) {
    cout << -1 << endl;
    return;
  }
  ll s_r = s - k * b;
  vector<ll> r(n);
  for(int i = 0; i < n; i ++) {
    r[i] = min(k - 1, s_r);
    s_r -= r[i];
  }
  r[0] += b * k;
  ll v_s = 0, v_b = 0;
  for(int i = 0; i < n; i++) {
    cout << r[i] << " ";
    v_s += r[i];
    v_b += r[i] / k;
  }
  cout << endl;
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
