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

const int Mod = 1e9 + 7;

ll po(ll a, ll b) {
  ll r = 1;
  while(b > 0) {
    if(b & 1) r = (r * a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return r;
}

int main()
{
  long long n;
  cin >> n;
  ll ans = 0;
  ll cur = 1;
  while(cur <= n) {
    ll last = cur + (n % cur) / (n / cur);
    ll sum = (cur % Mod + last % Mod) % Mod * ((last - cur + 1) % Mod) % Mod * po(2, Mod - 2) % Mod;
    ans = (ans + sum * (n / cur) % Mod) % Mod;
    cur = last + 1;
  }
  cout << ans << endl;
  return 0;
}
