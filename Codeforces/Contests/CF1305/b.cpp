// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

string s;

int main()
{
  cin >> s;
  int l = 0, r = sz(s) - 1;
  vector<int> sol;
  while(l < r) {
    if(s[l] == ')') l++;
    else if(s[r] == '(') r--;
    else sol.pb(l++), sol.pb(r--);
  }
  sort(all(sol));
  if(sz(sol)){
    cout << 1 << endl;
    cout << sz(sol) << endl;
    for(int i = 0 ; i < sz(sol) ; i++)
      cout << sol[i] + 1 << " ";
  } else {
    cout << 0 << endl;
  }
  return 0;
}
