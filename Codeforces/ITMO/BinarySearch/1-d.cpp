// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(all(v));
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    int ans = lower_bound(all(v), r + 1) - lower_bound(all(v), l);
    cout << ans << " ";
  }
  return 0;
}
