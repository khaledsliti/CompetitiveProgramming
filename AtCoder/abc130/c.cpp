#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long h, w;
int x, y;

int main()
{
  cin >> h >> w;
  cin >> x >> y;
  bool b = (x == 0 || x == w || y == 0 || y == h);
  cout << fixed << setprecision(12) << h * w / 2.0 << " " << !b << endl;
  return 0;
}
