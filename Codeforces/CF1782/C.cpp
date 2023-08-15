// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int A = 26;
const int N = 1e5 + 5;

int n;
string s;
char ans[N], tmp[N];

void Solve() {
  cin >> n >> s;
  vector<vector<int>> pos(A, vector<int>());
  for (int i = 0; i < n; i++) {
    pos[s[i] - 'a'].push_back(i);
  }
  vector<int> ord(A);
  iota(all(ord), 0);
  sort(all(ord), [&](int a, int b) { return sz(pos[a]) > sz(pos[b]); });

  int best = INT_MAX;
  for (int cnt = 1; cnt <= A; cnt++) {
    if (n % cnt != 0) {
      continue;
    }
    for (int i = 0; i < n; i++) {
      tmp[i] = -1;
    }
    int need = n / cnt;
    vector<char> st;
    for (int k = 0; k < cnt; k++) {
      int cur = ord[k];
      if (sz(pos[cur]) >= need) {
        for (int i = 0; i < need; i++) {
          tmp[pos[cur][i]] = char('a' + cur);
        }
      } else {
        for (int i = 0; i < sz(pos[cur]); i++) {
          tmp[pos[cur][i]] = char('a' + cur);
        }
        for (int i = sz(pos[cur]); i < need; i++) {
          st.push_back(char('a' + cur));
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (tmp[i] == -1) {
        tmp[i] = st.back();
        st.pop_back();
      }
    }
    int diff = 0;
    for (int i = 0; i < n; i++) {
      diff += s[i] != tmp[i];
    }
    // cout << diff << endl;
    // for (int i = 0; i < n; i++) {
    //   cout << tmp[i];
    // }
    // cout << endl;
    if (best > diff) {
      best = diff;
      for (int i = 0; i < n; i++) {
        ans[i] = tmp[i];
      }
    }
  }

  cout << best << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i];
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
