#include <bits/stdc++.h>
using namespace std;

int const maxN = 200010;

int n;
int arr[maxN];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &arr[i]);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      int j = i;
      int mx = arr[i];
      while(j < n && (arr[i] > 0) == (arr[j] > 0)) {
        mx = max(mx, arr[j]);
        j++;
      }
      ans += mx;
      i = j - 1;
    }
    cout << ans << endl;
  }
  return 0;
}
