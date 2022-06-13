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

int n, k;
string s;

int get(const string& s) {
  // cout << s << endl;
  int r = 0;
  for(int i = 0; i + 1 < sz(s); i++) {
    r += 10 * (s[i] - '0') + (s[i + 1] - '0'); 
  }
  // cout << r << endl;
  return r;
}

void solve() {
  cin >> n >> k >> s;
  if(n == 2) {
    int ans = get(s);
    if(k > 0) {
      reverse(all(s));
      ans = min(ans, get(s));
    }
    cout << ans << endl;
    return;
  }
  int ans = get(s);
  for(char c : {'0', '1'}) {
    int f = -1, l = -1;
    for(int i = 1; i + 1 < sz(s); i++) {
      if(s[i] == c) {
        if(f == -1) f = i;
        l = i;
      }
    }
    if(f == -1 && s[n - 1] == c) {
      f = n - 1;
    }
    if(l == -1 && s[0] == c) {
      l = 0;
    }
    ans = min(ans, get(s));
    if(f != -1 && k >= f) {
      swap(s[0], s[f]);
      ans = min(ans, get(s));
      swap(s[0], s[f]);
    }
    if(l != -1 && k >= n - 1 - l) {
      swap(s[l], s[n - 1]);
      ans = min(ans, get(s));
      swap(s[l], s[n - 1]);
    }
    if(f != -1 && l != -1 && l > f && k >= f + n - 1 - l) {
      swap(s[0], s[f]);
      swap(s[l], s[n - 1]);
      ans = min(ans, get(s));
      swap(s[0], s[f]);
      swap(s[l], s[n - 1]);
    }
  }
  cout << ans << endl;
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
