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
  int n; cin >> n; 
  string s; cin >> s;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    vector<int> cnt(10, 0);
    for(int j = i; j < n && j - i + 1 <= 100; j++) {
      cnt[s[j] - '0']++;
      bool ok = true;
      int d = 0;
      for(int c = 0; c < 10; c++) {
        d += cnt[c] > 0;
      }
      for(int c = 0; c < 10; c++) {
        if(cnt[c] > d) {
          ok = false;
        }
      }
      ans += ok;
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
