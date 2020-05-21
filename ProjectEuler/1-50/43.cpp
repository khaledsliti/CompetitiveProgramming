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

vector<int> pr {2, 3, 5, 7, 11, 13, 17};

int main()
{
  ll ans = 0;
  vector<int> d {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  do {
    if(d[0] == 0) continue;
    ll num = 0;
    for(int i = 0; i < sz(d); i++)
      num = num * 10 + d[i];
    bool good = true;
    for(int i = 1; i < 8; i++) {
      int cur = d[i] * 100 + d[i + 1] * 10 + d[i + 2];
      good &= cur % pr[i - 1] == 0;
    }
    if(good) ans += num, cout << num << endl;
  }while(next_permutation(all(d)));
  cout << ans << endl;
  return 0;
}
