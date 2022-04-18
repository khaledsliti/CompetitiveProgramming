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

const int N = 1e5 + 5;

int n;

int solve(string s, string p) {
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += s[i] != p[i];
  }
  return cnt;
}

void solve() {
  string s, p;
  cin >> n >> s >> p;
  if(s == p) {
    cout << 0 << endl;
    return;
  }

  int a_s = 0, a_p = 0;
  for(int i = 0; i < n; i++) {
    a_s += s[i] == '1';
    a_p += p[i] == '1';
  }
  int b_s = n - a_s;
  int b_p = n - a_p;

  if(a_s != a_p && a_p != b_s + 1) {
    cout << -1 << endl;
    return;
  }

  int ans = 1e9;
  if(a_s == a_p) {
    ans = solve(s, p);
  }

  if(a_p == b_s + 1) {
    for(int i = 0; i < n; i++) {
      if(s[i] == '1' && p[i] == '1') {
        for(int j = 0; j < n; j++) {
          if(i != j) {
            s[j] = (s[j] == '1') ? '0' : '1';
          }
        }
        ans = min(ans, 1 + solve(s, p));
        break;
      }
    }
  }

  if(ans >= 1e9) ans = -1;
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
