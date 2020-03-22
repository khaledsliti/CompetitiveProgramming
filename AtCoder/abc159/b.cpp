// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

bool pal(string s) {
  for(int i = 0 ; i < sz(s) / 2 ; i++)
    if(s[i] != s[sz(s) - 1 - i])
      return false;
  return true;
}


int main()
{
  string s;
  cin >> s;
  int n = sz(s);
  if(pal(s) && pal(s.substr(0, n / 2)) && pal(s.substr(n / 2 + 1, n / 2)))
    cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
