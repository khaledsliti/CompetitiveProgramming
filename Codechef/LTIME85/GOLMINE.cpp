// We only fail when we stop trying
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


void solve() {
  int n;
  cin >> n;
  double a = 0, b = 0;
  for(int i = 0; i < n; i++) {
    int g, x, y;
    cin >> g >> x >> y;
    a += 1.0 * g * y / (x + y);
    b += 1.0 * g * x / (x + y);
  }
  cout << fixed << setprecision(10) << a << " " << b << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
