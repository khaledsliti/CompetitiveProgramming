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
  string s;
  cin >> s;
  for (int i = 1; i + 1 < sz(s); i++) {
    if (s[i] == 'a') {
      cout << s.substr(0, i) << " " << s[i] << " " << s.substr(i + 1) << endl;
      return;
    }
  }
  cout << s[0] << " " << s.substr(1, sz(s) - 2) << " " << s.back() << endl;
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
