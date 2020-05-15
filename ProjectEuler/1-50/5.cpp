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

ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

int main()
{
  int ans = 2;
  for(int i = 3; i <= 20; i++)
    ans = lcm(ans, i);
  cout << ans << endl;
  return 0;
}
