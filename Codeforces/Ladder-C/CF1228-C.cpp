// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;

long long myPow(long long a, long long b) {
  if(!b)
    return 1LL;
  long long r = myPow(a, b >> 1);
  r = (r * r) % mod;
  if(b & 1)
    r = (r * a) % mod;
  return r;
}

void add(int p, long long n, long long& ans) {
  long long cnt = 0;
  while(n > 0) {
    cnt += n / p;
    n /= p;
  }
  ans = (ans * myPow(p, cnt)) % mod;
}

int main()
{
  int x;
  long long n;
  cin >> x >> n;
  long long ans = 1;
  for(int i = 2 ; i * i <= x ; i++) {
    if(x % i == 0) {
      add(i, n, ans);
      while(x % i == 0)
        x /= i;
    }
  }
  if(x > 1)
    add(x, n, ans);
  cout << ans << endl;
  return 0;
}
