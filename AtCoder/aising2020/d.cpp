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

const int N = 2e5 + 5;

int n, a, b;
string s;
ll ra[N], rb[N], p2a[N], p2b[N];

void calc(ll* r, ll* p, int mod) {
  r[0] = 0;
  p[0] = 1;
  for(int i = 1; i <= n; i++) {
    p[i] = (p[i - 1] * 2) % mod;
    r[i] = (r[i - 1] * 2 + s[i - 1] - '0') % mod;
  }
}

int solve(int n) {
  if(n == 0) return 0;
  int mod = __builtin_popcount(n);
  return 1 + solve(n % mod);
}

int main()
{
  cin >> n >> s;
  int popcount = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '1')
      popcount++;
  }
  a = popcount + 1;
  b = popcount - 1;
  calc(ra, p2a, a);
  if(b > 0) calc(rb, p2b, b);
  for(int i = 0; i < n; i++) {
    int cur = s[i] - '0';
    if(cur == 0) { // change to 1
      int ans = (ra[n] + p2a[n - 1 - i]) % a;
      cout << 1 + solve(ans) << endl;
    } else { // change to 0
      if(b == 0) cout << 0 << endl;
      else {
        int ans = (rb[n] - p2b[n - 1 - i]) % b;
        ans = (ans + b) % b;
        cout <<  1 + solve(ans) << endl;
      }
    }
  }
  return 0;
}
