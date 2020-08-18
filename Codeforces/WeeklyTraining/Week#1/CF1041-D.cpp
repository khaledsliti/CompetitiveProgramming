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

const int N = 2e5 + 5;
const long long Inf = 1e16;

int n, h;
int a[N], b[N];
ll after[N], width[N];

int main()
{
  scanf("%d%d", &n, &h);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", a + i, b + i);
  }
  after[n - 1] = Inf;
  for(int i = n - 2; i >= 0; i--) {
    after[i] = a[i + 1] - b[i];
  }
  for(int i = 1; i < n; i++)
    after[i] += after[i - 1];
  for(int i = 0; i < n; i++) {
    width[i] = b[i] - a[i];
    if(i > 0) width[i] += width[i - 1];
  }
  ll ans = h;
  for(int i = 0; i < n; i++) {
    int l = i, r = n - 1, last = i;
    while(l <= r) {
      int mid = (l + r) / 2;
      ll sum = after[mid] - (i > 0 ? after[i - 1] : 0LL);
      if(sum >= h) {
        last = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    ans = max(ans, h + width[last] - (i > 0 ? width[i - 1] : 0LL));
  }
  cout << ans << endl;
  return 0;
}
