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
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    s = "R" + s + "R";
    int best = 0;
    int last = 0;
    for(int i = 1 ; i < sz(s) ; i++) {
      if(s[i] == 'R') {
        best = max(best, i - last);
        last = i;
      }
    }
    cout << best << endl;
  }
  return 0;
}
