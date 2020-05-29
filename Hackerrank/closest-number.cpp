// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int myPow(int a, int b) {
  if(!b) return 1;
  int r = myPow(a, b >> 1);
  r *= r;
  if(b & 1) r *= a;
  return r;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int a, b, x;
    cin >> a >> b >> x;
    if(a == 1) {
      cout << (x == 1) << endl;
    } else {
      if(b < 0) cout << 0 << endl;
      else if(b == 0) cout << (x == 1) << endl;
      else {
        int apb = myPow(a, b);
        int l = apb / x * x;
        int r = l + x;
        if(abs(l - apb) <= abs(r - apb)) cout << l << endl;
        else cout << r << endl;
      }
    }
  }
  return 0;
}
