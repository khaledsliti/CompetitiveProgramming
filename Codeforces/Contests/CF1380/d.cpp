// We only fail when we stop trying
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

const int N = 2e5 + 5;

int n, m, x, k, y;
int a[N], b[N], p[N];

int main()
{
  scanf("%d%d%d%d%d", &n, &m, &x, &k, &y);
  for(int i = 0; i < n; i++)
    scanf("%d", a + i);
  for(int i = 0; i < m; i++)
    scanf("%d", b + i);
  int j = 0;
  for(int i = 0; i < n && j < m; i++) {
    if(a[i] == b[j]) {
      p[i] = 1;
      j++;
    }
  }
  if(j < m) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    if(!p[i]) {
      int bor = -1;
      if(i > 0)
        bor = max(bor, a[i - 1]);
      int j = i + 1;
      int mx = a[i];
      while(j < n && !p[j]) {
        mx = max(mx, a[j]);
        j++;
      }
      if(j < n) bor = max(bor, a[j]);
      ll len = j - i;
      ll best = 1e18;
      if(bor > mx) {
        best = min(best, len * y);
      }
      if(len >= k) {
        best = min(best, len / k * x + (len % k) * 1LL * y);
        best = min(best, x + (len - k) * y);
      }
      if(best >= 1e18) {
        cout << -1 << endl;
        return 0;
      }
      ans += best;
      i = j;
    }
  }
  cout << ans << endl;
  return 0;
}
