// RedStone
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

const int N = 1e6 + 1;
const int Mod = 998244353;

template<int N, int Mod>
struct Combination {
  int fact[N], inv[N], p2[N];
  int pow(int a, int b) {
    if(!b) return 1;
    int r = pow(a, b >> 1);
    r = 1LL * r * r % Mod;
    if(b & 1) r = 1LL * r * a % Mod;
    return r;
  }
  Combination() {
    fact[0] = inv[0] = p2[0] = 1;
    for(int i = 1; i < N; i++) {
      fact[i] = 1LL * fact[i - 1] * i % Mod;
      inv[i] = pow(fact[i], Mod - 2);
      p2[i] = 2LL * p2[i - 1] % Mod;
    }
  }
  int choose(int n, int k) {
    if(k < 0 || k > n) return 0;
    return 1LL * fact[n] * inv[n - k] % Mod * inv[k] % Mod;
  }
};


int n;
Combination<N, Mod> comb;

int solve(int av, int cur) {
  if(cur == 0) return av == 0;
  int r = 0;
  if(av < n) {
    r = (r + (n - av) * solve(av, cur - 1) % Mod) % Mod;
  }
  
}

int main()
{
  cin >> n;
  cout << solve(0, n) << endl;
  return 0;
}
