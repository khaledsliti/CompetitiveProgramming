// RedStone
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

int n, l, r;
int arr[N];

void solve() {
  scanf("%d%d%d", &n, &l, &r);
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    // l <= a[i] + a[j] <= r
    // a[j] >= l - a[i] && a[j] <= r - a[i]
    // 1 1 2 5 5
    int a = lower_bound(arr, arr + n, l - arr[i]) - arr;
    int b = lower_bound(arr, arr + n, r - arr[i] + 1) - arr;
    if(a <= i) a = i + 1;
    if(a < b) ans += b - a;
  }
  printf("%I64d\n", ans);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
