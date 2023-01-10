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

const int N = 2e5 + 3;


void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll ans = 0;
  for (int it = 0; it < 2; it++) {
    ll s = 0;
    for (int i = 0; i < n; i++) {
      s += arr[i];
      ans = max(ans, s);
      if (s < 0) {
        s = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      arr[i] = -arr[i];
    }
  }
  cout << ans << endl;
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
