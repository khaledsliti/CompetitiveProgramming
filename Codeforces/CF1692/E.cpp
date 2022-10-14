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

int n, x;
int arr[N];

void solve() {
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    if(i > 0) {
      arr[i] += arr[i - 1];
    }
  }
  int ans = 1e9;
  for(int i = 0; i < n; i++) {
    int need = x + (i > 0 ? arr[i - 1] : 0);
    int idx = lower_bound(arr, arr + n, need + 1) - arr - 1;
    if (idx >= i && arr[idx] == need) {
    // cout << need << " " << idx << endl;
      ans = min(ans, i + n - idx - 1);
    }
  }
  if(ans >= 1e9) ans = -1;
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
