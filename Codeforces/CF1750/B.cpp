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
  long long ans = 0;
  int cnt[2] = {0, 0};
  for(int i = 0; i < n; i++) {
    int j = i;
    while(j < n && s[i] == s[j]) {
      j++;
    }
    int l = j - i;
    ans = max(ans, 1LL * l * l);
    i = j - 1;
    cnt[s[i] - '0'] += l;
  }
  ans = max(ans, 1LL * cnt[0] * cnt[1]);
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
