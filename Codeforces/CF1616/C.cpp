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

const int N = 73;
const double EPS = 1e-9;

int n;
int a[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if(n <= 2) {
    cout << 0 << endl;
    return;
  }
  int ans = n;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      double delta = (a[j] - a[i]) * 1.0 / (j - i);
      double cur = a[i] - i * delta;
      // cout << i << " " << j << " " << delta << " " << cur << endl;
      int cur_ans = 0;
      for(int k = 0; k < n; k++) {
        if(abs(a[k] - cur) > EPS) {
          cur_ans++;
        }
        cur += delta;
      }
      ans = min(ans, cur_ans);
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
