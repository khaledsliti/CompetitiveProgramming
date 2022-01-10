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

const int N = 5007;
const int Mod = 998244353;

int C[N][N];

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> pref(n);
  for(int i = 0; i < n; i++) {
    pref[i] = s[i] == '1';
    if(i > 0) {
      pref[i] += pref[i - 1];
    }
  }
  auto sum = [&](int i, int j) { return pref[j] - (i > 0 ? pref[i - 1] : 0); };
  int ans = 1;
  if(pref[n - 1] >= k) {
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        int cnt = sum(i, j);
        if(cnt > k || cnt <= 0) continue;
        if(sum(i, i) == 0) cnt--;
        if(sum(j, j) == 0) cnt--;
        // cout << i << " " << j << " " << cnt << endl;
        ans = (ans + C[j - i - 1][cnt]) % Mod;
      }
    }
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  C[0][0] = 1;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
    }
  }

  int T = 1;
  while(T--) {
    solve();
  }
  return 0;
}
