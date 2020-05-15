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

long long n = 600851475143LL;

int main()
{
  long long ans = -1;
  for(long long i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      n /= i;
      ans = i;
    }
  }
  if(n > 1) ans = n;
  cout << ans << endl;
  return 0;
}
