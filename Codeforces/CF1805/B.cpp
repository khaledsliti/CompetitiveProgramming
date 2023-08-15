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

void Solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = -1;
  for (int i = 0; i < n; i++) {
    if (m == -1 || s[i] <= s[m]) {
      m = i;
    }
  }
  cout << s[m];
  for(int i = 0; i < n; i++) {
    if (i == m) {
      continue;
    }
    cout << s[i];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
  return 0;
}
