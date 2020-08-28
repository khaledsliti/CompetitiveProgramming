// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    map<int, int> cnt;
    for(int i = 0 ; i < n ; i++) {
      int a; cin >> a;
      cnt[a]++;
    }
    vector<int> vals;
    for(auto x : cnt)
      vals.push_back(x.first);
    int best = 0;
    for(int x : vals) {
      int others = sz(vals) - 1;
      int cur = cnt[x];
      int ch1 = min(cur, others);
      int ch2 = min(cur - 1, others + 1);
      best = max(best, max(ch1, ch2));
    }
    cout << best << endl;
  }
  return 0;
}
