// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int Mod =  998244353;

long long myPow(long long a, long long b) {
  if(!b) return 1;
  long long r = myPow(a, b >> 1);
  r = (r * r) % Mod;
  if(b & 1) r = (r * a) % Mod;
  return r;
}

int main()
{
  long long n, m, L, R;
  cin >> n >> m >> L >> R;
  long long tot = n * m;
  long long E = (R - L) / 2 + 1;
  long long O = (R - L + 1) / 2;
  long long inv = myPow(2, Mod - 2);
  if(tot & 1) cout << myPow(myPow(R - L + 1, n), m) << endl;
  else cout << (myPow(myPow(E + O, n), m) + myPow(myPow(E - O, n), m)) % Mod * inv % Mod << endl;
  return 0;
}
