#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int getNext(int n, int k)
{
  int l = k, r = n, nxt = k + 1;
  int q = n / k;
  while(l <= r){
    int mid = (l + r) / 2;
    if(n / mid == q){
      nxt = mid + 1;
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  return nxt;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    vector<int> res;
    for(int k = 1 ; k <= n ; k = getNext(n, k))
      res.push_back(n / k);
    res.push_back(0);
    reverse(all(res));
    printf("%d\n", sz(res));
    for(int a : res)
      printf("%d ", a);
    printf("\n");
  }
  return 0;
}
