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

const int N = 2e5 + 5;

int n, q;
ll p[N];

int main()
{
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    if(i) p[i] += p[i - 1];
  }
  while(q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ll ans = p[b] - (a > 0 ? p[a - 1] : 0);
    cout << ans << endl;
  }
  return 0;
}
