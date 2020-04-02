// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;

void solve() {
  scanf("%d%d", &n, &k);
  int tot = n / k;
  vector<string> s(tot);
  for(int i = 0 ; i < n ; i++) {
    int c; scanf(" %c", &c);
    s[i / k].pb(c);
  }
  int l = 0, r = k - 1, ans = 0;
  while(l < r) {
    int best = 1e9;
    for(char cur = 'a' ;  cur <= 'z' ; cur++) {
      int opt = 0;
      for(int i = 0 ; i < tot ; i++) {
        opt += (s[i][l] != cur) + (s[i][r] != cur);
      }
      best = min(best, opt);
    }
    ans += best;
    l++;
    r--;
  }
  if(l == r) {
    int best = 1e9;
    for(char cur = 'a' ;  cur <= 'z' ; cur++) {
      int opt = 0;
      for(int i = 0 ; i < tot ; i++) {
        opt += (s[i][l] != cur);
      }
      best = min(best, opt);
    }
    ans += best;
  }
  cout << ans << endl;
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) 
    solve();
  return 0;
}
