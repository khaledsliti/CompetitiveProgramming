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
  int T;
  cin >> T;
  while(T--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if(x > y) swap(x, y);
    if(b > 2 * a) {
      cout << 1LL * a * (x + y) << endl;
    } else {
      cout << 1LL * b * x + 1LL * a * (y - x) << endl;
    }
  }
  return 0;
}
