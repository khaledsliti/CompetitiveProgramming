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

int main()
{
  int ans = 0;
  for(int i = 1; i < 1000000; i++) {
    string r, s;
    for(int a = i; a > 0; a /= 10)
      r += char('0' + a % 10);
    s = r;
    reverse(all(s));
    bool pal = s == r;
    r.clear();
    for(int a = i; a > 0; a >>= 1)
      r += char('0' + (a & 1));
    s = r;
    reverse(all(s));
    pal &= s == r;
    if(pal) ans += i, cout << i << endl;
  }
  cout << ans << endl;
  return 0;
}
