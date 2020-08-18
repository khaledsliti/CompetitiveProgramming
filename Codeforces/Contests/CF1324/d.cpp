// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int arr[N];

int main()
{
  int t;
  t = 1;
  while(t--) {
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
      scanf("%d", arr + i);
    }
    for(int i = 0 ; i < n ; i++) {
      int a; scanf("%d", &a);
      arr[i] -= a;
    }
    sort(arr, arr + n);
    long long ans = 0;
    for(int i = 0 ; i < n ; i++) {
      int idx = lower_bound(arr, arr + n, -arr[i] + 1) - arr;
      int cnt = n - idx;
      if(arr[i] > 0) --cnt;
      ans += cnt;
    }
    ans /= 2;
    cout << ans << endl;
  }
  return 0;
}
