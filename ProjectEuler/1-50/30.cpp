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

const int N = 1e8;

bool check(int x) {
  ll s = 0;
  ll t = x;
  while(x > 0) {
    int d = x % 10;
    s += d * d * d * d * d;
    x /= 10;
  }
  return s == t;
}

int main()
{
  ll ans = 0;
  for(int i = 2; i < N; i++) {
    if(check(i))
      ans += i;
  }
  cout << ans << endl;
  return 0;
}
