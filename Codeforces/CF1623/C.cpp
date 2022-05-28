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
int arr[N];
long long cur[N], tmp[N];

bool check(long long mn) {
  for(int i = 0; i < n; i++) {
    cur[i] = arr[i];
    tmp[i] = 0;
  }
  for(int i = n - 1; i > 1; i--) {
    long long d = max(0LL, (tmp[i] + cur[i] - mn)) / 3;
    d = min(d, cur[i] / 3);
    cur[i] -= 3 * d;
    tmp[i - 1] += d;
    tmp[i - 2] += 2 * d;
  }
  for(int i = 0; i < n; i++) {
    cur[i] += tmp[i];
    if(cur[i] < mn)
      return false;
  }
  return true;
}

void solve() {
  cin >> n;
  long long s = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    s += arr[i];
  }
  long long low = 0, high = s, ans = 0;
  while(low <= high) {
    long long mid = (low + high) >> 1;
    if(check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
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
