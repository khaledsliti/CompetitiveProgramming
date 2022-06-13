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

const int N = 2e5 + 5;

int n, q;
int p[N];

void solve() {
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
      cin >> p[i];
  }
  sort(p, p + n);
  vector<ll> sum(n);
  for(int i = 0; i < n; i++) {
    sum[i] = p[i];
    if(i > 0) {
      sum[i] += sum[i - 1];
    }
  }
  while(q--) {
    int x, y;
    cin >> x >> y;
    int l = n - x;
    int r = l + y - 1;
    ll ans = sum[r] - (l > 0 ? sum[l - 1] : 0);
    cout << ans << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--) {
    solve();
  }
  return 0;
}
