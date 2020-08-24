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

int n, k;
double a[10000];

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  double ans, l = 0, r = 1e7;
  for(int it = 0; it< 100; it++) {
    double mid = (l + r) / 2.0;
    ll cnt = 0;
    for(int i = 0; i < n; i++)
      cnt += (int) (a[i] / mid);
    if(cnt >= k) {
      ans = mid;
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
