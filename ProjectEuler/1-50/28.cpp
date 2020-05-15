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

ll f(int i) {
  ll vi = 4 * i * i - 10 * i + 7;
  return 4 * vi + 12 * (i - 1);
}

int main()
{
  int n = 1001;
  int lim = (n + 1) >> 1;
  ll ans = 1;
  for(int i = 2; i <= lim; i++)
    ans += f(i);
  cout << ans << endl;
  return 0;
}
