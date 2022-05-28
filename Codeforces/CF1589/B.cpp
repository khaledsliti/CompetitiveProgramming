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

const int N = 3e4 + 1;

long long solve(long long a, long long b) {
  long long ans = LLONG_MAX;
  for(long long i = 0; i <= a; i ++) {
    long long cur = i * ((b + 2) / 3);
    cur += b * ((a - i + 2) / 3);
    ans = min(ans, cur);
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  int ans = min(solve(n, m), solve(m, n));
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
