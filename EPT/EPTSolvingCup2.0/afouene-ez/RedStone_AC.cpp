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

const int N = 1e5 + 5;
const int Mod = 1e9 + 7;

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

Combination<N, Mod> cnb;

void assertIn(long long a, long long l, long long r) {
  assert(a >= l && a <= r);
}

void solve() {
  int n; cin >> n;
  assertIn(n, 1, 1e5);
  long long ans = 1LL * cnb.fact[n] * cnb.pow(, Mod - 2) % Mod;

  
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  assertIn(T, 1, 1e5);
  while(T--) {
    solve();
  }

  return 0;
}

/*
N! / pow(N, N)
N! * pow(pow(N, N), Mod - 2)
*/