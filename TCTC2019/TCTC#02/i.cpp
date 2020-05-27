#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

int main()
{
  int q;
  scanf("%d", &q);
  while(q--){
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    int g = __gcd(a, b);
    if(b > a)
      swap(a, b);
    a /= g;
    printf("%d\n", n / a);
  }
  return 0;
}
