#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--){
    long long w;
    scanf("%lld", &w);
    printf("Case %d: ", tc++);
    if(w & 1) printf("Impossible\n");
    else{
      long long n = w, m = 1;
      while(!(n & 1)){
        n >>= 1;
        m <<= 1;
      }
      printf("%lld %lld\n", n, m);
    }
  }
  return 0;
}
