// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;



int main()
{
  int T;
  cin >> T;
  while(T--) {
    int a, b;
    cin >> a >> b;
    int c = 2 * a - b;
    if(c < 0 || c % 3 != 0) {
      cout << "NO" << endl;
    } else {
      int x = c / 3;
      int y = a - 2 * x;
      if(y >= 0) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
  return 0;
}
