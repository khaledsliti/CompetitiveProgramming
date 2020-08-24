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


int main()
{
  double c; cin >> c;
  double lo = 1.0, hi = 1e5;
  for(int it = 0; it < 10000; it++) {
    double mid = (lo + hi) / 2.0;
    if(mid * mid + sqrt(mid) > c) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << fixed << setprecision(15) << lo << endl;
  return 0;
}
