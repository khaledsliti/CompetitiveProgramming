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

int n, m, k;
int r[N], c[N];

int calc(int mod, int target) {
  if(mod >= target) {
    return mod - target;
  }
  return mod + k - target;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  int sr = 0, sc = 0;
  for(int i = 0; i < n; i++) {
    cin >> r[i];
    sr = (sr + r[i]) % k;
  }
  for(int i = 0; i < m; i++) {
    cin >> c[i];
    sc = (sc + c[i]) % k;
  }
  if(sr != sc) {
    cout << -1 << endl;
    return 0;
  }
  long long ans = 0, addr = 0, addc = 0;
  for(int i = 0; i < n; i++) {
    long long cur = 1LL * (k - 1) * m;
    int mod = cur % k;
    ans += cur;
    addr += calc(mod, r[i]);
  }
  for(int i = 0; i < m; i++) {
    addc += calc(1LL * (k - 1) * n % k, c[i]);
  }
  ans -= max(addr, addc);
  cout << ans << endl;
  return 0;
}
