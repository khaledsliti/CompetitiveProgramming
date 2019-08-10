#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T, tc(1);
  cin >> T;
  while(T--){
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
      int cur = 0;
      for(int j = 0 ; j < m ; j++){
        int a;
        scanf("%d", &a);
        cur += a;
      }
      sum ^= cur;
    }
    printf("Case %d: %s\n", tc++, sum ? "Alice" : "Bob");
  }
  return 0;
}
