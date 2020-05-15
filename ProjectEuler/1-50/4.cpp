// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int isPal(int x) {
  if(!x) return true;
  string r = "";
  while(x > 0) {
    r += char('0' + x % 10);
    x /= 10;
  }
  string s = r;
  reverse(all(s));
  return s == r;
}

int main()
{
  int ans = -1;
  for(int a = 100; a < 1000; a++)
    for(int b = 100; b < 1000; b++)
      if(isPal(a * b))
        ans = max(ans, a * b);
  cout << ans << endl;
  return 0;
}
