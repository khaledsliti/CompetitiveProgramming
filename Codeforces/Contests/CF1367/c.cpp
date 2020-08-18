// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  bool same = true;
  for(int i = 0; i < n; i++)
    same &= (s[i] == '0');
  if(same) {
    cout << 1 + (n - 1) / (k + 1) << endl;
    return;
  }
  int ans = 0;
  int l = 0, r = n - 1;
  while(s[l] != '1') l++;
  while(s[r] != '1') r--;
  ans += l / (k + 1) + (n - r - 1) / (k + 1);

  for(int i = l; i < r; i++) {
    if(s[i] == '0') {
      int j = i;
      while(j < r && s[j] == '0')
        j++;
      int len = j - i;
      if(len >= k) {
        len -= k;
        ans += len / (k + 1);
      }
      i = j;
    }
  }

  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
