#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int p[N];
int x, a;
int y, b;
long long k;
int occ[N];

int check(int m)
{
  int ac = 0, bc = 0, ab = 0;
  for(int i = 1 ; i <= m ; i++){
    if(i % a == 0 && i % b == 0)
      ab++;
    else if(i % a == 0)
      ac++;
    else if(i % b == 0)
      bc++;
  }
  long long sum = 0;
  int At = 0;
  while(ab--)
    sum += 1LL * p[At++] * (x + y);
  if(x > y){
    while(ac--)
      sum += 1LL * p[At++] * x;
    while(bc--)
      sum += 1LL * p[At++] * y;
  }else{
    while(bc--)
      sum += 1LL * p[At++] * y;
    while(ac--)
      sum += 1LL * p[At++] * x;
  }
  return sum >= k;
}

int main()
{
  int q;
  scanf("%d", &q);
  while(q--){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
      scanf("%d", p + i);
      p[i] /= 100;
    }
    scanf("%d%d", &x, &a);
    scanf("%d%d", &y, &b);
    scanf("%I64d", &k);
    
    
    sort(p, p + n);
    reverse(p, p + n);
    int l = 0, r = n, ans = -1;
    while(l <= r){
      int mid = (l + r) / 2;
      if(check(mid)){
        ans = mid;
        r = mid - 1;
      }else{
        l = mid + 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
