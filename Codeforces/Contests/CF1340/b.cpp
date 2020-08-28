// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2006;

int n, k;
int a[N];
char s[N];
int dp[N][N];
int dig[10] = { 119, 18, 93, 91, 58, 107, 111, 82, 127, 123 };

int solve(int cur, int rem) {
  if(cur >= n)
    return rem == 0;
  int& r = dp[cur][rem];
  if(r != -1) return r;
  r = 0;
  // D(a[cur]);
  for(int d = 9; d >= 0; d--) {
    bool can = (dig[d] & a[cur]) == a[cur];
    int take = __builtin_popcount(dig[d] ^ a[cur]);
    // D(d); D(can); D(take); cerr << endl;
    if(can && take <= rem) {
      r |= solve(cur + 1, rem - take);
    }
  }
  return r;
}

string ans;
void trace(int cur, int rem) {
  if(cur >= n)
    return;
  for(int d = 9; d >= 0; d--) {
    bool can = (dig[d] & a[cur]) == a[cur];
    int take = __builtin_popcount(dig[d] ^ a[cur]);
    if(can && take <= rem && solve(cur + 1, rem - take)) {
      ans += char('0' + d);
      trace(cur + 1, rem - take);
      return;
    }
  }
}

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++) {
    scanf("%s", s);
    a[i] = 0;
    for(int j = 0 ; j < 7 ; j++) {
      a[i] <<= 1;
      if(s[j] == '1')
        a[i] |= 1;
    }
  }
  memset(dp, -1, sizeof dp);
  if(!solve(0, k)) {
    cout << -1 << endl;
  } else {
    ans = "";
    trace(0, k);
    cout << ans << endl;
  }
  return 0;
}
