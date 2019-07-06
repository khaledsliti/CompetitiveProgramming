#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n, x;
  while(cin >> n >> x){
    int cur = 0;
    int ans = 1;
    for(int i = 0 ; i < n ; i++){
      int L;
      cin >> L;
      cur += L;
      ans += cur <= x;
    }
    cout << ans << endl;
  }
  return 0;
}
