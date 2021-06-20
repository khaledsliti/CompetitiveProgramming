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

void solve() {
  long long n, x, t;
  cin >> n >> x >> t;
  long long cnt = min(n - 1, t / x);
  long long rem = max(0LL, n - 1 - cnt);
  if(cnt < 0) cout << 0 << endl;
  else cout << cnt * (cnt + 1) / 2 + rem * cnt << endl;
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
