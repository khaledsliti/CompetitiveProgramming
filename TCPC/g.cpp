#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

int main()
{
  int n;
  scanf("%d", &n);
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    int a;
    scanf("%d", &a);
    int s = 0;
    while(a){
      s += a % 10;
      a /= 10;
    }
    ans += s & 1;
  }
  cout << ans << endl;
  return 0;
}
