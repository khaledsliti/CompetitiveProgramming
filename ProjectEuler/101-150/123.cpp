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

namespace time_lib {
  std::chrono::system_clock::time_point start, last_time_cap;

  void init_time()
  {
    last_time_cap = start = std::chrono::high_resolution_clock::now();
  }

  void print_time(string name = "None")
  {
    chrono::system_clock::time_point now = std::chrono::high_resolution_clock::now();
    long long from_start = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
    long long from_last = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_time_cap).count();
    cerr << name << " - from last = " << from_last << " ms, from start = " << from_start << " ms.\n";
    last_time_cap = now;
  }
}

const int N = 3e6 + 1;

int np[N];
vector<int> pr;
vector<ll> rem;

ll mult(ll a, ll b, ll mod) {
  if(b == 0) return 0LL;
  if(b & 1) return (a + mult(a, b - 1, mod)) % mod;
  ll r = mult(a, b >> 1, mod);
  return (r + r) % mod;
}

// ll mult(ll a, ll b, ll mod) {
//   return a % mod * (b % mod) % mod;
// }

ll pow(ll a, ll b, ll mod) {
  if(!b) return 1LL % mod;
  if(b & 1) return mult(a, pow(a, b - 1, mod), mod);
  ll r = pow(a, b >> 1, mod);
  return mult(r, r, mod);
}

int main()
{
  time_lib::init_time();
  for(int i = 2; i < N; i++) {
    if(!np[i]) {
      pr.pb(i);
      for(int j = 2 * i; j < N; j += i)
        np[j] = 1;
    }
  }
  for(int i = 0; i < sz(pr); i++) {
    ll mod = 1LL * pr[i] * pr[i];
    ll sum = pow(pr[i] - 1, i + 1, mod) + pow(pr[i] + 1, i + 1, mod);
    sum %= mod;
    rem.push_back(sum);
  }
  for(int i = 2; i < sz(rem); i += 2)
    assert(rem[i] > rem[i - 2]);
  time_lib::print_time("pre");
  return 0;
}
