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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    bool good = true;
    if(sz(s) & 1) {
      for(int i = 0 ; i < sz(s) ; i++)
        good &= s[i] == s[0];
    } else {
      for(int i = 0 ; i < sz(s) ; i += 2)
        good &= s[i] == s[0];
      for(int i = 1 ; i < sz(s) ; i += 2)
        good &= s[i] == s[1];
    }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
