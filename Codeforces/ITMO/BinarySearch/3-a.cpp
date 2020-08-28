// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 5;

int n;
int x[N], v[N];

bool check(double ti) {
  double L = -1e18, R = 1e18;
  for(int i = 0; i < n; i++) {
    double l = x[i] - v[i] * ti;
    double r = x[i] + v[i] * ti;
    L = max(L, l);
    R = min(R, r);
  }
  return L <= R;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &v[i]);
  } 
  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }
  double lo = 0, hi = 2e9;
  for(int it = 0; it < 100; it++) {
    double mid = lo + (hi - lo) / 2.0;
    if(check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << fixed << setprecision(15) << lo << endl;
  return 0;
}
