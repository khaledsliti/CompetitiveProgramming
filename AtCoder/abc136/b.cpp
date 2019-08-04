#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int c(int x)
{
  if(x / 10 == 0)
    return 1;
  return 1 + c(x / 10);
}

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1 ; i <= n ; i++){
    ans += c(i) & 1;
  }
  cout << ans << endl;
  return 0;
}
