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
    if(s[i] == '0') {
      int j = i + 1;
      while(j < n && s[j] == '1') {
        j++;
      }
      int cnt = j - i - 1;
      if(j < n) {
        ans += max(0, 2 - cnt);
      }
      i = j - 1;
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
