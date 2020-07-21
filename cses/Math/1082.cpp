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

const int N = 1e6 + 5;
const int Mod = 1e9 + 7;

long long n;

long long po(long long a, long long b) {
  long long r = 1;
  while(b > 0) {
    if(b & 1) r = (r * a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return r;
}

int main()
{
  while(cin >> n) {
    long long ans = 0;
    for(long long d = 1; d * d <= n; d++) {
      ans = (ans + d * ((n / d - 1) % Mod) % Mod) % Mod;
    }
    ans += n % Mod * ((n + 1) % Mod) % Mod * po(2, Mod - 2) % Mod;
    ans = (ans + Mod) % Mod;
    cerr << ans << endl;
  }
  return 0;
}
