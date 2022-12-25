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



int main()
{
  int x, y, n;
  cin >> x >> y >> n;
  int ans = x * n;
  ans = min(ans, n / 3 * y + (n % 3) * x);
  cout << ans << endl;
  return 0;
}
