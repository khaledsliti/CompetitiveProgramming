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

const int N = 2e5 + 3;
const int Mod = 998244353;

int n;
int arr[N];
int fact[N];

int mpow(int a, int b) {
  if(!b) return 1;
  int r = mpow(a, b >> 1);
  r = 1LL * r * r % Mod;
  if(b & 1) r = 1LL * r * a % Mod;
  return r;
}

int inv(int a) {
  return mpow(a, Mod - 2);
}

int cnk(int n, int k) {
  return 1LL * fact[n] * inv(fact[n - k]) % Mod * inv(fact[k]) % Mod;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  if(arr[n - 1] > arr[n - 2] + 1) {
    cout << 0 << endl;
    return;
  }
  if(arr[n - 1] == arr[n - 2]) {
    cout << fact[n] << endl;
    return;
  }
  int idx = n - 2;
  while(idx >= 0 && arr[idx] == arr[n - 2]) {
    idx--;
  }
  int b = idx + 1;
  int a = n - b;
  long long ans = fact[a] - (a > 0 ? fact[a - 1] : 0);
  ans = ans * cnk(n, a) % Mod;
  ans = ans * fact[b] % Mod;
  ans = (ans + Mod) % Mod;
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  fact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = 1LL * fact[i - 1] * i % Mod;
  }

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
