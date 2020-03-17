// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int Mod = 1e9 + 7;

int n, q;
char s[N];
int z[N], po[N];

int main()
{
  po[0] = 1;
  for(int i = 1 ; i < N ; i++) {
    po[i] = (2 * po[i - 1]) % Mod;
  }
  scanf("%d%d", &n, &q);
  scanf("%s", s);
  for(int i = 0 ; i < n ; i++) {
    z[i] = s[i] == '0';
    if(i) z[i] += z[i - 1];
  }
  while(q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    int zeros = z[r] - (l ? z[l - 1] : 0);
    int ones = r - l + 1 - zeros;
    int ans = (1LL * po[zeros] * (po[ones] - 1)) % Mod;
    cout << ans << endl;
  }
  return 0;
}
