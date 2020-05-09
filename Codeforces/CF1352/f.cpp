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

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int a, b, c;
    cin >> a >> b >> c;
    string r = "";
    if(b > 0)
      for(int i = 0 ; i <= b; i++) {
        if(i & 1) r += '0';
        else r += '1';
      }
    if(a > 0) {
      if(!sz(r)) {
        cout << string(a + 1, '0') << endl;
        continue;
      }
      for(int i = 0 ; i < sz(r); i++) {
        if(r[i] == '0') {
          string x = string(a, '0');
          r.insert(r.begin() + i, all(x));
          break;
        }
      }
    }
    if(c > 0) {
      if(!sz(r)) {
        cout << string(c + 1, '1') << endl;
        continue;
      }
      for(int i = 0 ; i < sz(r); i++) {
        if(r[i] == '1') {
          string x = string(c, '1');
          r.insert(r.begin() + i, all(x));
          break;
        }
      }
    }
    cout << r << endl;
  }
  return 0;
}
