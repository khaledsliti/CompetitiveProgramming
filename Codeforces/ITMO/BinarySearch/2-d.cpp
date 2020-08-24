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

const int N = 15007;

int b, n;
int t[N], y[N], z[N], sol[N];

int calc(int i, int tot) {
  int block = z[i] * t[i] + y[i];
  int rem = tot % block;
  return min(z[i], rem / t[i]) + tot / block * z[i];
}

bool check(int tot) {
  ll cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += calc(i, tot);
  }
  return cnt >= b;
}

int main()
{
  cin >> b >> n;
  for(int i = 0; i < n; i++) {
    cin >> t[i] >> z[i] >> y[i];
  }
  int lo = 0, hi = 1e9, ans = -1;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  assert(ans != -1);
  cout << ans << endl;
  for(int i = 0; i < n; i++) {
    int c = calc(i, ans);
    c = min(c, b);
    cout << c << " ";
    b -= c;
  }
  return 0;
}
