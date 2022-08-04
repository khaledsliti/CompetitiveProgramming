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

int solve(int n) {
  int ans[6] = {0, 2, 1, 1, 2, 2};
  return n / 6 * 2 + ans[n % 6];
}

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 2 << endl;
  } else if (n % 6 == 1) {
    cout << solve(n - 7) + 3 << endl;
  } else {
    cout << solve(n) << endl;
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
