#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T;
  cin >> T;
  while(T--){
    int a, b, k;
    cin >> a >> b >> k;
    if(a > b)
      swap(a, b);
    int g = __gcd(a, b);
    int len = b - g;
    int cnt = (len - 1) / a + 1;
    if(k > cnt)
      cout << "OBEY" << endl;
    else
      cout << "REBEL" << endl;
  }
  return 0;
}
