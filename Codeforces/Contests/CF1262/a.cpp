#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    int a = 1e9, b = 1;
    for(int i = 0 ; i < n ; i++){
      int l, r;
      scanf("%d%d", &l, &r);
      a = min(a, r);
      b = max(b, l);
    }
    printf("%d\n", max(0, b - a));
  }
  return 0;
}
