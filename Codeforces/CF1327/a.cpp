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
    int n, k;
    cin >> n >> k;
    if(n < k || (n & 1) != (k & 1)) {
      cout << "NO" << endl;
    } else {
      int need = (n - k) / 2;
      if(need * 2 >= 1LL * k * (k - 1)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
  return 0;
}
