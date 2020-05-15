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


int n;

void solve() {
  cin >> n;
  n >>= 1;
  int len = 1;
  long long ans = 0;
  for(int i = 0; i < n; i++){
    ans += 1LL * (i + 1) * (4 * len + 4);
    len += 2;
  }
  cout << ans << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
