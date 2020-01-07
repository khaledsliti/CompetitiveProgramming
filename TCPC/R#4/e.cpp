#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    int u, k;
    scanf("%d%d", &u, &k);
    int l = 31 - __builtin_clz(++k);
    printf("%I64d\n", ((1LL * u) << l) + k - (1LL << l));
  }
  return 0;
}
