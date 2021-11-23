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

int n;
int a[N], b[N];

bool check(int len) {
  int aa = len - 1, bb = 0;
  for(int i = 0; i < n && len > 0; i++) {
    if(a[i] >= aa && b[i] >= bb) {
      len--;
      aa--, bb++;
    }
  }
  return len <= 0;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int low = 1, high = n, ans = 0;
  while(low <= high) {
    int mid = (low + high) / 2;
    // cout << mid << " " << check(mid) << endl;
    if(check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  // assert(ans > 0);
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
