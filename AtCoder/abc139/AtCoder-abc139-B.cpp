#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()



int main()
{
  int a, b;
  cin >> a >> b;
  int act = 1, ans = 0;
  while(act < b)
    act += a - 1, ans++;
  cout << ans << endl;
  return 0;
}
