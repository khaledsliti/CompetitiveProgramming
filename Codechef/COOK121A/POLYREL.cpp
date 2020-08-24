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
  int n;
  scanf("%d", &n);
  int x, y;
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
  }
  int ans = 0;
  while(n > 2) {
    ans += n;
    n >>= 1;
  }
  cout << ans << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
