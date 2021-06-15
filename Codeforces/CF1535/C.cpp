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

const int N = 2e5 + 5;

int n;
string s;
int nxt[N], nxt1[N];

void solve() {
  cin >> s;
  n = sz(s);
  nxt1[n] = n;
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == '?') nxt1[i] = nxt1[i + 1];
    else nxt1[i] = i;
  }
  nxt[n] = n;
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == '?') {
      nxt[i] = nxt[i + 1];
    } else if(i + 1 < n && s[i + 1] == '?') {
      if(nxt1[i + 1] >= n) nxt[i] = n;
      else {
        int c = s[nxt1[i + 1]] - '0';
        int need = (s[i] - '0') ^ 1;
        if((nxt1[i + 1] - i - 1) & 1) {
          need ^= 1;
        }
        if(need == c) {
          nxt[i] = nxt[nxt1[i + 1]];
        } else {
          nxt[i] = nxt1[i + 1];
        }
      }
    } else {
      if(s[i] != s[i + 1]) nxt[i] = nxt[i + 1];
      else nxt[i] = i + 1;
    }
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans += nxt[i] - i;
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
