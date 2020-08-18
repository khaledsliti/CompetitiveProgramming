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

int n;
string s;
int occ[10];

void solve() {
  cin >> s;
  n = sz(s);
  memset(occ, 0, sizeof occ);
  for(int i = 0; i < n; i++) {
    occ[s[i] - '0']++;
  }
  int ans = n;
  for(int i = 0; i <= 9; i++)
    ans = min(ans, n - occ[i]);
  for(int i = 0; i <= 9; i++)
    for(int j = i + 1; j <= 9; j++) {
      string tmp = "";
      for(int k = 0; k < n; k++)
        if(s[k] - '0' == i || s[k] - '0' == j)  {
          tmp += s[k];
        }
      if(!sz(tmp)) continue;
      int len = 1;
      for(int k = 1; k < sz(tmp); k++) {
        if(tmp[k - 1] != tmp[k])
          len++;
      }
      if(len & 1) len--;
      // cout << tmp << " " << len << endl;
      ans = min(ans, n - len);
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
  while(T--)
    solve();
  return 0;
}
