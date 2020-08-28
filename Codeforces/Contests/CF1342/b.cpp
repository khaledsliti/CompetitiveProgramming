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
    string s;
    cin >> s;
    int a = 1;
    for(int i = 1 ; i < sz(s) ; i++)
      a &= s[i] == s[0];
    if(a) cout << s << endl;
    else {
      for(int i = 0 ; i < sz(s) ; i++) {
        cout << "01";
      }
      cout << endl;
    }
  }
  return 0;
}
