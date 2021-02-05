// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

int n, m, k;

int main()
{
  cin >> n >> m >> k;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int s = 0;
    for(int j = 0; j < k; j++) {
      int a; cin >> a;
      s += a;
    }
    int q; cin >> q;
    ans += q <= 10 && s >= m;
  }
  cout << ans << endl;
  return 0;
}
