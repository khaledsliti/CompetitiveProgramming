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

int n, m;
int a[N], b[N], mx_a[N], mn_a[N];
int sol_a[N], sol_b[N];
int ord[N];

void solve() {
  cin >> n >> m;
  long long D = 0, minSum = 0, maxSum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    mx_a[i] = min(a[i], m);
    mn_a[i] = max(0, m - b[i]);
    D += a[i] - b[i];
    maxSum += mx_a[i];
    minSum += mn_a[i];
  }
  // for(int i = 0; i < n; i++) {
  //   cout << mn_a[i] << " " << mx_a[i] << endl;
  // }
  long long target = (D + 1LL * n * m) / 2;
  target = min(maxSum, max(minSum, target));
  D(target);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ord[i] = i;
  }
  sort(ord, ord + n, [&](int a, int b) {
    if(mx_a[a] != mx_a[b]) {
      return mx_a[a] < mx_a[b];
    }
    return mn_a[a] > mn_a[b];
  });
  for(int j = 0; j < n; j++) {
    int i = ord[j];
    int take_a = max(1LL * mn_a[i], min(1LL * mx_a[i], target));
    sol_a[i] = take_a, sol_b[i] = m - take_a;
    target -= take_a;
    ans += a[i] - sol_a[i] - b[i] + sol_b[i];
  }
  if(ans < 0) ans = -ans;
  cout << ans << endl;
  for(int i = 0; i < n; i++) {
    cout << sol_a[i] << " " << sol_b[i] << endl;
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
