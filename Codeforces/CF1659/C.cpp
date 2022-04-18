#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
typedef long long ll;

const int N = 2e5 + 5;

int n, a, b;
int x[N];
long long dp[N];

void solve() {
  cin >> n >> a >> b;
  n++;
  for(int i = 1; i < n; i++) {
    cin >> x[i];
  }
  long long cur = 0;
  for(int i = 1; i < n; i++) {
    int d = x[i] - x[i - 1];
    cur += 1LL * d * (a + b);
  }
  long long ans = cur;
  int cnt = 0;
  for(int i = n - 2; i >= 0; i--) {
    int d = x[i + 1] - x[i];
    cur -= 1LL * a * d;
    cur += 1LL * cnt * d * b;
    ans = min(ans, cur);
    cnt++;
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
