#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;
int a[N][22];
int sum[N];

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++){
    int x;
    scanf("%d", &x);
    int cnt = 0;
    while(x){
      a[x][cnt]++;
      sum[x]++;
      x >>= 1;
      cnt++;
    }
    a[x][cnt]++;
    sum[x]++;
  }
  int ans = 1e9;
  for(int i = 0 ; i < N ; i++){
    if(sum[i] >= k){
      int cur = 0;
      int added = k;
      for(int j = 0 ; j < 22 && added > 0 ; j++)
        while(a[i][j] > 0 && added > 0)
          cur += j, a[i][j]--, added--;
      ans = min(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}
