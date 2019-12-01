#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

char s[N];

ostream& operator<<(ostream& cout, const vector<pair<int, int>>& v)
{
  for(int i = 0 ; i < sz(v) ; i++)
    cout << v[i].first << " " << v[i].second << endl;
  cout << endl;
  return cout;
}

pair<int, int> solve(vector<int>& v)
{
  int n = sz(v);
  if(n == 0)
    return {1, 1};
  vector<pair<int, int>> dp(n + 1, {0, 0});
  int x = 0, mn = 0, mx = 0;
  for(int i = n - 1 ; i >= 0 ; i--){
    x += -1 * v[i];
    mn = min(mn, x);
    mx = max(mx, x);
    dp[i] = { mn - x, mx - x };
  }
  int width = dp[0].second - dp[0].first + 1;
  int ans = width;
  x = mn = mx = 0;
  for(int i = 0 ; i <= n ; i++){
    // calc
    for(int d = -1 ; d <= 1 ; d += 2){
      int right = max(mx, x + d + dp[i].second);
      int left = min(mn, x + d + dp[i].first);
      ans = min(ans, right - left + 1);
    }
    // advance
    if(i < n){
      x += v[i];
      mn = min(mn, x);
      mx = max(mx, x);
    }
  }
  return { width, ans };
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%s", s);
    vector<int> a, b;
    for(int i = 0 ; s[i] ; i++){
      if(s[i] == 'D')
        a.pb(1);
      else if(s[i] == 'A')
        a.pb(-1);
      else if(s[i] == 'W')
        b.pb(1);
      else
        b.pb(-1);
    }
    pair<int, int> x = solve(a);
    pair<int, int> y = solve(b);
    printf("%lld\n", min(1LL * x.first * y.second, 1LL * x.second * y.first));
  }
  return 0;
}
