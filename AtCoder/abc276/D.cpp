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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n; cin >> n;
  int g = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    g = __gcd(g, a[i]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int d = a[i] / g;
    while(d % 2 == 0) {
      d /= 2;
      ans++;
    }
    while(d % 3 == 0) {
      d /= 3;
      ans++;
    }
    if(d > 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
