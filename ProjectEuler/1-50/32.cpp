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
  int d[9];
  iota(d, d + 9, 1);
  ll ans = 0;
  set<int> s;
  do {
    ll a = 0;
    for(int i = 0; i <= 6; i++) {
      a = 10 * a + d[i];
      ll b = 0;
      for(int j = i + 1; j <= 7; j++) {
        b = b * 10 + d[j];
        ll c = 0;
        for(int k = j + 1; k < 9; k++) {
          c = c * 10 + d[k];
        }
        if(a * b == c) {
          s.insert(c);
        }
      }
    }
  }while(next_permutation(d, d + 9));
  for(auto x : s)
    ans += x;
  cout << ans << endl;
  return 0;
}
