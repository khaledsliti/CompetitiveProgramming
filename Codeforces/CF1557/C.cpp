// Guess Who's Back
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

const int N = 2e5 + 5;
const int Mod = 1e9 + 7;

int n, k;
int fact[N];
int ways;
int memo[N][2];

int mpow(int a, int b) {
  if(!b) return 1;
  int r = mpow(a, b >> 1);
  r = (1LL * r * r) % Mod;
  if(b & 1) r = (1LL * r * a) % Mod;
  return r;
}

int inv(int a) {
  return mpow(a, Mod - 2);
}

int cnk(int a, int b) {
  return 1LL * fact[a] * inv(fact[b]) % Mod * inv(fact[a - b]) % Mod;
}

int solve(int bit, int bigger) {
  if(bit <= 0) return 1;
  int& r = memo[bit][bigger];
  if(r != -1) return r;
  if(bigger) {
    r = (1LL * solve(bit - 1, bigger) * mpow(2, n)) % Mod;
  } else {
    // all 1
    r = solve(bit - 1, n % 2 == 0);
    // at least one zero
    r = (r + 1LL * ways * solve(bit - 1, 0) % Mod) % Mod;
  }
  return r;
}

void solve() {
  cin >> n >> k;
  ways = 1;
  for(int i = 2; i < n; i += 2) {
    ways = (ways + cnk(n, i)) % Mod;
  }
  memset(memo, -1, sizeof memo);
  int ans = solve(k, 0);
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  fact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = 1LL * i * fact[i - 1] % Mod;
  }

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
