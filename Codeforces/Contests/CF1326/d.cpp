// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const long long mod1 = 1000000009;
const long long modInverse1 = 554687505;
 
const long long mod2 = 1190494759;
const long long modInverse2 = 976577732;

const long long base = 128;
const int N = 1e6 + 5;
const int A = 26;

int n;
char s[N];

long long h1[N][2];
long long h2[N][2];

long long bp1[N], bp2[N], inv1[N], inv2[N];

void build_hash() {
  bp1[0] = bp2[0] = inv1[0] = inv2[0] = 1;
  for(int i = 1 ; i <= n ; i++) {
    bp1[i] = (bp1[i - 1] * base) % mod1;
    bp2[i] = (bp2[i - 1] * base) % mod2;
    inv1[i] = (inv1[i - 1] * modInverse1) % mod1;
    inv2[i] = (inv2[i - 1] * modInverse2) % mod2;
  }
  for(int i = 0 ; i < n ; i++) {
    h1[i][0] = ((i > 0 ? h1[i - 1][0] : 0) * base + s[i] - 'a') % mod1;
    h2[i][0] = ((i > 0 ? h2[i - 1][0] : 0) * base + s[i] - 'a') % mod2;
  }
  for(int i = n - 1 ; i >= 0 ; i--) {
    h1[i][1] = ((i + 1 < n ? h1[i + 1][1] : 0) * base + s[i] - 'a') % mod1;
    h2[i][1] = ((i + 1 < n ? h2[i + 1][1] : 0) * base + s[i] - 'a') % mod2;
  }
}

bool is_palind(int l, int r) {
  int len = r - l + 1;

  long long vl1 = h1[r][0];
  if(l > 0) {
    vl1 -= h1[l - 1][0] * bp1[len] % mod1;
    vl1 = (vl1 % mod1 + mod1) % mod1;
  }
  long long vr1 = h1[l][1];
  if(r + 1 < n) {
    vr1 -= h1[r + 1][1] * bp1[len] % mod1;
    vr1 = (vr1 % mod1 + mod1) % mod1;
  }
  
  long long vl2 = h2[r][0];
  if(l > 0) {
    vl2 -= h2[l - 1][0] * bp2[len] % mod2;
    vl2 = (vl2 % mod2 + mod2) % mod2;
  }
  long long vr2 = h2[l][1];
  if(r + 1 < n) {
    vr2 -= h2[r + 1][1] * bp2[len] % mod2;
    vr2 = (vr2 % mod2 + mod2) % mod2;
  }

  return vl1 == vr1 && vl2 == vr2;
}

void solve() {
  build_hash();
  int l = 0, r = n - 1;
  while(l < r && s[l] == s[r])
    l++, r--;
  string res = "";
  for(int i = 0 ; i < l ; i++)
    printf("%c", s[i]);
  if(l <= r) {
    int cnt1 = 0, cnt2 = 0;
    for(int i = l ; i <= r ; i++)
      if(is_palind(l, i))
        cnt1 = i - l + 1;
    for(int i = r ; i >= l ; i--)
      if(is_palind(i, r))
        cnt2 = r - i + 1;
    if(cnt1 >= cnt2) {
      for(int it = 0 ; it < cnt1 ; it++)
        printf("%c", s[it + l]);
    } else {
      for(int it = 0 ; it < cnt2 ; it++)
        printf("%c", s[r - cnt2 + 1 + it]);
    }
  }
  for(int i = r + 1 ; i < n ; i++)
    printf("%c", s[i]);
  printf("\n");
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%s", s);
    n = strlen(s);
    solve();
  }
  return 0;
}
