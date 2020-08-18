// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e6 + 5;

int n, k;
char s[N];
int acc[N];
vector<int> a, b;
int dp[N];

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  for(int i = 0; i < n; i++) {
    acc[i] = s[i] == '1';
    if(i) acc[i] += acc[i - 1];
  }
  int best = 1e9;
  for(int st = 0; st < k; st++) {
    a.clear(); b.clear();
    for(int i = 0; i < n; i += k) {
      int r = min(n - 1, i + k - 1);
      int j = i + st;
      int zero = acc[r] - (i > 0 ? acc[i - 1] : 0);
      int one = zero;
      if(j < n) {
        if(s[j] == '0') one++;
        else one--;
      }
      a.push_back(one);
      b.push_back(zero);
    }
    vector<int> suff(sz(b) + 1, 0);
    for(int i = sz(b) - 1; i >= 0; i--)
      suff[i] = suff[i + 1] + b[i];
    dp[0] = a[0];
    int pref = b[0];
    int cur = min(a[0] + suff[1], suff[0]);
    for(int i = 1; i < sz(a); i++) {
      dp[i] = a[i] + min(dp[i - 1], pref);
      pref += b[i];
      cur = min(cur, dp[i] + suff[i + 1]);
    }
    best = min(best, cur);
  }
  printf("%d\n", best);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
