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

string get(int x) {
  string s = "";
  s += char('0' + x / 10);
  s += char('0' + x % 10);
  return s;
}

bool palin(int t) {
  int h = t / 60;
  int m = t % 60;
  string s = get(h) + get(m);
  // cout << s << endl;
  string r = s;
  reverse(all(r));
  return s == r;
}

void solve() {
  int h, m, x;
  scanf("%d:%d %d", &h, &m, &x);
  int cur = h * 60 + m;
  set<int> seen;
  int ans = 0;
  while(seen.find(cur) == seen.end()) {
    ans += palin(cur);
    seen.insert(cur);
    cur = (cur + x) % 1440;
  }
  cout << ans << endl;
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
