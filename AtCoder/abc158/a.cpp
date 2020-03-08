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
  string s;
  cin >> s;
  if(s[0] != s[1] || s[0] != s[2])
    cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
