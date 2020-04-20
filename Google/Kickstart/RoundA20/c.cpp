// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100001;

int n, k;
int a[N];

bool check(int len) {
  int cnt = 0;
  for(int i = 1 ; i < n ; i++)
    cnt += (a[i] - a[i - 1] - 1) / len;
  return cnt <= k;
}

void solve() {
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", a + i);
  int l = 1, r = 1e9, ans = 1e9;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(check(mid))
      ans = mid, r = mid - 1;
    else 
      l = mid + 1;
  }
  printf("%d\n", ans);
}

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--) {
    printf("Case #%d: ", tc++);
    solve();
  }
  return 0;
}
