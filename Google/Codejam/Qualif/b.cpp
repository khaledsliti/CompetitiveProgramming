// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve(int tc) {
  string s;
  cin >> s;
  int last = 0;
  string res = "";
  for(int i = 0 ; i < sz(s) ; i++) {
    int d = s[i] - '0';
    for(int i = 0 ; i < d - last ; i++)
      res += '(';
    for(int i = 0 ; i < last - d ; i++)
      res += ')';
    res += s[i];
    last = d;
  }
  for(int i = 0 ; i < last ; i++)
    res += ')';
  cout << "Case #" << tc << ": " << res << endl;
}

int main()
{
  int t, tc(1);
  cin >> t;
  while(t--) {
    solve(tc++);
  }
  return 0;
}
