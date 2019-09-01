#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()



int main()
{
  string a, b;
  cin >> a >> b;
  int ans = 0;
  for(int i = 0 ; i < 3 ; i++)
    ans += a[i] == b[i];
  cout << ans << endl;
  return 0;
}
