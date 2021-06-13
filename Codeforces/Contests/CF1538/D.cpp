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

int a, b, k;

int getSteps(int x) {
  int ans = 0;
  for(int i = 2; i * i <= x; i++) {
    while(x % i == 0) {
      x /= i;
      ans++;
    }
  }
  if(x > 1) ans++;
  return ans;
}

void solve() {
  cin >> a >> b >> k;
  int g = __gcd(a, b);
  if(k == 1) {
    if(a != b && min(a, b) == g) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
  }
  int mn = (a > g) + (b > g);
  int mx = getSteps(a) + getSteps(b);
  cout << (k >= mn && k <= mx ? "YES" : "NO") << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
