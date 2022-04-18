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
  int n, m;
  cin >> n >> m;
  int dx = 1, dy = 1;
  int x, y;
  cin >> x >> y;
  --x, --y;
  int a, b; cin >> a >> b; --a, --b;
  int aa = x <= a ? a - x : n - 1 - x + n - 1 - a;
  int bb = y <= b ? b - y : m - 1 - y + m - 1 - b;
  cout << min(aa, bb) << endl;
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
