// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, m, q;
int a[N], b[N];

int main()
{
  cin >> n >> m >> q;
  int xx = 1e9, yy = 1e9;
  for(int i = 0 ; i < n ; i++){
    cin >> a[i];
    xx = min(xx, a[i]);
  }
  for(int i = 0 ; i < m ; i++) {
    cin >> b[i];
    yy = min(yy, b[i]);
  }
  int best = xx + yy;
  while(q--) {
    int x, y, c;
    cin >> x >> y >> c;
    --x, --y;
    best = min(best, a[x] + b[y] - c);
  }
  cout << best << endl;
  return 0;
}
