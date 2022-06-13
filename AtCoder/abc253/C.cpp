// RedStone
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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int q; cin >> q;
  map<int, int> cnt;
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int x; cin >> x;
      cnt[x]++;
    } else if(t == 2) {
      int x, c; cin >> x >> c;
      c = min(c, cnt[x]);
      cnt[x] -= c;
      if(cnt[x] == 0) {
        cnt.erase(x);
      }
    } else {
      cout << cnt.rbegin()->first - cnt.begin()->first << endl;
    }
  }
  return 0;
}
