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

long long mpow(long long a, long long b) {
  if(!b) {
    return 1;
  }
  long long r = mpow(a, b >> 1);
  r = (r * r) % Mod;
  if(b & 1) {
    r = (r * a) % Mod;
  }
  return r;
}

void solve() {
  long long n;
  cin >> n;
  long long ans = (n * (n - 1) / 2) % Mod;
  ans += n * (n + 1) % Mod * (2 * n + 1) % Mod * mpow(3, Mod - 2) % Mod;
  ans %= Mod;
  ans = (ans - n * n % Mod) % Mod;
  ans = (ans + Mod) % Mod;
  cout << 2022 * ans % Mod << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}


/*
1   2   3   4   5
2   4   6   8   10
3   6   9   12  15
4   8   12  16  20
5   10  15  20  25

f(n) = f(n - 1) + n * n + (n - 1) * n

f(1) = 1
f(n) = f(n - 1) + 2 * n^2 - n


i^2
i * (i + 1)

*/