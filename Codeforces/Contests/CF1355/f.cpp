// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 640;

int isp[N];
vector<int> pr;


int ask(ll x) {
  cout << "? " << x << endl;
  int r;
  cin >> r;
  return r;
}

int main()
{
  for(int i = 2; i < N; i++)
    isp[i] = 1;
  for(int i = 2; i * i < N; i++)
    if(isp[i])
      for(int j = i * i; j < N; j += i)
        isp[j] = 0;
  for(int i = 0; i < N; i++)
    if(isp[i])
      pr.push_back(i);

  vector<ll> qr;
  int index = 0;
  ll limit = 1e18;
  while(index < sz(pr)) {
    ll cur = 1;
    while(index < sz(pr) && cur <= limit / pr[index])
      cur *= pr[index++];
    qr.push_back(cur);
  }

  int T;
  cin >> T;
  while(T--) {
    vector<ll> primes;
    for(int i = 0; i < sz(qr); i++) {
      int p = ask(qr[i]);
      for(int j = 2; j * j <= p; j++)
        if(p % j == 0) {
          primes.push_back(j);
          p /= j;
        }
      if(p > 1) primes.push_back(p);
    }
    limit = 1e9;
    for(int i = 0; i < sz(primes); i++) {
      ll& x = primes[i];
      ll y = x;
      while(x * y <= limit)
        x *= y;
    }
    ll ans = 1;
    for(int i = 0; i < sz(primes); i += 2) {
      ll cur = primes[i];
      if(i + 1 < sz(primes)) cur *= primes[i + 1];
      int x = ask(cur);
      for(int j = 2; j * j <= x; j++) {
        int deg = 0;
        while(x % j == 0) {
          x /= j;
          deg++;
        }
        ans *= (deg + 1);
      }
      if(x > 1) ans *= 2;
    }
    ans = max(8LL, 2 * ans);
    
    cout << "! " << ans << endl;
  }
  return 0;
}
