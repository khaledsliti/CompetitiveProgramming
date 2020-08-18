#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T;
  cin >> T;
  while(T--){
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    while(n > 0){
      if(n % k == 0){
        n /= k;
        ans++;
      }else{
        ans += n % k;
        n -= n % k;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
