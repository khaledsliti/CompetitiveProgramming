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
    int x;
    cin >> x;
    int ans = 0;
    bool found = false;
    for(int i = 1; i <= 9 && !found; i++) {
      int cur = 0;
      for(int it = 0; it < 4 && !found; it++) {
        cur = cur * 10 + i;
        ans += it + 1;
        if(x == cur) {
          found = true;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
