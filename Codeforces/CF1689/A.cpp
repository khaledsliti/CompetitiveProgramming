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



void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  string a, b;
  cin >> a >> b;
  sort(all(a));
  sort(all(b));
  reverse(all(a)), reverse(all(b));
  int cnt = 0;
  string res;
  while(sz(a) && sz(b)) {
    if(cnt == -k || (a.back() < b.back() && cnt < k)) {
      res.push_back(a.back());
      a.pop_back();
      if(cnt < 0) {
        cnt = 1;
      } else {
        cnt++;
      }
    } else {
      res.push_back(b.back());
      b.pop_back();
      if(cnt > 0) {
        cnt = -1;
      } else {
        cnt--;
      }
    }
  }
  cout << res << endl;
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
