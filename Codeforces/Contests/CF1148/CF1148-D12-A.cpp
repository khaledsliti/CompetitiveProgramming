#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
  long long a, b, c;
  cin >> a >> b >> c;
  long long m = min(a, b);
  c += m;
  long long r = max(a - m, b - m);
  cout << 2 * c + (r > 0) << endl;
  return 0;
}