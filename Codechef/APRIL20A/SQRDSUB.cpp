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

int n;
int arr[N], L[N], R[N];

void solve() {
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", arr + i);
  }
  for(int i = 0 ; i < n ; i++) {
    if(arr[i] & 1)
      L[i] = 1 + (i ? L[i - 1] : 0);
    else
      L[i] = 0;
  }
  for(int i = n - 1 ; i >= 0 ; i--) {
    if(arr[i] & 1)
      R[i] = 1 + (i + 1 < n ? R[i + 1] : 0);
    else
      R[i] = 0;
  }
  long long ans = 1LL * n * (n + 1) / 2;
  for(int i = 0 ; i < n ; i++) {
    if(arr[i] && (arr[i] & 3) == 2) {
      ans -= 1LL * (i > 0 ? L[i - 1] + 1 : 1) * (i + 1 < n ? R[i + 1] + 1 : 1);
    }
  }

  printf("%lld\n", ans);
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
