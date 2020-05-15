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

int main()
{
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int sum = 0;
  int r = min(a, k);
  sum += r;
  k -= r;
  r = min(b, k);
  k -= r;
  r = min(c, k);
  sum -= r;
  cout << sum << endl;
  return 0;
}
