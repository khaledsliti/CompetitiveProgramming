// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


string solve() {
  int x, y;
  cin >> x >> y;
  int a = abs(x), b = abs(y);
  int len = 0;
  for(int i = 0 ; (1 << i) <= max(a, b) ; i++)
    len = i;
  string ret = "";
  for(int i = 0 ; a > 0 || b > 0 ; i++) {
    if(a == 1 && b == 0) {
      ret += 'E';
    } else if(a == 0 && b == 1) {
      ret += 'N';
    } else {
      int a0 = a & 1;
      int b0 = b & 1;
      // D(a); D(b); D(a0); D(b0);
      int a1 = (a >> 1) & 1, b1 = (b >> 1) & 1;
      // D(a1), D(b1);
      if(a0 == b0)
        return "IMPOSSIBLE";
      if(a0 == 1) {
        if(a1 == b1) {
          a++;
          ret += 'W';
        } else {
          a--;
          ret += 'E';
        }
      } else {
        if(a1 == b1) {
          b++;
          ret += 'S';
        } else {
          b--;
          ret += 'N';
        }
      }
    }
    a >>= 1;
    b >>= 1;
  }
  if(x < 0) 
    for(int i = 0 ; i < sz(ret) ; i++)
      if(ret[i] == 'E') ret[i] = 'W';
      else if(ret[i] == 'W') ret[i] = 'E';
  if(y < 0) 
    for(int i = 0 ; i < sz(ret) ; i++)
      if(ret[i] == 'N') ret[i] = 'S';
      else if(ret[i] == 'S') ret[i] = 'N';
  return ret;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--) {
    cout << "Case #" << tc++ << ": " << solve() << endl;
  }
  return 0;
}
