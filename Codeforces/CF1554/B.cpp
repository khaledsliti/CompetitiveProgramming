// Guess Who's Back
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

const int N = 1e5 + 5;

int n, k;
int arr[N];

long long calc(int idx) {
  long long ans = LLONG_MIN;
  for(int i = 1; i <= n; i++) {
    if(idx != i) {
      long long cur = 1LL * i * idx - 1LL * k * (arr[idx] | arr[i]);
      ans = max(ans, cur);
    }
  }
  return ans;
}

void solve() {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  long long ans = LLONG_MIN;
  for(int i = 1; i <= min(3 * k, n); i++) {
    ans = max(ans, calc(i));
    ans = max(ans, calc(n - i + 1));
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
