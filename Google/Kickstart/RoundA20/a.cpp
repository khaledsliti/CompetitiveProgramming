// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for(int i = 0; i < n && k >= v[i]; i++) {
    ans++;
    k -= v[i];
  }
  cout << ans << endl;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--) {
    cout << "Case #" << tc++ << ": ";
    solve();
  }
  return 0;
}
