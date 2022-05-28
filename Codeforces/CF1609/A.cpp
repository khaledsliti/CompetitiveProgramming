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

void solve() {
  int n; cin >> n;
  long long ans = 1;
  vector<long long> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    while(a[i] % 2 == 0) {
      ans *= 2;
      a[i] /= 2;
    }
  }
  sort(all(a));
  ans *= a.back();
  for(int i = 0; i < n - 1; i++) {
    ans += a[i];
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
