#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//Constants

//Data

//Methods

int main()
{
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for(int i = 0 ; i + 2 < n ; i++)
    ans += s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C';
  cout << ans << endl;
  return 0;
}
