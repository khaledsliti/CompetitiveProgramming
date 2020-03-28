// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long calc(long long n, long long p) {
  long long ans = 0;
  while(n > 0) {
    ans += n / p;
    n /= p;
  }
  return ans;
}

int main()
{
  long long n, b;
  cin >> n >> b;

  long long ans = 4e18;
  for(long long i = 2 ; i * i <= b ; i++) {
    if(b % i == 0) {
      int m = 0;
      while(b % i == 0)
        b /= i, m++;
      ans = min(ans, calc(n, i) / m);
    }
  }
  if(b > 1)
    ans = min(ans, calc(n, b));
  cout << ans << endl;
  return 0;
}
