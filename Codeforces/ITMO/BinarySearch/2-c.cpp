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
  int n, x, y;
  cin >> n >> x >> y;
  if(x > y) swap(x, y);
  if(n == 1) {
    cout << x << endl;
    return 0;
  }
  n--;
  int l = x, r = n * x, ans = -1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int tot = mid / x + mid / y;
    if(tot >= n) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  assert(ans != -1);
  cout << ans + x << endl;
  return 0;
}
