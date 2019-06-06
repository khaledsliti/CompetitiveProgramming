#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;
int a[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &n, &k);
    for(int i = 0 ; i < n ; i++){
      scanf("%d", a + i);
    }
    int best = 2e9, ans;
    for(int i = 0 ; i + k < n ; i++){
      int mid = (a[i + k] + a[i]) / 2;
      // cout << i << " " << mid << endl;
      int cur = max(a[i + k] - mid, mid - a[i]);
      if(cur < best){
        best = cur;
        ans = mid;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
