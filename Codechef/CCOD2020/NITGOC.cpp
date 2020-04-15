// We only fail when we stop trying
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
  int t;
  cin >> t;
  while(t--) {
    long long a, b;
    cin >> a >> b;
    while(a > 1 && b > 1) {
      if(a > b) {
        a -= (a - 1) / b * b;
      } else if (a < b) {
        b -= (b - 1) / a * a;
      } else {
        break;
      }
    }
    if(a == 1 || b == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
