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

int n;
string s, p;

int main()
{
  cin >> n >> s >> p;
  vector<int> a, b;
  for(int i = 0 ; i < n ; i++) {
    if(s[i] != p[i]){
      if(s[i] == 'a') a.pb(i);
      else b.pb(i);
    }
  }
  vector<pair<int, int>> ans;
  while(sz(a) >= 2) {
    ans.pb({ a[sz(a) - 1], a[sz(a) - 2] });
    a.pop_back();
    a.pop_back();
  }
  while(sz(b) >= 2) {
    ans.pb({ b[sz(b) - 1], b[sz(b) - 2] });
    b.pop_back();
    b.pop_back();
  }
  if((sz(a) ^ sz(b)))
    return cout << -1 << endl, 0;
  if(sz(a)){
    ans.push_back({a[0], a[0]});
    ans.push_back({a[0], b[0]});
  }
  printf("%d\n", sz(ans));
  for(int i = 0 ; i < sz(ans) ; i++)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  return 0;
}
