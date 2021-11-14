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
  int n, d;
  cin >> n >> d;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    ans += (d + a - 1) / a;
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef LOCAL
  freopen("frog.in", "r", stdin);
#endif

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}