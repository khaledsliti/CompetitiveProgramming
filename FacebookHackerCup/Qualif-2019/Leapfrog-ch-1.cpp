#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  ios::sync_with_stdio(false);
  int T, tc(1);
  cin >> T;
  while(T--){
    string s;
    cin >> s;
    int a = 0, b = 0;
    for(int i = 1 ; i < sz(s) ; i++){
      a += s[i] == '.';
      b += s[i] == 'B';
    }
    cout << "Case #" << tc++ << ": " << (a <= b && a > 0 ? "Y" : "N") << endl;
  }
  return 0;
}
