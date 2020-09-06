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

int main()
{
  int n;
  cin >> n;
  double ans = 1e18;
  for(int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    ans = min(ans, sqrt(x * x + y * y + z * z));
  }
  cout << fixed << setprecision(3) << ans << endl;
  return 0;
}
