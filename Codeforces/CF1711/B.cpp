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

int n, m;
int a[N];
int x[N], y[N];

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> d(n, 0);
  for(int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
    d[x[i]]++;
    d[y[i]]++;
  }
  if(m & 1) {
    int ans = 1e9;
    for(int i = 0; i < m; i++) {
      int ok_x = d[x[i]] & 1;
      int ok_y = d[y[i]] & 1;
      if(ok_x) {
        ans = min(ans, a[x[i]]);
      }
      if(ok_y) {
        ans = min(ans, a[y[i]]);
      }
      if(!ok_x && !ok_y) {
        ans = min(ans, a[x[i]] + a[y[i]]);
      }
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
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
