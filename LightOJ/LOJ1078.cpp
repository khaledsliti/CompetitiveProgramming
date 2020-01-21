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
    int n, d;
    scanf("%d%d", &n, &d);
    int cur = d % n;
    for(int len = 1 ; ; len++){
      if(cur == 0){
        printf("Case %d: %d\n", tc++, len);
        break;
      }
      cur = (cur * 10 + d) % n;
    }
  }
  return 0;
}
